#include "GameState.h"
#include <iostream>

GameState::GameState(SDLApplication* app) {

}

GameState::~GameState() {

}

void GameState::render() {
	for (list<GameObject*>::iterator it = objects.begin(); it != objects.end();) {
		((*it++))->render();
	}
}

void GameState::update() {
	for (list<GameObject*>::iterator it = objects.begin(); it != objects.end();) {
		((*it++))->update();
	}
}

bool GameState::handleEvents(SDL_Event& e){
	bool handled = false;
	auto it = objects.begin();
	while (it != objects.end() && !handled) {
		if ((*it)->handleEvent(e)) {
			handled = true;
		} else {
			++it;
		}
	}
	return handled;
}