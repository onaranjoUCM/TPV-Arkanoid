#include "PauseState.h"
#include "SDLApplication.h"

PauseState::PauseState(SDLApplication* app) : GameState(app) {
	playButton = new MenuButton(10, 500, 100, 50, app->getTexture(app->playText), app, playButtonClicked);
	menuButton = new MenuButton(500, 500, 100, 50, app->getTexture(app->menuText), app, menuButtonClicked);
	stage.push_back(playButton);
	stage.push_back(menuButton);
};

PauseState::~PauseState(){
	delete playButton;
	delete menuButton;
	delete texture;
}

void PauseState::playButtonClicked(SDLApplication* app) {
	app->getStateMachine()->popState();
}

void PauseState::menuButtonClicked(SDLApplication* app) {
	app->getStateMachine()->changeState(new MainMenuState(app));
}

void PauseState::render() {
	pauseImag.x = 100;
	pauseImag.y = 100;
	pauseImag.h = 200;
	pauseImag.w = 200;
	texture = app->getTexture(8);
}