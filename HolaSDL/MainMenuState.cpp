#include "MainMenuState.h"
#include "SDLApplication.h"

MainMenuState::MainMenuState(SDLApplication* app) : GameState(app) {
	playButton = new MenuButton(100, 100, 100, 50, app->getTexture(0), app, playButtonClicked);
	stage.push_back(playButton);
};

MainMenuState::~MainMenuState() {}

void MainMenuState::playButtonClicked(SDLApplication* app) {
	app->getStateMachine()->changeState(new PlayState(app));
}