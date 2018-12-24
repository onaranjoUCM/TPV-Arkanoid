#include "EndState.h"
#include "SDLApplication.h"

EndState::EndState(SDLApplication* app) : GameState(app) {
	playButton = new MenuButton(100, 400, 100, 50, app->getTexture(app->playText), app, playButtonClicked);
	stage.push_back(playButton);
	menuButton = new MenuButton(100, 500, 100, 50, app->getTexture(app->menuText), app, playButtonClicked);
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
	playButton->render();
	menuButton->render();

	// para la imagen gameOver;
	SDL_Rect gameOverImag;
	gameOverImag.x = 300;
	gameOverImag.y = 50;
	gameOverImag.h = 200;
	gameOverImag.h = 200;
	Texture* texture = app->getTexture(app->gameOverText);
	texture->render(gameOverImag);
}

void EndState::handleEvent() {

}