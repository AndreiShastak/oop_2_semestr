#include "Sheep.h"


Sheep::Sheep(World* worldref, int x, int y) :
	Animal(worldref, x, y)
{
	this->power = 4;
	this->initiative = 4;
	this->sign = 'S';
}

Sheep::~Sheep()
{
}

Organism * Sheep::reproduction(int x, int y) {
	return new Sheep(this->world, x, y);
}
Sheep::Sheep(World* worldRef, int x, int y, int power, int age) : Animal(worldRef, x, y, power, age)
{
	this->sign = 'S';
}