#include "Grass.h"

Grass::Grass(World* worldref, int x, int y) :
	Plant(worldref, x, y)
{
	this->sign = 'g';
}


Grass::~Grass()
{
}

Organism * Grass::reproduction(int x, int y) {
	return new Grass(this->world, x, y);
}

Grass::Grass(World* worldRef, int x, int y, int power, int age) : Plant(worldRef, x, y, power, age)
{
	this->sign = 'g';
}