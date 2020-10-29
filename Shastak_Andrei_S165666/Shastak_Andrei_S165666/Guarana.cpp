#include "Guarana.h"

Guarana::Guarana(World* worldref, int x, int y) :
	Plant(worldref, x, y)
{
	this->sign = 'u';
}


Guarana::~Guarana()
{
}


bool Guarana::ifReflectedAtack(Organism* other)
{
	other->setPower(other->getPower() + 3);

	return false;
}

Organism * Guarana::reproduction(int x, int y) {
	return new Guarana(this->world, x, y);
}

Guarana::Guarana(World* worldRef, int x, int y, int power, int age) : Plant(worldRef, x, y, power, age)
{
	this->sign = 'u';
}