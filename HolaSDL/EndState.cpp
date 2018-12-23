#include "EndState.h"
#include "SDLApplication.h"

EndState::EndState(SDLApplication* app) : GameState(app) {
	playButton = new MenuButton(10, 500, 100, 50, app->getTexture(0), app, playButtonClicked);
	stage.push_back(playButton);
	menuButton = new MenuButton(500, 500, 100, 50, app->getTexture(5), app, playButtonClicked);
	stage.push_back(menuButton);
}

EndState::~EndState(){
	delete playButton;
	delete menuButton;
};

void EndState::playButtonClicked(SDLApplication* app) {
	app->getStateMachine()->changeState(new PlayState(app));
}

void EndState::menuButtonClicked(SDLApplication* app) {
	app->getStateMachine()->changeState(new MainMenuState(app));
}

void EndState::update() {
	GameState::update();
}

void EndState::render() {
	GameState::render();
}

void EndState::handleEvent() {

}