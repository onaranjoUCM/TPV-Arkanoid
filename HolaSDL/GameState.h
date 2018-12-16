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

	//metodos de la hoja de teoria
	virtual bool onEnter() = 0;
	virtual bool onExit() = 0;
	//virtual std::string getStateID() const { return s_menuID; }

private:
	//static const std::string s_menuID;
};
#endif