#include "GameStateMachine.h"

GameStateMachine::GameStateMachine() {
	
}

GameStateMachine::~GameStateMachine() { }

void GameStateMachine::updateCurrentState() {
	currentState = stack.top();
	cout << "Cargado " << currentState << endl;
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