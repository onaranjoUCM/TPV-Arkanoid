#pragma once

#include "ArkanoidError.h"
#include <SDL.h>

class FileNotFoundError : public ArkanoidError {
	FileNotFoundError(const string &stringLine) : ArkanoidError("The file " + stringLine + " was not found") {}
};
