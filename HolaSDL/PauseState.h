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
	SDL_Rect pauseImag;
	Texture* texture;
public:
	PauseState(SDLApplication* app);
	~PauseState();

	static void playButtonClicked(SDLApplication* app);
	static void menuButtonClicked(SDLApplication* app);

	void render();
};

#endif