#include "MainMenuState.h"

MainMenuState::MainMenuState() {
	cout << "Cargado MainMenuState" << endl;
}

MainMenuState::~MainMenuState() {

}

bool MainMenuState::onExit() { return true; }
bool MainMenuState::onEnter() { return true; }

void MainMenuState::handleEvents() {
	
}