#include "GameState.h"
#include <iostream>

GameState::GameState(SDLApplication* app) : app(app) {}

GameState::~GameState() {
	for (auto object : stage)
	{
		delete object;
	}
}

void GameState::render() {
	/*
	for (list<GameObject*>::iterator it = stage.begin(); it != stage.end();) {
		((*it++))->render();
	}
	*/
	for (auto object : stage)
	{
		object->render();
	}
}

void GameState::update() {
	for (list<GameObject*>::iterator it = stage.begin(); it != stage.end();) {
		((*it++))->update();
	}
}

bool GameState::handleEvents(SDL_Event& e){
	bool handled = false;
	auto it = stage.begin();
	while (!handled && it != stage.end()) {
		if ((*it)->handleEvent(e)) {
			handled = true;
		} else {
			++it;
		}
	}
	return handled;
}