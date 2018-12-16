#include "MenuButton.h"

//MenuButton::MenuButton(Texture* t, int X, int Y, int W, int H/*, SDLApplication* APP*/) :
	//texture(t), x(X), y(Y), w(W), h(H)/*, app(APP)*/ {}

MenuButton::~MenuButton() {}

void MenuButton::render() {
	ArkanoidObject::render();
}

void MenuButton::update() {
/*	Vector2D* pMousePos = TheInputHandler::Instance()
		->getMousePosition();
	if (pMousePos->getX() < (m_position.getX() + m_width)
		&& pMousePos->getX() > m_position.getX()
		&& pMousePos->getY() < (m_position.getY() + m_height)
		&& pMousePos->getY() > m_position.getY())
	{
		m_currentFrame = MOUSE_OVER;
		if (TheInputHandler::Instance()->getMouseButtonState(LEFT))
		{
			m_currentFrame = CLICKED;
		}
	}
	else
	{
		m_currentFrame = MOUSE_OUT;
	}*/
}

void MenuButton::clean()
{
	ArkanoidObject::limpiar();
}

bool MenuButton::HandleEvents(SDL_Event& e){
	bool handled = false;
	while (SDL_PollEvent(&e) && !exit) {
		if (e.type == SDL_MOUSEBUTTONDOWN && e.button.button == SDL_BUTTON_LEFT) {
			SDL_Point p = { e.button.x, e.button.y };
			SDL_Rect r = { x, y, w, h };
			if (SDL_PointInRect(&p, &r)) {
				//cb(app);
				handled = true;
			}
			return handled;
		}
	}
	return handled;
}