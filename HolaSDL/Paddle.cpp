#include "Paddle.h"
#include "checkML.h"

using namespace std;

void Paddle::expandW() {
	w = w + (w / 2);
}

void Paddle::reduceW() {
	w = w - (w / 2);
}

void Paddle::resetW() {
	w = wIni;
}

void Paddle::update() {
	if (pos.getX() > 25 - speed && pos.getX() < 800 - w - speed - 25) {	// ELIMINAR VALORES ESTATICOS
		pos = Vector2D(pos.getX() + speed, pos.getY());
	}
}

Vector2D Paddle::ballCollisionVector(const SDL_Rect* ballRect) {
	Vector2D collVector;
	int ballCenter = ballRect->x + (ballRect->w / 2);
	int espacio = w / 6;
	
	if (ballCenter > pos.getX() && ballCenter < pos.getX() + espacio * 1) {
		collVector = Vector2D(2, 10);
	}

	if (ballCenter > pos.getX() + (espacio * 1) && ballCenter < pos.getX() + espacio * 2) {
		collVector = Vector2D(1, 10);
	}
	
	if (ballCenter > pos.getX() + (espacio * 2) && ballCenter < pos.getX() + espacio * 3) {
		collVector = Vector2D(0, 10);
	}

	if (ballCenter > pos.getX() + (espacio * 3) && ballCenter < pos.getX() + espacio * 4) {
		collVector = Vector2D(0, 10);
	}

	if (ballCenter > pos.getX() + (espacio * 4) && ballCenter < pos.getX() + espacio * 5) {
		collVector = Vector2D(-1, 10);
	}

	if (ballCenter > pos.getX() + (espacio * 5) && ballCenter < pos.getX() + espacio * 6) {
		collVector = Vector2D(-2, 10);
	}
	
	collVector.normalize();
	return collVector;
}

// Recibe y administra los eventos de teclado
bool Paddle::handleEvent(SDL_Event& e) {
	bool handled = false;
	if (e.type == SDL_KEYDOWN) {
		switch (e.key.keysym.sym)
		{
		case SDLK_LEFT:
			speed = -3;
			handled = true;
			break;
		case SDLK_RIGHT:
			speed = 3;
			handled = true;
			break;
		}
	}

	if (e.type == SDL_KEYUP) {
		switch (e.key.keysym.sym)
		{
		case SDLK_LEFT:
			speed = 0;
			handled = true;
			break;
		case SDLK_RIGHT:
			speed = 0;
			handled = true;
			break;
		}
	}
	return handled;
}

bool Paddle::collides(const SDL_Rect* rect, Vector2D& collVector) {
	if (SDL_HasIntersection(rect, &getRect())) {
		collVector = ballCollisionVector(rect);
		return true;
	}
	return false;
}