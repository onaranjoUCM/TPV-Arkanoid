#include "PauseState.h"
#include "SDLApplication.h"

PauseState::PauseState(SDLApplication* app) : GameState(app) {
	playButton = new MenuButton(350, 400, 100, 50, app->getTexture(app->playText), app, playButtonClicked);
	stage.push_back(playButton);
	menuButton = new MenuButton(350, 500, 100, 50, app->getTexture(app->menuText), app, menuButtonClicked);
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

void PauseState::render() {
	playButton->render();
	menuButton->render();

	// para la imagen de pausado
	SDL_Rect pauseImag;
	pauseImag.x = 200;
	pauseImag.y = 100;
	pauseImag.h = 200;
	pauseImag.w = 400;
	Texture* texture = app->getTexture(app->pauseText);
	texture->render(pauseImag);
}