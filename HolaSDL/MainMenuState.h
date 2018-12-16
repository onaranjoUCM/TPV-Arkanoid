#ifndef MainMenuStateH;
#define MainMenuStateH

#include "GameState.h"
#include "checkML.h"
#include <iostream>

class MainMenuState : public GameState {
protected:
	
public:
	MainMenuState();
	~MainMenuState();

	void handleEvents();
};

#endif