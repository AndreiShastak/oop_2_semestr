#include "SowThistle.h"

SowThistle::SowThistle(World* worldref, int x, int y) :
	Plant(worldref, x, y)
{
	this->sign = 's';
}


SowThistle::~SowThistle()
{
}

void SowThistle::action(char ch)
{
	Plant::action(ch);
	Plant::action(ch);
	Plant::action(ch);
}
Organism * SowThistle::reproduction(int x, int y) {
	return new SowThistle(this->world, x, y);
}
SowThistle::SowThistle(World* worldRef, int x, int y, int power, int age) : Plant(worldRef, x, y, power, age)
{
	this->sign = 's';
}