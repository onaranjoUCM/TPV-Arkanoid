#include "PlayState.h"
#include "SDLApplication.h"
#include "checkML.h"
#include <fstream>

using namespace std;

const std::string PlayState::sPlayID = "PLAY";

void PlayState::limpiar() {}

void PlayState::update() {}

void PlayState::render() {}

void PlayState::handleEvent() {
	/*
	if () { // Pulsado escape
		app->getStateMachine();
		pushState(new PauseState);
	}
	else {
		// Llamar al handleEvents de todos los objetos que lo necesiten
		GameState::handleEvent(e);
	}
	*/
}

bool PlayState::onEnter() {
	std::cout << "entering PlayState\n";
	return true;
}

bool PlayState::onExit() {
	std::cout << "exiting PlayState\n";
	return true;
}
