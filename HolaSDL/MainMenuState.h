#ifndef MainMenuStateH;
#define MainMenuStateH

#include "GameState.h"
#include "PlayState.h"
#include "MenuButton.h"
#include "checkML.h"
#include <iostream>

class MainMenuState : public GameState {
protected:
	MenuButton* playButton;
public:
	MainMenuState(SDLApplication* app);
	~MainMenuState();

	static void playButtonClicked(SDLApplication* app);
};

#endif