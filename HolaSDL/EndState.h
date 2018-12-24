#ifndef EndStateH;
#define EndStateH

#include "GameState.h"
#include "MenuButton.h"
#include "checkML.h"
#include <iostream>

class EndState : public GameState {
protected:
	MenuButton* playButton;
	MenuButton* menuButton;
public:
	EndState(SDLApplication* app);
	~EndState();

	static void playButtonClicked(SDLApplication* app);
	static void menuButtonClicked(SDLApplication* app);

	void update();
	void render();
	void handleEvent();
};

#endif