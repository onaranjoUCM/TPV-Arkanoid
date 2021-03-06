#ifndef MainMenuStateH;
#define MainMenuStateH

#include "GameState.h"
#include "PlayState.h"
#include "EndState.h"
#include "MenuButton.h"
#include "checkML.h"
#include <iostream>

class MainMenuState : public GameState {
protected:
	MenuButton* playButton;
	MenuButton* loadButton;
	MenuButton* quitButton;
public:
	MainMenuState(SDLApplication* app);

	void render();

	static void playButtonClicked(SDLApplication* app);
	static void quitButtonClicked(SDLApplication* app);
	static void loadButtonClicked(SDLApplication* app);
};

#endif