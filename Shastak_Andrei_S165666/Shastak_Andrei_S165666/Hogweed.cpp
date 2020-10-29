#include "Hogweed.h"

Hogweed::Hogweed(World* worldRef, int x, int y) :
	Plant(worldRef, x, y)
{
	this->sign = 'h';
	this->power = 10;
}


Hogweed::~Hogweed()
{
}

Organism * Hogweed::reproduction(int x, int y)
{
	return new Hogweed(this->world, x, y);
}

bool Hogweed::ifReflectedAtack(Organism* other)
{
	world->deleteOrganism(other);
	world->deleteOrganism(this);
	return true;
}
void Hogweed::action(char ch)
{
	if (this->y < this->world->getHeight() - 1)
	{
		Organism* tmp = this->world->getOrganismByLocation(this->x, this->y + 1);
		if (tmp != NULL) {
			world->deleteOrganism(tmp);
		}
	}
	if (this->x < this->world->getWidth() - 1)
	{
		Organism* tmp = this->world->getOrganismByLocation(this->x + 1, this->y);
		if (tmp != NULL)
		{
			world->deleteOrganism(tmp);
		}
	}


	if (this->y > 0)
	{

		Organism* tmp = this->world->getOrganismByLocation(this->x, this->y - 1);
		if (tmp != NULL)
		{
			world->deleteOrganism(tmp);
		}
	}

	if (this->x > 0)
	{
		Organism* tmp = this->world->getOrganismByLocation(this->x - 1, this->y);
		if (tmp != NULL)
		{
			world->deleteOrganism(tmp);
		}

	}
}

Hogweed::Hogweed(World* worldRef, int x, int y, int power, int age) : Plant(worldRef, x, y, power, age)
{
	this->sign = 'h';
}