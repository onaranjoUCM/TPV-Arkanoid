#ifndef PlayStateH;
#define PlayStateH

#include "GameState.h"
#include "Vector2D.h"
#include "Texture.h"

class SDLApplication;
class PlayState : public GameState
{
private:
	static const std::string sPlayID;
public:
	~PlayState() { limpiar(); }
	void limpiar();

	void update();
	void render();
	void handleEvent();

	virtual bool onEnter();
	virtual bool onExit();
	virtual std::string getStateID() const { return sPlayID; }
};

#endif