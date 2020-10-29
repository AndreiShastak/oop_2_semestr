#include "DeadlyNightshade.h"

DeadlyNightshade::DeadlyNightshade(World* worldRef, int x, int y) :
	Plant(worldRef, x, y)
{
	this->sign = 'd';
	this->power = 99;
}


DeadlyNightshade::~DeadlyNightshade()
{
}

Organism * DeadlyNightshade::reproduction(int x, int y) {
	return new DeadlyNightshade(this->world, x, y);
}

bool DeadlyNightshade::ifReflectedAtack(Organism* other) {
	std::string log = " Berries " + (char)other->getSign();
	log += "\n";
	world->addToLog(log);
	world->deleteOrganism(other);
	world->deleteOrganism(this);
	return true;
}
DeadlyNightshade::DeadlyNightshade(World* worldRef, int x, int y, int power, int age) : Plant(worldRef, x, y, power, age)
{
	this->sign = 'd';
}