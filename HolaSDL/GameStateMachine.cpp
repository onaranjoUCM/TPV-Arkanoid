#include "GameStateMachine.h"
#include <iostream>

GameStateMachine::GameStateMachine() {}

GameStateMachine::~GameStateMachine() {
	currentState = nullptr;
	while (!stack.empty())
	{
		delete stack.top();
		stack.pop();
	}
}

// Actualiza la variable del estado actual
void GameStateMachine::updateCurrentState() {
	if (!stack.empty())
	{
		currentState = stack.top();
	}
}

GameState* GameStateMachine::getCurrentState() {
	return currentState;
}

// Añade un estado a la pila
void GameStateMachine::pushState(GameState *pState)
{
	stack.push(pState);
	updateCurrentState();
}

// Elimina el estado actual de la pila
void GameStateMachine::popState()
{
	if (!stack.empty())
	{
		delete stack.top();
		stack.pop();
		updateCurrentState();
	}
}

// Elimina el estado actual y añade uno nuevo
void GameStateMachine::changeState(GameState *pState)
{
	popState();
	pushState(pState);
	updateCurrentState();
}