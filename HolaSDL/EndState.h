#ifndef EndStateH;
#define EndStateH

#include "GameState.h"
#include "checkML.h"
#include <iostream>

class EndState : public GameState {
protected:

public:
	EndState(SDLApplication* app) : GameState(app) {}
	~EndState();

	void update();
	void render();
	void handleEvent();
};

#endif