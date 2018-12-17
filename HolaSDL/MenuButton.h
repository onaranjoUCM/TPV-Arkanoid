#ifndef MenuButtonH
#define MenuButtonH

#include "GameObject.h"
#include "Texture.h"

using CallBackOnClick = void(SDLApplication* app);

class MenuButton : public GameObject {
	protected:
		CallBackOnClick* cb;
		SDLApplication* app;
		int x, y, w, h;
		Texture* texture;
	public:
		MenuButton() {}
		MenuButton(int x, int y, int w, int h, Texture* texture, void (*callback)(SDLApplication* app));
		~MenuButton();

		void render();
		void update() {};
		void handleEvents() {};
		bool handleEvent(SDL_Event& e);
};
#endif