#ifndef MainMenuStateH;
#define MainMenuStateH

#include "GameState.h"
//#include "MenuButton.h"
#include "checkML.h"
#include <iostream>

class MainMenuState : public GameState {
protected:
	//MenuButton* playButton;
public:
	MainMenuState();
	~MainMenuState();
};

#endif