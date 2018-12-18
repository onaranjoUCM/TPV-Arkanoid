#include "EndState.h"

EndState::EndState(SDLApplication* app) : GameState(app) {
	
};

void EndState::update() {
	GameState::update();
}

void EndState::render() {
	GameState::render();
}

void EndState::handleEvent() {

}