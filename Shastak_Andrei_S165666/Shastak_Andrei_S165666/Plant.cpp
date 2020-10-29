#include "Plant.h"
Plant::Plant(World* worldRef, int x, int y) :
	Organism(worldRef, x, y)
{
	this->initiative = 0;
	this->power = 0;
}


Plant::~Plant()
{
}


void Plant::multiply(int x, int y) {}
void Plant::action(char ch) {
	if (rand() % 20 == 1)
	{
		if (this->y < this->world->getHeight() - 1 && world->getOrganismByLocation(x, y + 1) == NULL)
		{
			world->addOrganism(this->reproduction(x, y + 1));
			std::string log = "Multiplication ";
			log += (char) this->getSign();
			log += "\n";
			world->addToLog(log);

		}
		if (this->y > 0 && world->getOrganismByLocation(x, y - 1) == NULL)
		{

			world->addOrganism(this->reproduction(x, y - 1));
			std::string log = "Multiplication ";
			log += (char) this->getSign();
			log += "\n";
			world->addToLog(log);
		}
		else
			if (this->x < this->world->getWidth() - 1 && world->getOrganismByLocation(x + 1, y) == NULL)
			{
				world->addOrganism(this->reproduction(x + 1, y));
				std::string log = "Multiplication ";
				log += (char) this->getSign();
				log += "\n";
				world->addToLog(log);
			}
			else if (this->x > 0 && world->getOrganismByLocation(x - 1, y) == NULL)
			{
				world->addOrganism(this->reproduction(x - 1, y));
				std::string log = "Multiplication ";
				log += (char) this->getSign();
				log += "\n";
				world->addToLog(log);
			}
	}
}

bool Plant::collision(Organism* other) {
	return true;
}
Plant::Plant(World* worldRef, int x, int y, int power, int age) : Organism(worldRef, x, y, power, age)
{

}


