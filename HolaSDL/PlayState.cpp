#include "PlayState.h"
#include "PauseState.h"
#include "EndState.h"
#include "SDLApplication.h"
#include <time.h> 
#include <fstream> 

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

PlayState::PlayState(SDLApplication* app, string filename) : GameState(app) {
	ifstream file(filename);
	if (file.fail()) {
		cout << "Error cargando el archivo " << filename << endl;
		//throw "Error loading blocks map from " + filename;
	} else {
		float x, y, w, h, vx, vy, color;

		file >> vidas;
		file >> nivelActual;

		file >> x >> y >> w >> h;
		blocksMap = new BlocksMap(w, h, app->getTexture(app->blocksText));
		blocksMap->load(niveles[nivelActual]);
		for (int r = 0; r < blocksMap->getRows(); r++) {
			for (int c = 0; c < blocksMap->getCols(); c++) {
				file >> color;
				Block* block = blocksMap->getCells()[r][c];
				if (block != nullptr) {
					block->setColor(color);
					if (color == 0) {
						blocksMap->ballHitsBlock(block);
					}
				}
			}
		}

		file >> vx >> vy >> x >> y >> w >> h;
		paddle = new Paddle(x, y, w, h, app->getTexture(app->paddleText));
		file >> vx >> vy >> x >> y >> w >> h;
		ball = new Ball(x, y, w, h, Vector2D(vx, vy), app->getTexture(app->ballText), this);
		file >> x >> y >> w >> h;
		sideWallLeft = new Wall("left", x, y, w, h, app->getTexture(app->sideWallText));
		file >> x >> y >> w >> h;
		sideWallRight = new Wall("right", x, y, w, h, app->getTexture(app->sideWallText));
		file >> x >> y >> w >> h;
		upperWall = new Wall("top", x, y, w, h, app->getTexture(app->upperWallText));
		loadList();
		srand(time(NULL));

		file.close();
	}
}

void PlayState::update() {
	if (win == false && gameOver == false) {
		GameState::update();
	}

	if (vidas == 0 && !gameOver) {
		cout << "Has perdido!" << endl;
		app->getStateMachine()->changeState(new EndState(app));
		gameOver = true;
	}
}

bool PlayState::handleEvents(SDL_Event& e) {
	if (e.type == SDL_KEYDOWN && (e.key.keysym.sym == SDLK_ESCAPE || e.key.keysym.sym == SDLK_s)) {
		if (e.key.keysym.sym == SDLK_ESCAPE) {
			app->getStateMachine()->pushState(new PauseState(app));
		}
		if (e.key.keysym.sym == SDLK_s) {
			saveGame();
		}
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
		//delete blocksMap;
		ball->setPos(Vector2D(WIN_WIDTH / 2 - app->getTexture(app->ballText)->getW() / 10, WIN_HEIGHT - 100));
		ball->setVel(ballSpeed);
		nivelActual++;
		//blocksMap = new BlocksMap(WIN_WIDTH - 200, WIN_HEIGHT / 2, app->getTexture(app->blocksText));
		blocksMap->load(niveles[nivelActual]);
	}
	else {
		win = true;
		app->getStateMachine()->changeState(new EndState(app));
		cout << "Has ganado!";
	}
}

void PlayState::createReward(int x, int y) {
	int random = rand() % 4;
	list<GameObject*>::iterator it = --stage.end();
	Reward* r = new Reward(x, y, 50, 20, random, Vector2D(0, 2), app->getTexture(app->rewardText), paddle, this, it);
	stage.push_back(r);
}

void PlayState::ganaVida() {
	vidas++;
	cout << "Vidas: " << vidas << endl;
}

void PlayState::deleteReward(Reward* r) {
	stage.erase(++r->getIndvector());
}

void PlayState::saveGame() {
	app->setExit(true);
	cout << "Escribe el nombre del fichero donde guardar la partida:" << endl;
	string filename;
	cin >> filename;
	filename = "..\\savedGames\\" + filename + ".txt";

	ofstream outfile(filename, ofstream::trunc);
	outfile << vidas << " ";
	outfile << nivelActual << endl;
	for (auto object : stage)
	{
		ArkanoidObject* a = static_cast<ArkanoidObject*>(object);
		a->saveToFile(outfile);
	}
	outfile.close();
}

string PlayState::getNivelActual() {
	return niveles[nivelActual];
}

void PlayState::pierdeVida() {
	vidas--;
	cout << "Vidas: " << vidas << endl;
}