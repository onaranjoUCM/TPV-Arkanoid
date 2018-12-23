#include "PlayState.h"
#include "PauseState.h"
#include "SDLApplication.h"

PlayState::PlayState(SDLApplication* app) : GameState(app) {
	//blocksMap = new BlocksMap(WIN_WIDTH - 200, WIN_HEIGHT / 2, app->getTexture(app->blocksText));
	//blocksMap->load(niveles[nivelActual]);
	sideWallLeft = new Wall("left", 4, 0, 20, WIN_HEIGHT, app->getTexture(app->sideWallText));
	sideWallRight = new Wall("right", WIN_WIDTH - 24, 0, 20, WIN_HEIGHT, app->getTexture(app->sideWallText));
	upperWall = new Wall("top", 0, 0, WIN_WIDTH, 20, app->getTexture(app->upperWallText));
	paddle = new Paddle(WIN_WIDTH / 2 - app->getTexture(app->paddleText)->getW() / 2, WIN_HEIGHT - (WIN_HEIGHT / 10), app->getTexture(app->paddleText)->getW(), app->getTexture(app->paddleText)->getH(), app->getTexture(app->paddleText));
	ball = new Ball(WIN_WIDTH / 2 - app->getTexture(app->ballText)->getW() / 10, WIN_HEIGHT - 100, app->getTexture(app->ballText)->getW() / 5, app->getTexture(app->ballText)->getH() / 5, ballSpeed, app->getTexture(app->ballText), this);
	loadList();
};

PlayState::~PlayState() {}

bool PlayState::handleEvents(SDL_Event& e) {
	if (e.type == SDL_KEYDOWN && e.key.keysym.sym == SDLK_ESCAPE) {
		app->getStateMachine()->pushState(new PauseState(app));
	}
	else {
		GameState::handleEvents(e);
	}
	return true;
}

void PlayState::loadList() {
	//stage.push_back(blocksMap);
	stage.push_back(paddle);
	stage.push_back(ball);
	stage.push_back(sideWallLeft);
	stage.push_back(sideWallRight);
	stage.push_back(upperWall);
}

// Comprueba si el objeto pasado por parámetro colisiona con otro objeto del juego
bool PlayState::collides(const SDL_Rect* rect, const Vector2D* vel, Vector2D& collVector) {
	//if (blocksMap->checkCollision(rect, vel, collVector, this)) { return true; }
	if (sideWallLeft->collides(rect, collVector)) { return true; }
	if (sideWallRight->collides(rect, collVector)) { return true; }
	if (upperWall->collides(rect, collVector)) { return true; }
	if (paddle->collides(rect, collVector)) { return true; }

	return false;
}

void PlayState::pierdeVida() {
	vidas--;
	cout << "Vidas: " << vidas << endl;
}