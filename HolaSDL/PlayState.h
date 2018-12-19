#ifndef PlayStateH;
#define PlayStateH

#include "GameState.h"
#include "PauseState.h"
#include "MenuButton.h"
#include "checkML.h"
#include <iostream>

class PlayState : public GameState {
protected:
	
public:
	PlayState(SDLApplication* app);
	~PlayState();

	void render();	// Temporal
	bool handleEvents(SDL_Event& e);
};

#endif