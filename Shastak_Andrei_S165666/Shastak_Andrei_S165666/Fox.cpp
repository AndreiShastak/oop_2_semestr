#include "Fox.h"

Fox::Fox(World* worldRef, int x, int y) :
	Animal(worldRef, x, y)
{
	this->power = 3;
	this->initiative = 7;
	this->sign = 'F';
}

Fox::~Fox()
{
}

void Fox::action(char ch)
{
	
	Animal::action(ch);

	Organism * tmp = this->world->getOrganismByLocation(this->x, this->y);
	if (tmp != NULL)
	{
		if (tmp->getPower() > this->power)
		{
			this->recoverPosition();

			/*if (ch > 6)
			this->action(6);
			else if(ch > 0)
			this->action(ch--);*/
		}
	}

}

Organism * Fox::reproduction(int x, int y) {
	return new Fox(this->world, x, y);
}
Fox::Fox(World* worldRef, int x, int y, int power, int age) : Animal(worldRef, x, y, power, age)
{
	this->sign = 'F';
}