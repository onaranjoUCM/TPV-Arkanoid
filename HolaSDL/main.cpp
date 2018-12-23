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

// TAREAS
// Implementar destructores correctamente
// Eliminar update y handleEvents vacios de todos los objetos que hereden de ArkanoidObject
// Sustituir referencias a Game.h por PlayState.h o SDLApplication.h (actualmente comentadas)
// Sustituir los void handleEvents de los objetos por bool handleEvent que se ajusten al virtual de GameObject