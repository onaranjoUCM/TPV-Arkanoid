#ifndef MovingObjectH
#define MovingObjectH

#include "ArkanoidObject.h"
#include "Vector2D.h"
#include "checkML.h"

class SDLAplication;
class MovingObject : public ArkanoidObject {
protected:
	Vector2D vel;
public:
	MovingObject() {}
	MovingObject(int x, int y, int w, int h, Vector2D v, Texture* t) :
		ArkanoidObject(x, y, w, h, t) {
		vel = v;
	}
	virtual ~MovingObject() {}

	virtual void update() = 0;
	virtual bool handleEvent(SDL_Event& e) = 0;

	void loadFromFile(ifstream& file, SDLApplication* game);
	void saveToFile(ofstream& outfile);

	Vector2D getVel();
	void setVel(Vector2D newVel);
};

#endif