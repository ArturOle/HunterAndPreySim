#include "Main.h"


Main::Main()
{
	window = new Window;
	window->Loop();
}


Main::~Main()
{
	delete(window);
};


int main()
{
	_CrtSetDbgFlag( _CRTDBG_ALLOC_MEM_DF | _CRTDBG_LEAK_CHECK_DF);
	Main* run = new Main;
	delete(run);
}











/*
Simulation of possible behavior of some animals.

Blue dots - the pray, devides into two after eating food ( yellow dot )
Red dots - the hunter, multiplies after eating blue dot. Red dot will sterve after x sec without eating.

blue dots wins when acchive y multiple of red dots.
red dots win when all blue dot will be eaten

For ths experiment we will use reinforced learnig for both parties.		

*/