#include "Animals.h"

void Animal::multiply(int x, int y) {}
void Animal::action(char ch) {

	lastMove = rand() % 4;

	switch (lastMove) {
	case 0:
		if (this->y<this->world->getHeight() - 1)
			this->y++;
		break;
	case 1:
		if (this->y>0)
			this->y--;
		break;
	case 2:
		if (this->x<this->world->getWidth() - 1)
			this->x++;
		break;
	case 3:
		if (this->x>0)
			this->x--;
		break;
	}

}
bool Animal::collision(Organism* other) {

	if (other->ifReflectedAtack(this))
	{
		return true;
	}
	if (this->power > other->getPower())
	{
		std::string log = "";
		log += (char)this->getSign();
		log += " vs ";
		log += (char)other->getSign();
		log += " Won: ";
		log += (char)this->getSign();
		log += "\n";
		world->addToLog(log);
		this->world->deleteOrganism(other);
		return true;
	}
	else
	{
		if (this->power < other->getPower())
		{

			std::string log = "";
			log += (char)this->getSign();
			log += " vs ";
			log += (char)other->getSign();
			log += " Won: ";
			log += (char)other->getSign();
			log += "\n";
			world->addToLog(log);

			this->world->deleteOrganism(this);
			return false;
		}
		else if (this->power == other->getPower() && this->initiative > other->getInitiative())
		{
			std::string log = "";
			log += (char)this->getSign();
			log += " vs ";
			log += (char)other->getSign();
			log += " Won: ";
			log += (char)this->getSign();
			log += "\n";;

			this->world->deleteOrganism(other);
			return true;
		}
		else if (this->power == other->getPower() && this->initiative < other->getInitiative())
		{
			std::string log = "";
			log += (char)this->getSign();
			log += " vs ";
			log += (char)other->getSign();
			log += " Won: ";
			log += (char)other->getSign();
			log += "\n";
			return false;
		}
		else if (this->getSign() == other->getSign()) {

			this->recoverPosition();
			if (this->y < this->world->getHeight() - 1 && world->getOrganismByLocation(x, y + 1) == NULL)
			{
				world->addOrganism(this->reproduction(x, y + 1));
				std::string log = "Multiplication" + this->getSign();
				log += "\n";
				world->addToLog(log);
			}
			if (this->y > 0 && world->getOrganismByLocation(x, y - 1) == NULL)
			{

				world->addOrganism(this->reproduction(x, y - 1));
				std::string log = "Multiplication" + this->getSign();
				log += "\n";
				world->addToLog(log);
			}
			else
				if (this->x < this->world->getWidth() - 1 && world->getOrganismByLocation(x + 1, y) == NULL)
				{
					world->addOrganism(this->reproduction(x + 1, y));
					std::string log = "Multiplication" + this->getSign();
					log += "\n";
					world->addToLog(log);
				}
				else
					if (this->x > 0 && world->getOrganismByLocation(x - 1, y) == NULL)
					{
						world->addOrganism(this->reproduction(x - 1, y));
						std::string log = "Multiplication" + this->getSign();
						log += "\n";
						world->addToLog(log);
					}
		}
	}


	return true;
}

Animal::Animal(World* worldRef, int x, int y) :
	Organism(worldRef, x, y)
{

}
Animal::~Animal()
{

}

Animal::Animal(World* worldRef, int x, int y, int power, int age) : Organism(worldRef, x, y, power, age)
{

}