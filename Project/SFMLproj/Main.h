#pragma once

#define _CRTDBG_MAP_ALLOC
#include <stdlib.h>
#include <crtdbg.h>
#include "Window.h"

class Main
{
	Window* window;

public:
	Main();
	~Main();
};

