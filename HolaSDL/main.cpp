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

// Implementar excepciones
// A�adir comentarios a cada funci�n (salvo que sea trivial)
// Cambiar valores inmediatos (Ctrl+F "inmediato" deber�a encontrar la mayor�a) -> Esto que es? xd
// Revisar cadena de update/handleEvent de arkanoidObject, movingObject e hijos
// loadFromFile no esta correctamente implementado aun
// Corregir error cuando hay mas de un reward (tambien ocurre ese error
// al haber un reward del nivel anterior, que hace que el juego muera)