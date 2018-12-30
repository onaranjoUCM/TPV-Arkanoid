#include "Reward.h"
#include "PlayState.h"
#include "checkML.h"

using namespace std;

Reward::~Reward() {
	paddle = nullptr;
	playState = nullptr;
}

void Reward::update() {
	pos = pos + vel;
	if (SDL_HasIntersection(&getRect(), &paddle->getRect()) && !spent) {
		spent = true;
		doEffect();
	}
	if (getY() > 600) {	// CAMBIAR VALOR INMEDIATO
		playState->deleteReward(this);
	}
}

bool Reward::handleEvent(SDL_Event& e) { return false; }

void Reward::render() {
	if (SDL_GetTicks() > lastAnimationTime + animationSpeed) {
		animationFrame++;
		lastAnimationTime = SDL_GetTicks();
		if (animationFrame == 7) {
			animationFrame = 0;
		}
	}
	renderFrame(rewardType, animationFrame);
}

// Provoca un efecto distinto dependiendo de su tipo
void Reward::doEffect() {
	paddle->resetW();
	switch (rewardType) {
	case 0:
		playState->nextLevel();
		break;
	case 1:
		paddle->expandW();
		break;
	case 2:
		paddle->reduceW();
		break;
	case 3:
		playState->ganaVida();
		break;
	}
	playState->deleteReward(this);
}

list<GameObject*>::iterator Reward::getIndvector() {
	return indVector;
}

void Reward::setIndvector(list<GameObject*>::iterator it) {
	indVector = it;
}