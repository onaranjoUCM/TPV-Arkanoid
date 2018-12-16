#include "GameState.h"
#include "MenuButton.h"
#include <iostream>
#include <vector>
//#include "SDLApplication.h"
//#include "MenuButton.h"

class MenuState : public GameState{
protected:
	//std::vector<GameObject*> m_gameObjects;
	//static const std::string sMenuID;
	//Texture* texturaButton = nullptr;
public:
	MenuState();
	~MenuState();
	virtual void update();
	virtual void render();
	virtual void handleEvents();

	//virtual std::string getStateID() const { return sMenuID; }
};

