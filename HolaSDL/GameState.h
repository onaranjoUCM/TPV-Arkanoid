#ifndef GameStateH
#define GameStateH

#include "GameObject.h"
#include "checkML.h"
#include <list>

using namespace std;

class Game;
class GameState {
protected:
	list<GameObject*> objects;
	Game* game;
public:
	~GameState() {};
	virtual void update();
	virtual void render();
	virtual void handleEvents();
};
#endif