#include "SDL_image.h"
#include "Texture.h"
#include "GameStateMachine.h"

// ESTO ES AHORA EL EQUIVALENTE A GAME
using uint = unsigned int;

class SDLApplication {
protected:
	SDL_Window* window = nullptr;
	SDL_Renderer* renderer = nullptr;
	const uint winWidth = 800;
	const uint winHeight = 600;

	bool exit = false;
	Texture* textures[6];	// Cambiar inmediato

	enum GameState { menu, play, end, pause };
	GameStateMachine* stateMachine = nullptr;
public:
	SDLApplication();
	~SDLApplication();

	void run();
	void render();
	void handleEvents();

	GameStateMachine* getStateMachine();
};