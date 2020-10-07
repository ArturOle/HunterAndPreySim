#include "Main.h"
#include <SFML/Window.hpp>
#include <SFML/Graphics.hpp>

using namespace sf;

Main::Main()
{
	RenderWindow window{ VideoMode{800, 600}, "Hello World" };
	window.setFramerateLimit(60);

	while (true)
	{
		window.clear(Color::Black);
		window.display();
	}

};

int main()
{

}
/*
Simulation of possible behavior of some animals.

Blue dots - the pray, devides into two after eating food ( yellow dot )
Red dots - the hunter, multiplies after eating blue dot. Red dot will sterve after x sec without eating.

blue dots wins when acchive y multiple of red dots.
red dots win when all blue dot will be eaten

For ths experiment we will use reinforced learnig for both parties.		




*/