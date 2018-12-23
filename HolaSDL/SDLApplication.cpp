#include "SDLApplication.h"

SDLApplication::SDLApplication() {
	cout << "Cargado SDLApplication" << endl;
	_CrtSetDbgFlag(_CRTDBG_ALLOC_MEM_DF | _CRTDBG_LEAK_CHECK_DF); // Check Memory Leaks
	SDL_Init(SDL_INIT_EVERYTHING);
	window = SDL_CreateWindow("Arkanoid", SDL_WINDOWPOS_CENTERED,
		SDL_WINDOWPOS_CENTERED, winWidth, winHeight, SDL_WINDOW_SHOWN);
	renderer = SDL_CreateRenderer(window, -1, SDL_RENDERER_ACCELERATED);
	
	textures[0] = new Texture(renderer);
	textures[0]->load("..\\images\\play.png", 1, 1); // 0 para el boton play
	textures[2] = new Texture(renderer);
	textures[2]->load("..\\images\\quit.png", 1, 1); // 2 para el boton quit
	textures[3] = new Texture(renderer);
	textures[3]->load("..\\images\\pause.png", 1, 1); // 3 para el boton pausa
	textures[4] = new Texture(renderer);
	textures[4]->load("..\\images\\load.png", 1, 1); // 4 para el boton load
	textures[5] = new Texture(renderer);
	textures[5]->load("..\\images\\menu.png", 1, 1); // 5 para el boton menu
	textures[1] = new Texture(renderer);
	textures[1]->load("..\\images\\bricks.png", 1, 1);

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
		stateMachine->getCurrentState()->update();
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