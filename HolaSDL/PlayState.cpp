#include "PlayState.h"
#include "checkML.h"

//const std::string PlayState::sPlayID = "PLAY";

PlayState::PlayState() {

}

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

/*
bool PlayState::onEnter() {
	std::cout << "entering PlayState\n";
	return true;
}

bool PlayState::onExit() {
	std::cout << "exiting PlayState\n";
	return true;
}
*/