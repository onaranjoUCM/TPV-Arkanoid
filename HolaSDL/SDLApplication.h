#include "GameStateMachine.h"
#include "SDL_image.h"
#include "Texture.h"
#include <iostream>

class SDLApplication {
protected:
	SDL_Window* window = nullptr;
	SDL_Renderer* renderer = nullptr;
	const int winWidth = 800;
	const int winHeight = 600;

	bool exit = false;
	Texture* textures[6];	// Cambiar inmediato?
	GameStateMachine* stateMachine = nullptr;
	enum enumStates { menu, play, end, pause };

public:
	SDLApplication();
	~SDLApplication();

	void run();
	void render();
	void handleEvents();

	GameStateMachine* getStateMachine();
	Texture* getTextures(int i);
};