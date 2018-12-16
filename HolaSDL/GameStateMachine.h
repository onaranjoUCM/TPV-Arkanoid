#include "GameState.h"
#include "MainMenuState.h"
#include <stack>
#include <vector>

class GameStateMachine {
	protected:
		//NOTA: push(), pop(), etc requieren stack, pero back()
		//requiere vector
		GameState* currentState = nullptr;
		std::vector<GameState*> m_gameStates;
		std::stack<GameState*> stack;
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