#include "PauseState.h"

PauseState::PauseState(SDLApplication* app) : GameState(app) {
	
};

void PauseState::update() {
	GameState::update();
}

void PauseState::render() {
	GameState::render();
}

void PauseState::handleEvent() {

}