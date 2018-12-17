#include "PlayState.h"
#include "checkML.h"

PlayState::~PlayState() {

}

void PlayState::update() {
	GameState::update();
}

void PlayState::render() {
	GameState::render();
}

void PlayState::handleEvent() {
	SDL_Event e;
	while (SDL_PollEvent(&e) && !exit) {
		if (e.type == SDL_KEYDOWN && e.key.keysym.sym == SDLK_ESCAPE) {
			//app->getStateMachine()->pushState(new PauseState);
		}
		else {
			GameState::handleEvents(e);
		}
	}
}