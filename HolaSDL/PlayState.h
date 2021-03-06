#ifndef PlayStateH;
#define PlayStateH

#include "GameState.h"
#include "ArkanoidObject.h"
#include "BlocksMap.h"
#include "Wall.h"
#include "Paddle.h"
#include "Ball.h"
#include "Reward.h"
#include "checkML.h"
#include <list>

class PlayState : public GameState {
protected:
	Wall* sideWallLeft = nullptr;
	Wall* sideWallRight = nullptr;
	Wall* upperWall = nullptr;
	BlocksMap* blocksMap = nullptr;
	Paddle* paddle = nullptr;
	Ball* ball = nullptr;
	Reward* firstReward = nullptr;
	
	bool gameOver = false;
	bool win = false;
	int vidas = 3;
	int nivelActual = 0;
	Vector2D ballSpeed = Vector2D(2, -2);
	string niveles[3] = { "..\\maps\\level01.ark", "..\\maps\\level02.ark", "..\\maps\\level03.ark" };
public:
	PlayState(SDLApplication* app);
	PlayState(SDLApplication* app, string filename);

	bool handleEvents(SDL_Event& e);

	bool collides(const SDL_Rect* rect, const Vector2D* vel, Vector2D& collVector);
	void update();
	void pierdeVida();
	void nextLevel();
	void loadList();
	void createReward(int x, int y);
	void ganaVida();
	void deleteReward(Reward* r);
	void saveGame();
	string getNivelActual();
};

#endif