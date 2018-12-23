#include "PauseState.h"
#include "SDLApplication.h"

PauseState::PauseState(SDLApplication* app) : GameState(app) {
	playButton = new MenuButton(10, 500, 100, 50, app->getTexture(0), app, playButtonClicked);
	menuButton = new MenuButton(500, 500, 100, 50, app->getTexture(5), app, menuButtonClicked);
	stage.push_back(playButton);
	stage.push_back(menuButton);
};

PauseState::~PauseState(){
	delete playButton;
	delete menuButton;
}

void PauseState::playButtonClicked(SDLApplication* app) {
	app->getStateMachine()->popState();
}

void PauseState::menuButtonClicked(SDLApplication* app) {
	app->getStateMachine()->changeState(new MainMenuState(app));
}