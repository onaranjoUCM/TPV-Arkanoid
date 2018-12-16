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
}

void GameStateMachine::popState()
{
	if (!stack.empty())
	{
		delete stack.top();
		stack.pop();
		currentState = stack.top();
	}
}

void GameStateMachine::changeState(GameState *pState)
{
	popState();
	pushState(pState);
	currentState = stack.top();
}

void GameStateMachine::update() {
}

void GameStateMachine::render() {
}

void GameStateMachine::handleEvents() {
	/*
	while (event) {
		if (event.type == SDL_QUIT) exit = true;
		else
			stateMachine.CurrentState->handleEvents(event);
	}
	*/
}