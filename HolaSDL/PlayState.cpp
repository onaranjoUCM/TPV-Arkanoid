#include "PlayState.h"
#include "SDLApplication.h"

PlayState::PlayState(SDLApplication* app) : GameState(app) {};

PlayState::~PlayState() {}

void PlayState::render() {	// Temporal
	SDL_Rect dstRect;
	dstRect.x = 200;
	dstRect.y = 200;
	dstRect.w = 400;
	dstRect.h = 200;
	Texture* texture = app->getTexture(1);
	texture->render(dstRect, SDL_FLIP_NONE);
}

bool PlayState::handleEvents(SDL_Event& e) {
	if (e.type == SDL_KEYDOWN && e.key.keysym.sym == SDLK_ESCAPE) {
		app->getStateMachine()->pushState(new PauseState(app));
	}
	else {
		GameState::handleEvents(e);
	}
	return true;
}