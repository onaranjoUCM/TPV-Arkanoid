#include "GameStateMachine.h"

void GameStateMachine::pushState(GameState *pState)
{
	/*
	stack.push_back(pState);
	stack.back()->onEnter();
	*/
}

void GameStateMachine::popState()
{
	/*
	if (!stack.empty())
	{
		if (stack.back()->onExit())
		{
			delete stack.back();
			stack.pop_back();
		}
	}
	*/
}

void GameStateMachine::changeState(GameState *pState)
{
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