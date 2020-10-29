#include "Wolf.h"


Wolf::Wolf(World* worldref, int x, int y) :
	Animal(worldref, x, y)
{
	this->power = 9;
	this->initiative = 5;
	this->sign = 'W';
}


Wolf::~Wolf()
{
}

bool Wolf::Action()
{
	return true;
}

bool Wolf::specialCollision(Organism* other)
{
	return true;
}

Organism * Wolf::reproduction(int x, int y) {
	return new Wolf(this->world, x, y);
}

Wolf::Wolf(World* worldRef, int x, int y, int power, int age) : Animal(worldRef, x, y, power, age)
{
	this->sign = 'T';
}