#ifndef MainMenuStateH;
#define MainMenuStateH

#include "GameState.h"
#include "MenuButton.h"
#include "checkML.h"
#include <iostream>

using CallBackOnClick = void(SDLApplication* app);

class MainMenuState : public GameState {
protected:
	MenuButton* playButton;
public:
	MainMenuState(SDLApplication* app);
	~MainMenuState();

	void render();
	void handleEvent(SDL_Event e);	// Quitar
	static void playButtonClicked(SDLApplication* app);
};

#endif