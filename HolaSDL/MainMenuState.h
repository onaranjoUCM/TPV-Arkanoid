#include "GameState.h"
#include "Vector2D.h"
#include "Texture.h"

class MainMenuState : public GameState {
protected:
	
public:
	MainMenuState() {};
	~MainMenuState() { limpiar(); }
	void limpiar();

	void update() {};
	void render() {};
	void handleEvent() {};
};