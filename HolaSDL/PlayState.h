#ifndef PlayStateH;
#define PlayStateH

#include "GameState.h"
#include "PauseState.h"
#include "SDLApplication.h"

class PlayState : public GameState {
protected:
	//static const std::string sPlayID;
	//SDLApplication* app = nullptr;
public:
	PlayState();
	~PlayState();

	void update();
	void render();
	void handleEvent();

	//virtual std::string getStateID() const { return sPlayID; }
};

#endif