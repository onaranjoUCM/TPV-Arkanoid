#include "GameStateMachine.h"
#include "SDL_image.h"
#include "Texture.h"
#include <iostream>

using uint = unsigned int;

class SDLApplication {
protected:
	SDL_Window* window = nullptr;
	SDL_Renderer* renderer = nullptr;
	const uint winWidth = 800;
	const uint winHeight = 600;

	bool exit = false;
	Texture* textures[6];	// Cambiar inmediato?
	GameStateMachine* stateMachine = nullptr;
	enum GameState { menu, play, end, pause };

public:
	SDLApplication();
	~SDLApplication();

	void run();
	void render();
	void handleEvents();

	GameStateMachine* getStateMachine();
};