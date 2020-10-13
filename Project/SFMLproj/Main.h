#pragma once

#include <stdlib.h>
#include <crtdbg.h>

#include "Window.h"

#define _CRTDBG_MAP_ALLOC


class Main
{
	Window* window;

public:
	Main();
	~Main();
};


/*The program implements polymorphism.
• The program uses streams.
• The program uses templates (user-defined or STL).
• The program uses exceptions.
• The program correctly manages the memory*/
