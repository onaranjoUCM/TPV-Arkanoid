#include "GameState.h"
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

		void updateCurrentState();
		GameState* getCurrentState();
		void pushState(GameState* pState);
		void changeState(GameState* pState);
		void popState();
};