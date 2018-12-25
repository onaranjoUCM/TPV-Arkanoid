#pragma once
#include <exception>
#include <stdexcept>
using namespace std;

class ArkanoidError : public logic_error {
public:
	ArkanoidError(const string &stringLine) : logic_error("Error: " + stringLine) {}
};

