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
	GameState::~GameState();
}

void MainMenuState::playButtonClicked(SDLApplication* app) {
	app->getStateMachine()->changeState(new PlayState(app));
}

void MainMenuState::loadButtonClicked(SDLApplication* app) {
	string loadCode;
	cout << "Introduzca el codigo del fichero de guardado: " << endl;
	cin >> loadCode;
	loadCode = "..\\savedGames\\" + loadCode + ".txt";
	app->getStateMachine()->changeState(new PlayState(app, loadCode));
}

void MainMenuState::quitButtonClicked(SDLApplication* app) {
	app->setExit(true);
}

void MainMenuState::render() {
	GameState::render();

	// imagen de inicio
	SDL_Rect titleImag;
	titleImag.x = 200;
	titleImag.y = 10;
	titleImag.h = 200;
	titleImag.w = 400;
	Texture* texture = app->getTexture(app->titleText);
	texture->render(titleImag);
}