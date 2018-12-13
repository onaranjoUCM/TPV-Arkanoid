#include "GameState.h"
#include "GameState.h"
#include "PlayState.h"
//#include "MainMenuState.h"
//#include "PauseState.h"
//#include "EndState.h"
#include "stack"

class GameStateMachine {
	protected:
		GameState* currentState = nullptr;
		stack<GameState*> stack; // Como pone el enunciado
		//list<GameState*> machineGameStates; //como lo haria yo
		//std::vector<GameState*> machineGameStates; // como recomienda el libro ese

		PlayState* playState = nullptr;
	public:
		GameStateMachine();
		~GameStateMachine();

		GameState* getCurrentState();
		void pushState(GameState* pState);
		void changeState(GameState* pState);
		void popState();
};

/*class GameStateMachine
{
private:
	Stack << GameState * >> stack;
public:
	GameStateMachine();
	~GameStateMachine();

	GameStates currentState() { return ...(? ); }
	void popState() {
		if (stack.empty()) {
			delete stack.top();
			stack.pop();
		}
	}
	void changeStates(GameState s) {
		popState();
		pushState(s);
	}
	void handleEvents() {
		while (event) {
			if (event.type == SDL_QUIT) exit = true;
			else
				stateMachine.CurrentState->handleEvents(event);
		}
	}
};*/
