#pragma once

#include "ArkanoidError.h"
#include <SDL.h>

class FileNotFoundError : public ArkanoidError {
public:
	FileNotFoundError(const string &stringLine) : ArkanoidError("The file " + stringLine + " was not found") {}
};
