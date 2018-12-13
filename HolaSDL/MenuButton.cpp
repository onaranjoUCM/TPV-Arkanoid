#include "MenuButton.h"

bool MenuButton::HandleEvent(SDL_Event& e){
	/*
	if () {	// RATON IZQUIERDO
		SDL_Point p = { e.button.x, e.button.y };
		SDL_Rect r = { x, y, w, h };
		if (SDL_PointInRect()&p, &r) {
			cb(app);
			handled = true;
		}
		return handled;
	}
	*/
	return true;
}

/*
MenuButton::MenuButton(const ArkanoidObject* pParams) :
	ArkanoidObject(buttonX, buttonY, buttonW, buttonH, textura)
{
	mouseCurrentFrame = mouseOut; // start at frame 0
}
void MenuButton::render()
{
	ArkanoidObject::render(); // use the base class drawing
}
void MenuButton::update()
{
	Vector2D* pMousePos = TheInputHandler::Instance()->getMousePosition();
	if (pMousePos->getX() < (pMousePos.getX() + buttonW)
		&& pMousePos->getX() > pMousePos.getX()
		&& pMousePos->getY() < (pMousePos.getY() + buttonH)
		&& pMousePos->getY() > pMousePos.getY())
	{
		mouseCurrentFrame = mouseOver;
		if (TheInputHandler::Instance()->getMouseButtonState(LEFT))
		{
			mouseCurrentFrame = isClick;
		}
	}
	else
	{
		mouseCurrentFrame = mouseOut;
	}
}
*/