#include "EndState.h"
#include "SDLApplication.h"

EndState::EndState(SDLApplication* app) : GameState(app) {
	playButton = new MenuButton(350, 400, 100, 50, app->getTexture(app->playText), app, playButtonClicked);
	stage.push_back(playButton);
	menuButton = new MenuButton(350, 500, 100, 50, app->getTexture(app->menuText), app, menuButtonClicked);
	stage.push_back(menuButton);
}

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
	gameOverImag.x = 200;
	gameOverImag.y = 10;
	gameOverImag.h = 200;
	gameOverImag.w = 400;
	Texture* texture = app->getTexture(app->gameOverText);
	texture->render(gameOverImag);
}