#include "MainMenuState.h"
#include "SDLApplication.h"

MainMenuState::MainMenuState(SDLApplication* app) : GameState(app) {
	playButton = new MenuButton(100, 100, 100, 50, app->getTexture(0), app, playButtonClicked);
	stage.push_back(playButton);
	//loadButton = new MenuButton(100, 200, 100, 50, app->getTexture(4), app, playButtonClicked);
	//stage.push_back(loadButton);
	quitButton = new MenuButton(100, 300, 100, 50, app->getTexture(2), app, quitButtonClicked);
	stage.push_back(quitButton);
};

MainMenuState::~MainMenuState() {
	delete playButton;
	delete loadButton;
	delete quitButton;
}

void MainMenuState::playButtonClicked(SDLApplication* app) {
	app->getStateMachine()->changeState(new PlayState(app));
}

void MainMenuState::quitButtonClicked(SDLApplication* app) {
	app->getStateMachine()->changeState(new EndState(app));
}