#include "MainMenuState.h"
#include "SDLApplication.h"

MainMenuState::MainMenuState(SDLApplication* app) : GameState(app) {
	playButton = new MenuButton(350, 300, 100, 50, app->getTexture(app->playText), app, playButtonClicked);
	stage.push_back(playButton);
	loadButton = new MenuButton(350, 400, 100, 50, app->getTexture(app->loadText), app, loadButtonClicked);
	stage.push_back(loadButton);
	quitButton = new MenuButton(350, 500, 100, 50, app->getTexture(app->quitText), app, quitButtonClicked);
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

void MainMenuState::loadButtonClicked(SDLApplication * app) {

}

void MainMenuState::quitButtonClicked(SDLApplication* app) {
	// REVISAR SI ES CORRECTA LA IMPLEMENTACION
	app->~SDLApplication();
}

void MainMenuState::render() {
	playButton->render();
	loadButton->render();
	quitButton->render();

	// title image
	SDL_Rect titleImag;
	titleImag.x = 200;
	titleImag.y = 10;
	titleImag.h = 200;
	titleImag.w = 400;
	Texture* texture = app->getTexture(app->titleText);
	texture->render(titleImag);
}