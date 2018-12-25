#pragma once

#include "ArkanoidError.h"
#include <SDL.h>

class FileFormatError : public ArkanoidError {
	FileFormatError(const string &stringLine) : ArkanoidError("Error in the file format: " + stringLine) {}
};