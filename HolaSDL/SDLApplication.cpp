#include "SDLApplication.h"

SDLApplication::SDLApplication() {
	cout << "Cargado SDLApplication" << endl;
	_CrtSetDbgFlag(_CRTDBG_ALLOC_MEM_DF | _CRTDBG_LEAK_CHECK_DF); // Check Memory Leaks
	SDL_Init(SDL_INIT_EVERYTHING);
	window = SDL_CreateWindow("Arkanoid", SDL_WINDOWPOS_CENTERED,
		SDL_WINDOWPOS_CENTERED, winWidth, winHeight, SDL_WINDOW_SHOWN);
	renderer = SDL_CreateRenderer(window, -1, SDL_RENDERER_ACCELERATED);
	
	stateMachine = new GameStateMachine();
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