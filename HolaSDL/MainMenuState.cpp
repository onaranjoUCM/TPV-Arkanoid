#include "MainMenuState.h"
#include "SDLApplication.h"

MainMenuState::MainMenuState(SDLApplication* app) : GameState(app) {
	playButton = new MenuButton(100, 100, 100, 50, app->getTextures(0), playButtonClicked);
	objects.push_back(playButton);
};

MainMenuState::~MainMenuState() {

}

void MainMenuState::render() {
	playButton->render();
}

void MainMenuState::handleEvent(SDL_Event e) {
	cout << "mms" << endl;
	while (SDL_PollEvent(&e) && !exit) {
		playButton->handleEvent(e);
	}
}

void MainMenuState::playButtonClicked(SDLApplication* app) {
	cout << "Boton pulsado" << endl;
	app->getStateMachine()->pushState(new PlayState(app));
}