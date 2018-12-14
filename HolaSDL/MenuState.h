#include "GameState.h"
#include "MenuButton.h"
#include <iostream>

class MenuState : public GameState{
private:
	//static const std::string sMenuID;
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

