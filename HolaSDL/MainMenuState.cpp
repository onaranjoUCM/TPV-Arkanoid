#include "MainMenuState.h"

void limpiar(){}

void MainMenuState::update() { }

void MainMenuState::render() { }

void MainMenuState::handleEvents() {}

bool MainMenuState::onEnter()
{
	std::cout << "entering MenuState\n";
	return true;
}

bool MainMenuState::onExit()
{
	std::cout << "exiting MenuState\n";
	return true;
}