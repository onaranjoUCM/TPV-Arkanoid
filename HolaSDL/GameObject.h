#ifndef GameObjectH
#define GameObjectH

#include "SDL.h"

class SDLApplication;
class GameObject {
protected:
	
public:
	GameObject();
	~GameObject();
	virtual void render() = 0;
	virtual void update() = 0;
	virtual bool handleEvent(SDL_Event& e) = 0;
};

#endif