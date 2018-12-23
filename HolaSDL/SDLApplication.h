#include "GameStateMachine.h"
#include "MainMenuState.h"
#include "SDL_image.h"
#include "Texture.h"
#include <iostream>

const int WIN_WIDTH = 800;
const int WIN_HEIGHT = 600;
const int NUM_TEXTURES = 11;
const int FRAME_RATE = 10;

class SDLApplication {
public:
	const enum textureName {
		blocksText,
		rewardText,
		sideWallText,
		upperWallText,
		paddleText,
		ballText,
		playText,
		quitText,
		pauseText,
		loadText,
		menuText
	};

protected:
	SDL_Window* window = nullptr;
	SDL_Renderer* renderer = nullptr;

	Texture* textures[NUM_TEXTURES];
	const string textureNames[NUM_TEXTURES] = {
		"..\\images\\bricks.png",
		"..\\images\\rewards.png",
		"..\\images\\side.png",
		"..\\images\\topside.png",
		"..\\images\\paddle.png",
		"..\\images\\ball.png",
		"..\\images\\play.png",
		"..\\images\\quit.png",
		"..\\images\\pause.png",
		"..\\images\\load.png",
		"..\\images\\menu.png"
	};

	bool exit = false;
	GameStateMachine* stateMachine;
	//enum enumStates { menu, play, end, pause };

public:
	SDLApplication();
	~SDLApplication();

	void run();
	void render();
	void update();
	void handleEvents();

	GameStateMachine* getStateMachine();
	Texture* getTexture(int i);
};