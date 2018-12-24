#include "PlayState.h"
#include "PauseState.h"
#include "EndState.h"
#include "SDLApplication.h"
#include <time.h> 

PlayState::PlayState(SDLApplication* app) : GameState(app) {
	blocksMap = new BlocksMap(WIN_WIDTH - 200, WIN_HEIGHT / 2, app->getTexture(app->blocksText));
	blocksMap->load(niveles[nivelActual]);
	sideWallLeft = new Wall("left", 4, 0, 20, WIN_HEIGHT, app->getTexture(app->sideWallText));
	sideWallRight = new Wall("right", WIN_WIDTH - 24, 0, 20, WIN_HEIGHT, app->getTexture(app->sideWallText));
	upperWall = new Wall("top", 0, 0, WIN_WIDTH, 20, app->getTexture(app->upperWallText));
	paddle = new Paddle(WIN_WIDTH / 2 - app->getTexture(app->paddleText)->getW() / 2, WIN_HEIGHT - (WIN_HEIGHT / 10), app->getTexture(app->paddleText)->getW(), app->getTexture(app->paddleText)->getH(), app->getTexture(app->paddleText));
	ball = new Ball(WIN_WIDTH / 2 - app->getTexture(app->ballText)->getW() / 10, WIN_HEIGHT - 100, app->getTexture(app->ballText)->getW() / 5, app->getTexture(app->ballText)->getH() / 5, ballSpeed, app->getTexture(app->ballText), this);
	loadList();
	srand(time(NULL));
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
	stage.push_back(blocksMap);
	stage.push_back(paddle);
	stage.push_back(ball);
	stage.push_back(sideWallLeft);
	stage.push_back(sideWallRight);
	stage.push_back(upperWall);
}

// Comprueba si el objeto pasado por parámetro colisiona con otro objeto del juego
bool PlayState::collides(const SDL_Rect* rect, const Vector2D* vel, Vector2D& collVector) {
	if (blocksMap->checkCollision(rect, vel, collVector, this)) { return true; }
	if (sideWallLeft->collides(rect, collVector)) { return true; }
	if (sideWallRight->collides(rect, collVector)) { return true; }
	if (upperWall->collides(rect, collVector)) { return true; }
	if (paddle->collides(rect, collVector)) { return true; }

	return false;
}

void PlayState::nextLevel() {
	if (nivelActual < 2) {
		delete blocksMap;
		ball->setPos(Vector2D(WIN_WIDTH / 2 - app->getTexture(app->ballText)->getW() / 10, WIN_HEIGHT - 100));
		ball->setVel(ballSpeed);
		nivelActual++;
		blocksMap = new BlocksMap(WIN_WIDTH - 200, WIN_HEIGHT / 2, app->getTexture(app->blocksText));
		blocksMap->load(niveles[nivelActual]);
	}
	else {
		win = true;
		cout << "Has ganado!";
	}
}

void PlayState::createReward(int x, int y) {
	int random = rand() % 4;
	list<GameObject*>::iterator it = stage.end();
	Reward* r = new Reward(x, y, 50, 20, rewardTypes[random], Vector2D(0, 2), app->getTexture(app->rewardText), paddle, this, it);
	stage.push_back(r);
	/*
	auto itFR = objects.end();
	if (firstReward == objects.end()) {
		firstReward = itFR;
	}
	*/
}

void PlayState::ganaVida() {
	vidas++;
	cout << "Vidas: " << vidas << endl;
}

void PlayState::deleteReward(Reward* r) {
	// PENDIENTE DE MEJORA
	for (list<GameObject*>::iterator it = stage.begin(); it != stage.end(); ++it) {
		if ((*it) == r) {
			delete r;
			stage.erase(it);
			break;
		}
	}
}

void PlayState::saveGame() {}

string PlayState::getNivelActual() {
	return niveles[nivelActual];
}

void PlayState::pierdeVida() {
	vidas--;
	cout << "Vidas: " << vidas << endl;
}