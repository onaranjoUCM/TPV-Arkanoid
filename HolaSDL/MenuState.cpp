#include "MenuState.h"

MenuState::MenuState() {}

MenuState::~MenuState() {}

void MenuState::update() { 
	for (int i = 0; i < m_gameObjects.size(); i++)
	{
		m_gameObjects[i]->update();
	}
}

void MenuState::render() { 
	for (int i = 0; i < m_gameObjects.size(); i++)
	{
		m_gameObjects[i]->render();
	}
}

void MenuState::handleEvents() {}


bool MenuState::onEnter()
{
	/*if (!TheTextureManager::Instance()->load("assets/button.png",
		"playbutton", TheGame::Instance()->getRenderer()))
	{
		return false;
	}
	if (!TheTextureManager::Instance()->load("assets/exit.png",
		"exitbutton", SDLApplication->getRenderer()))
	{
		return false;
	}*/
	/*ArkanoidObject* button1 = new MenuButton(new ArkanoidObject(100, 100,
		400, 100, "playbutton"));
	ArkanoidObject* button2 = new MenuButton(new ArkanoidObject(100, 300,
		400, 100, "exitbutton"));
	m_gameObjects.push_back(button1);
	m_gameObjects.push_back(button2);
	std::cout << "entering MenuState\n";
	return true;*/
}

bool MenuState::onExit()
{
	/*    for(int i = 0; i < m_gameObjects.size(); i++)
		  {
			m_gameObjects[i]->clean();
		  }
		  m_gameObjects.clear();
		  TheTextureManager::Instance()
		  ->clearFromTextureMap("playbutton");
		  TheTextureManager::Instance()
			->clearFromTextureMap("exitbutton");
		  std::cout << "exiting MenuState\n";
		  return true;*/
}