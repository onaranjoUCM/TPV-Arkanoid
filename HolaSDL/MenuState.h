#include "GameState.h"
#include "MenuButton.h"
#include <iostream>
#include <vector>
//#include "SDLApplication.h"
//#include "ArkanoidObject.h"
//#include "MenuButton.h"

class MenuState : public GameState{
private:
	std::vector<GameObject*> m_gameObjects;
	static const std::string sMenuID;
	//std::vector<ArkanoidObject*> menuGameObjects;
	//Texture* texturaButton = nullptr;
public:
	MenuState();
	~MenuState();
	virtual void update();
	virtual void render();
	virtual void handleEvents();

	//virtual bool onEnter();
	//virtual bool onExit();
	//virtual std::string getStateID() const { return sMenuID; }
};

