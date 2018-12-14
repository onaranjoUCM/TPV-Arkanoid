#ifndef EndStateH;
#define EndStateH

#include "GameState.h"
#include "checkML.h"
#include <iostream>

class EndState : public GameState {
protected:

public:
	EndState();
	~EndState();

	void update();
	void render();
	void handleEvent();
};

#endif