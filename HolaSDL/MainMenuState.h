#ifndef MainMenuStateH;
#define MainMenuStateH

#include "MenuState.h"
#include "checkML.h"
#include <iostream>

class MainMenuState : public MenuState {
protected:
	
public:
	MainMenuState();
	~MainMenuState();

	bool onExit();
	bool onEnter();
	void handleEvents();
};

#endif