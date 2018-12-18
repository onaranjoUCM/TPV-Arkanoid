#ifndef PlayStateH;
#define PlayStateH

#include "GameState.h"
#include "MenuButton.h"
#include "checkML.h"
#include <iostream>

class PlayState : public GameState {
protected:
	
public:
	PlayState(SDLApplication* app);
	~PlayState();

	void update();
	void render();
	void handleEvent();
};

#endif