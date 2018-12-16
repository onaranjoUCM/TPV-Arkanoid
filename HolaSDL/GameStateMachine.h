#include "GameState.h"
#include "MainMenuState.h"
#include <stack>
#include <vector>

using namespace std;

class GameStateMachine {
	protected:
		GameState* currentState = nullptr;
		stack<GameState*> stack;
	public:
		GameStateMachine();
		~GameStateMachine();

		GameState* getCurrentState();
		void pushState(GameState* pState);
		void changeState(GameState* pState);
		void popState();

		void update();
		void render();
		void handleEvents();
};