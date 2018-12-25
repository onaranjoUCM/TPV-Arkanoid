#pragma once

#include "ArkanoidError.h"
#include "SDLError.h"

class SDLError : public ArkanoidError {
	public:
		SDLError(const string &stringLine) : ArkanoidError("SDL " + stringLine + " was not found") {}
};
