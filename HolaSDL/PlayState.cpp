#include "PlayState.h"
#include "SDLApplication.h"

PlayState::PlayState(SDLApplication* app) : GameState(app) {
	
};

PlayState::~PlayState() {

}

bool PlayState::handleEvents(SDL_Event& e) {
	if (e.type == SDL_KEYDOWN && e.key.keysym.sym == SDLK_ESCAPE) {
		cout << app;
		//app->getStateMachine()->pushState(new PauseState(app));
	}
	else {
		GameState::handleEvents(e);
	}
	return true;
}