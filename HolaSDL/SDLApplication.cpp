#include "SDLApplication.h"

SDLApplication::SDLApplication() {
	// INITIALIZE SDL
	_CrtSetDbgFlag(_CRTDBG_ALLOC_MEM_DF | _CRTDBG_LEAK_CHECK_DF); // Check Memory Leaks
	SDL_Init(SDL_INIT_EVERYTHING);
	window = SDL_CreateWindow("Arkanoid", SDL_WINDOWPOS_CENTERED,
		SDL_WINDOWPOS_CENTERED, WIN_WIDTH, WIN_HEIGHT, SDL_WINDOW_SHOWN);
	renderer = SDL_CreateRenderer(window, -1, SDL_RENDERER_ACCELERATED);
	
	// TEXTURES
	textures[blocksText] = new Texture(renderer);
	textures[blocksText]->load(textureNames[blocksText], 2, 3);
	textures[rewardText] = new Texture(renderer);
	textures[rewardText]->load(textureNames[rewardText], 10, 8);
	for (int i = 2; i < NUM_TEXTURES; i++) {
		textures[i] = new Texture(renderer);
		textures[i]->load(textureNames[i], 1, 1);
	}

	// STATES MACHINE
	stateMachine = new GameStateMachine();
	stateMachine->pushState(new MainMenuState(this));
}

SDLApplication::~SDLApplication() {
	SDL_DestroyRenderer(renderer);
	SDL_DestroyWindow(window);

	SDL_Window* window = nullptr;
	SDL_Renderer* renderer = nullptr;
	GameStateMachine* gsm = nullptr;

	SDL_Quit();
};

void SDLApplication::run() {
	while (!exit) {
		render();
		handleEvents();
		update();
	}
}

void SDLApplication::render() {
	if (window == nullptr || renderer == nullptr)
		cout << "Error cargando SDL" << endl;
	else {
		SDL_RenderClear(renderer);
		stateMachine->getCurrentState()->render();
		SDL_RenderPresent(renderer);
	}
}

void SDLApplication::update() {
	stateMachine->getCurrentState()->update();
	int startTime = SDL_GetTicks();
	int frameTime = SDL_GetTicks() - startTime;
	if (frameTime < FRAME_RATE) {
		SDL_Delay(FRAME_RATE - frameTime);
	}
}

void SDLApplication::handleEvents() {
	SDL_Event e;
	while (SDL_PollEvent(&e) && !exit) {
		if (e.type == SDL_QUIT) {
			exit = true;
		} else {
			stateMachine->getCurrentState()->handleEvents(e);
		}
	}
}

GameStateMachine* SDLApplication::getStateMachine() {
	return stateMachine;
}

Texture* SDLApplication::getTexture(int i) {
	return textures[i];
}

void SDLApplication::setExit(bool e) {
	exit = e;
}