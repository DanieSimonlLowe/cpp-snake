#ifndef INPUT_H_INCLUDED
#define INPUT_H_INCLUDED
#include <windows.h>
#include "consonants.hpp"

DWORD WINAPI inputThread(void *input);
#include "input.cpp"
#endif // INPUT_H_INCLUDED
