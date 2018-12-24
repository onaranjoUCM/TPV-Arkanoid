#ifndef RewardH
#define RewardH

#include "MovingObject.h"
#include "Paddle.h"
#include "Vector2D.h"
#include "Texture.h"
#include <list>

class PlayState;
class Reward : public MovingObject {
private:
	int rewardType;
	Paddle* paddle;
	bool spent = false;
	PlayState* playState;
	list<GameObject*>::iterator indVector;	// NUEVO

	int animationSpeed = 200;
	int animationFrame = 0;
	int lastAnimationTime;
public:
	Reward() {}
	Reward(int x, int y, int w, int h, int rt, Vector2D v, Texture* t, Paddle* p, PlayState* ps, list<GameObject*>::iterator i) :
		MovingObject(x, y, w, h, v, t) {
		rewardType = rt;
		paddle = p;
		playState = ps;
		lastAnimationTime = SDL_GetTicks();
		indVector = i;
	}
	~Reward();

	void render();
	void update();
	bool handleEvent(SDL_Event& e);
	void doEffect();
};

#endif