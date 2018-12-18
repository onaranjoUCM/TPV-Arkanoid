#ifndef EndStateH;
#define EndStateH

#include "GameState.h"
#include "MenuButton.h"
#include "checkML.h"
#include <iostream>

class EndState : public GameState {
protected:

public:
	EndState(SDLApplication* app);
	~EndState();

	void update();
	void render();
	void handleEvent();
};

#endif