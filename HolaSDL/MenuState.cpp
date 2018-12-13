#include "MenuState.h"

void limpiar(){}

void MenuState::update() { }

void MenuState::render() { }

void MenuState::handleEvents() {}

bool MenuState::onEnter()
{
	std::cout << "entering MenuState\n";
	return true;
}

bool MenuState::onExit()
{
	std::cout << "exiting MenuState\n";
	return true;
}