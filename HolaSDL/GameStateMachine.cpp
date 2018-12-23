#include "GameStateMachine.h"
#include <iostream>

GameStateMachine::GameStateMachine() {}

GameStateMachine::~GameStateMachine() {}

void GameStateMachine::updateCurrentState() {
	if (!stack.empty())
	{
		currentState = stack.top();
		cout << "Cargado estado: " << currentState << endl;
	}
}

GameState* GameStateMachine::getCurrentState() {
	return currentState;
}

void GameStateMachine::pushState(GameState *pState)
{
	stack.push(pState);
	updateCurrentState();
}

void GameStateMachine::popState()
{
	if (!stack.empty())
	{
		delete stack.top();
		stack.pop();
		updateCurrentState();
	}
}

void GameStateMachine::changeState(GameState *pState)
{
	popState();
	pushState(pState);
	updateCurrentState();
}