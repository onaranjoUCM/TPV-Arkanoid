#ifndef GameStateH
#define GameStateH

#include "GameObject.h"
#include "checkML.h"
#include "SDL.h"
#include <list>

using namespace std;

class GameState {
protected:
	list<GameObject*> objects;
public:
	~GameState() {};
	virtual void update();
	virtual void render();
	virtual bool handleEvents(SDL_Event& e);
};
#endif