#include "Main.h"


Main::Main()
{
	window = new Window;
	window->Loop();
}


Main::~Main()
{
	delete(window);
}


int main()
{
	Main* run = new Main;
	delete(run);
	_CrtSetDbgFlag(_CRTDBG_ALLOC_MEM_DF | _CRTDBG_LEAK_CHECK_DF);
}

/*
Simulation of possible behavior of some animals.

Green dots - the pray, devides into two after eating food ( yellow dot )
Red dots - the hunter, multiplies after eating blue dot. Red dot will sterve after x sec without eating.

green dots wins when achive y multiple of red dots.
red dots win when all green dot will be eaten	
*/