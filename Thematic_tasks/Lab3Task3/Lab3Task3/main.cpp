#include "ZOO.h"
#include "Animal.h"
#include <crtdbg.h>

#define _CRTDBG_MAP_ALLOC

int main()
{
	ZOO zoo(2);
	std::cout << zoo.censos.size() << std::endl;

	for (Animal* x : zoo.censos)
	{
		Axolotl* axol = dynamic_cast<Axolotl*>(x);
		if (axol != NULL) 
		{
			axol->Eat();
			axol->Swim();
		}
		else 
		{
			std::cout << "I'm not axoltl!" << std::endl;
			RedPanda* redp = dynamic_cast<RedPanda*>(x);
			if (redp != NULL)
			{
				redp->Eat();
				redp->Jump();
			}
			else
			{
				std::cout << "I'm not red panda!" << std::endl;
				Glonk* glonk = dynamic_cast<Glonk*>(x);
				if (glonk != NULL)
				{
					glonk->Eat();
					glonk->Nothing();
					glonk->Dies();

				}
				else 
				{
					std::cout << "I'm not glonk!" << std::endl;
				}
			}
		}
		delete x;
	}
	//zoo.censos.at(0)->Eat();
	_CrtSetDbgFlag(_CRTDBG_ALLOC_MEM_DF | _CRTDBG_LEAK_CHECK_DF);
}