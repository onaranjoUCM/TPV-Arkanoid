#ifndef BallH
#define BallH

#include "Texture.h"
#include "Vector2D.h"
#include "MovingObject.h"
#include "checkML.h"

class PlayState;
class Ball : public MovingObject{
private:
	Vector2D posIni;
	Vector2D velIni;
	PlayState* playState;
public:
	Ball() {}
	Ball(int x, int y, int w, int h, Vector2D v, Texture* t, PlayState* g) :
		MovingObject(x, y, w, h, v, t) {
		playState = g;
		posIni = Vector2D(x, y);
		velIni = v;
	}
	~Ball();

	void update();
	bool handleEvent(SDL_Event& e) { return false; };
};

#endif