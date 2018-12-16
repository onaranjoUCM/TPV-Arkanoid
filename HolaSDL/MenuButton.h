#ifndef MenuButtonH
#define MenuButtonH

#include "GameObject.h"
#include "Texture.h"
#include "ArkanoidObject.h"
//#include "SDLApplication.h"
//using CallBackOnClick = void(SDLApplication* app);

class ArkanoidObject;
class MenuButton : public ArkanoidObject {
	protected:
		int x, y, w, h;
		//CallBackOnClick* cb;
		//SDLApplication* app;
		Texture* texture;
	public:
		MenuButton() {}
		MenuButton(int x, int y, int w, int h, Texture* texture) : 
			ArkanoidObject(x, y, w, h, texture)
		{
			m_currentFrame = MOUSE_OUT; // start at frame 0
		}
		//MenuButton(Texture* t, int X, int Y, int W, int H/*, SDLApplication* APP*/);
		~MenuButton();

		void render();
		bool HandleEvents(SDL_Event& e);

		//metodos de la teoria
		//virtual void render(); //de draw() a render()
		virtual void update();
		virtual void clean();
	private:
		enum button_state
		{
			MOUSE_OUT = 0,
			MOUSE_OVER = 1,
			CLICKED = 2
		};
		button_state m_currentFrame;
};
#endif