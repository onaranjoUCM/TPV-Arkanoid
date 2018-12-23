#include "Ball.h"
#include "PlayState.h"
#include "checkML.h"

using namespace std;

void Ball::limpiar() {
	playState = nullptr;
}

// Actualiza la posición de la bola según su velocidad y si ha chocado con algo
void Ball::update() {
	Vector2D prevPos = pos;
	Vector2D vel = getVel();

	setPos(pos + getVel());

	Vector2D collVector;
	if (playState->collides(&getRect(), &vel, collVector)) {
		vel = vel - (collVector * (2 * (vel * collVector)));
		setVel(vel);
		setPos(prevPos + getVel());
	}

	if (pos.getY() > 600 + 100) {	// Cambiar valor inmediato o mover bloque a playState
		pos = posIni;
		setVel(velIni);
		playState->pierdeVida();
	}
}