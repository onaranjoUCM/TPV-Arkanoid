#include "MainMenuState.h"
#include "SDLApplication.h"

MainMenuState::MainMenuState(SDLApplication* app) : GameState(app) {
	playButton = new MenuButton(100, 100, 100, 50, app->getTextures(0), app, playButtonClicked);
	objects.push_back(playButton);
};

MainMenuState::~MainMenuState() {}

void MainMenuState::playButtonClicked(SDLApplication* app) {
	app->getStateMachine()->pushState(new PlayState(app));
}