#include "GameObject.h"
#include "SDLApplication.h"
#include "Vector2D.h"
#include "Texture.h"

using CallBackOnClick = void(SDLApplication* app);
class MenuButton : public GameObject
{
protected:
	CallBackOnClick* cb;
	//enum buttonState {mouseOut = 0, mouseOver = 1, isClick = 1};
	//Texture* textura;
	//buttonState mouseCurrentFrame;
public:
	MenuButton();
	~MenuButton() { limpiar(); }
	void render();
	void update();
	void limpiar();
	bool HandleEvent(SDL_Event& e);
};