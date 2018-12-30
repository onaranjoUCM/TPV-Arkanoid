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

// Implementar excepciones
	//creo que eso ya esta
// Cambiar valores inmediatos (Ctrl+F "inmediato" debería encontrar la mayoría)
	//Esto que es?
		//Por ejemplo, donde pone 800 en lugar de WIN_WIDTH (normalmente porque no tiene acceso a él, lo que hay que hacer es dárselo de la forma adecuada)
// Revisar cadena de herencias de update/handleEvent de arkanoidObject, movingObject e hijos
// loadFromFile no esta correctamente implementado aun