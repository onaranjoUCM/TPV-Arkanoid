#include "SDL_image.h"
#include "checkML.h"
#include "SDLApplication.h"
#include <iostream>

using namespace std;

using uint = unsigned int;

int main(int argc, char* argv[]){
	SDLApplication app = SDLApplication();
	app.run();
	return 0;
}

// TAREAS (Apunta aqu� si necesitas que se haga algo o si quieres preguntar algo)

// Implementar destructores correctamente
// Implementar excepciones
=======
// Mejorar men�s
// Eliminar update y handleEvents vacios de todos los objetos que hereden de ArkanoidObject
// Sustituir referencias a Game.h por PlayState.h o SDLApplication.h (actualmente comentadas)
// Sustituir los void handleEvents de los objetos por bool handleEvent que se ajusten al virtual de GameObject
// A�adir comentarios a cada funci�n (salvo que sea trivial)
// GameState::render() puede que de error al pasar de nivel
// Cambiar valores inmediatos (Ctrl+F "inmediato" deber�a encontrar la mayor�a)
// Revisar cadena de update/handleEvent de arkanoidObject, movingObject e hijos
>>>>>>> d6af75ebeaa9b2d475a8d2293c429a88d13a7d5f
