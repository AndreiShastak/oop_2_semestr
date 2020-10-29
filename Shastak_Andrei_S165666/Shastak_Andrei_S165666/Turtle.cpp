#include "Turtle.h"

Turtle::Turtle(World* worldref, int x, int y) :
	Animal(worldref, x, y)
{
	this->power = 2;
	this->initiative = 1;
	this->sign = 'T';
}


Turtle::~Turtle()
{
}

void Turtle::action(char ch)
{
	if (rand() % 4 == 0) {
		Animal::action(ch);
	}
}


bool Turtle::ifReflectedAtack(Organism* other) {
	if (other->getPower() < 5)
	{
		other->recoverPosition();
		return true;
	}
	return false;

}

Organism * Turtle::reproduction(int x, int y) {
	return new Turtle(this->world, x, y);
}

Turtle::Turtle(World* worldRef, int x, int y, int power, int age) : Animal(worldRef, x, y, power, age)
{
	this->sign = 'T';
}