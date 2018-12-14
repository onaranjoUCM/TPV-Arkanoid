#include "GameObject.h"
#include "SDLApplication.h"

using CallBackOnClick = void(SDLApplication* app);
class MenuButton : public GameObject {
	protected:
		int x, y, w, h;
		CallBackOnClick* cb;
		SDLApplication* app;
		Texture* texture;

		//enum buttonState {mouseOut = 0, mouseOver = 1, isClick = 1};
		//buttonState mouseCurrentFrame;
	public:
		MenuButton(Texture* t, int X, int Y, int W, int H, SDLApplication* APP);

		~MenuButton();

		void render();
		bool HandleEvents(SDL_Event& e);
};