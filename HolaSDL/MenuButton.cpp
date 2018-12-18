#include "MenuButton.h"
#include <iostream>

MenuButton::MenuButton(int X, int Y, int W, int H, Texture* t, void (*callback)(SDLApplication* app)) :
	texture(t), x(X), y(Y), w(W), h(H), cb(callback) {}

MenuButton::~MenuButton() {}

void MenuButton::render() {
	SDL_Rect dstRect;
	dstRect.x = x;
	dstRect.y = y;
	dstRect.w = w;
	dstRect.h = h;
	texture->render(dstRect, SDL_FLIP_NONE);
}

bool MenuButton::handleEvent(SDL_Event& e){
	cout << "evento recogido";
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