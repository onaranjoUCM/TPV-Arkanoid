#include "GameStateMachine.h"

GameStateMachine::GameStateMachine() {
	pushState(new MainMenuState());
}

GameStateMachine::~GameStateMachine() { }

GameState* GameStateMachine::getCurrentState() {
	return currentState;
}

void GameStateMachine::pushState(GameState *pState)
{
	stack.push(pState);
	currentState = stack.top();
	//stack.back()->onEnter();
}

void GameStateMachine::popState()
{
	if (!stack.empty())
	{
		delete stack.top();
		stack.pop();
		
		// ESTO NO SE DE DONDE SALE
		/*
		if (stack.back()->onExit())
		{
			delete stack.back();
			stack.pop_back();
		}*/
	}
}

void GameStateMachine::changeState(GameState *pState)
{
	popState();
	pushState(pState);

	// ESTO NO SE DE DONDE SALE
	/*
	if (!stack.empty())
	{
		if (stack.back()->getStateID() == pState->getStateID())
		{
			return; // do nothing
		}
		if (stack.back()->onExit())
		{
			delete stack.back();
			stack.pop_back();
		}
	}
	// push back our new state
	stack.push_back(pState);
	// initialise it
	stack.back()->onEnter();
	*/
}