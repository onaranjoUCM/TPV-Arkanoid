#ifndef GameStateH
#define GameStateH

#include "GameObject.h"
#include "checkML.h"
#include "SDL.h"
#include <list>

using namespace std;

class SDLApplication;
class GameState {
protected:
	list<GameObject*> objects;
	SDLApplication* app;
public:
	GameState(SDLApplication* app) {};
	~GameState() {};
	void update();
	void render();
	virtual bool handleEvents(SDL_Event& e);
};
#endif