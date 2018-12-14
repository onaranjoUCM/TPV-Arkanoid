#ifndef PauseStateH;
#define PauseStateH

#include "GameState.h"
#include "checkML.h"
#include <iostream>

class PauseState : public GameState {
protected:

public:
	PauseState();
	~PauseState();

	void update();
	void render();
	void handleEvent();
};

#endif