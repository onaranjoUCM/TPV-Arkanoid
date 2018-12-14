#ifndef PlayStateH;
#define PlayStateH

#include "GameState.h"
#include "PauseState.h"
#include "SDLApplication.h"

//class SDLApplication;
class PlayState : public GameState
{
private:
	static const std::string sPlayID;
	//SDLApplication* app = nullptr;
public:
	PlayState();
	~PlayState();

	void update();
	void render();
	void handleEvent();

	//virtual bool onEnter();
	//virtual bool onExit();
	//virtual std::string getStateID() const { return sPlayID; }
};

#endif