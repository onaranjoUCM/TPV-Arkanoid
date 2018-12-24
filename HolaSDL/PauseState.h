#ifndef PauseStateH;
#define PauseStateH

#include "GameState.h"
#include "PlayState.h"
#include "MenuButton.h"
#include "checkML.h"
#include <iostream>

class PauseState : public GameState {
protected:
	MenuButton* playButton;
	MenuButton* menuButton;
public:
	PauseState(SDLApplication* app);

	static void playButtonClicked(SDLApplication* app);
	static void menuButtonClicked(SDLApplication* app);

	void render();
};

#endif