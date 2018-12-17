#ifndef GameObjectH
#define GameObjectH

class SDLApplication;
class GameObject {
protected:
	
public:
	GameObject();
	~GameObject();
	virtual void render() = 0;
	virtual void update() = 0;
	virtual void handleEvents() = 0;
};

#endif