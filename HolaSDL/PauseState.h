#ifndef PauseStateH;
#define PauseStateH

#include "GameState.h"
#include "MenuButton.h"
#include "checkML.h"
#include <iostream>

class PauseState : public GameState {
protected:

public:
	PauseState(SDLApplication* app);
	~PauseState();

	void update();
	void render();
	void handleEvent();
};

#endif