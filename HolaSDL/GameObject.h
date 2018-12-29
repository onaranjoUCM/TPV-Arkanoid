#ifndef GameObjectH
#define GameObjectH

#include "SDL.h"
#include "checkML.h"

class SDLApplication;
class GameObject {
protected:
	
public:
	GameObject();
	virtual ~GameObject();
	virtual void render() = 0;
	virtual void update() = 0;
	virtual bool handleEvent(SDL_Event& e) = 0;
};

#endif