#include "MainMenuState.h"

MainMenuState::MainMenuState(SDLApplication* app) : GameState(app) {
	cout << "Cargado MainMenuState" << endl;
	Texture* t;
	//playButton = new MenuButton(100, 100, 100, 50, t, asd(app));
};

MainMenuState::~MainMenuState() {

}

void MainMenuState::handleEvents() {

}

void asd(SDLApplication* app) {}