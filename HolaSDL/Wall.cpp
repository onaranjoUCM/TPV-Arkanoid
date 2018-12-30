#include "Wall.h"
#include "checkML.h"

using namespace std;

// Devuelve si un objeto ha entrado en contacto con �l y en qu� direcci�n debe rebotar
bool Wall::collides(const SDL_Rect* rect, Vector2D& collVector) {
	if (SDL_HasIntersection(rect, &getRect())) {
		if (wallPosition == "left") { collVector = Vector2D(1, 0); }
		if (wallPosition == "right") { collVector = Vector2D(-1, 0); }
		if (wallPosition == "top") { collVector = Vector2D(0, -1); }
		return true;
	} else {
		return false;
	}
}