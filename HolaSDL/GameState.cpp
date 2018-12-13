#include "GameState.h"

void GameState::render(){}
void GameState::update(){
	for (list<GameObject*>::iterator it = objects.begin(); it != objects.end();) {
		((*it++))->update();
	}
}
bool GameState::handleEvents(SDL_Event& e){
	/*
	auto it = stage.begin();
	while (it != stage.end() && !handled) {
		if ((*it)->handleEvent(e)) {
			handled = true;
		}
		else {
			++it;
		}
	}
	*/
	return true;
}