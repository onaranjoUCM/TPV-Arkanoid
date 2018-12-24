#include "GameStateMachine.h"
#include "MainMenuState.h"
#include "SDL_image.h"
#include "Texture.h"
#include <iostream>

const int WIN_WIDTH = 800;
const int WIN_HEIGHT = 600;
const int NUM_TEXTURES = 14;
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
		menuText,
		gameOverText,
		inMenuText,
		titleText
	};

protected:
	SDL_Window* window = nullptr;
	SDL_Renderer* renderer = nullptr;

	Texture* textures[NUM_TEXTURES];
	const string textureNames[NUM_TEXTURES] = {
		"..\\images\\bricks.png", //0
		"..\\images\\rewards.png", //1
		"..\\images\\side.png", //2
		"..\\images\\topside.png", //3
		"..\\images\\paddle.png", //4
		"..\\images\\ball.png", //5
		"..\\images\\play.png", //6
		"..\\images\\quit.png", //7
		"..\\images\\pause.png", //8
		"..\\images\\load.png", //9
		"..\\images\\menu.png", //10
		"..\\images\\gameOver.png", //11
		"..\\images\\menu.png", //12
		"..\\images\\title.png" //13
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