#include "MenuButton.h"

MenuButton::MenuButton(Texture* t, int X, int Y, int W, int H, SDLApplication* APP) :
	texture(t), x(X), y(Y), w(W), h(H), app(APP) {}

MenuButton::~MenuButton() {}

void MenuButton::render() {
	SDL_Rect dstRect;
	dstRect.x = x;
	dstRect.y = y;
	dstRect.w = w;
	dstRect.h = h;
	texture->render(dstRect, SDL_FLIP_NONE);
}

bool MenuButton::HandleEvents(SDL_Event& e){
	bool handled = false;
	while (SDL_PollEvent(&e) && !exit) {
		if (e.type == SDL_MOUSEBUTTONDOWN && e.button.button == SDL_BUTTON_LEFT) {
			SDL_Point p = { e.button.x, e.button.y };
			SDL_Rect r = { x, y, w, h };
			if (SDL_PointInRect(&p, &r)) {
				cb(app);
				handled = true;
			}
			return handled;
		}
	}
	return handled;
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