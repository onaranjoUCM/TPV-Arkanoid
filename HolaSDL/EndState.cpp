#include "EndState.h"

EndState::EndState() {
	cout << "Cargado EndState" << endl;
}

EndState::~EndState() {

}

void EndState::update() {
	GameState::update();
}

void EndState::render() {
	GameState::render();
}

void EndState::handleEvent() {

}