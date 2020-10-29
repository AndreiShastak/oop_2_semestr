#include "Human.h"
#include "World.h"
#include <cstdlib>
#include<windows.h>
Human::Human(World* worldRef, int x, int y) :
	Animal(worldRef, x, y)
{
	this->sign = 'H';
	this->power = 5;
	this->initiative = 4;
	this->turn = -10;
}
Human::~Human()
{

}

void Human::action(char ch) {

	if (this->turn >= this->world->getTurn() - 5)
	{
		this->power--;
		std::string log = "Human power:";
		log += std::to_string(this->power);
		log += "\n";
		this->world->addToLog(log);

	}
	if (ch == 'x' && this->turn + 10 <= this->world->getTurn())
	{
		this->power += 5;
		this->turn = this->world->getTurn();

		std::string log = "Human power:";
		log += std::to_string(this->power);
		log += "\n";
		this->world->addToLog(log);
	}

	if (ch == -32)
	{
		ch = _getch();
		switch (ch) {
		case 80:
			if (this->y<this->world->getHeight() - 1)
				this->y++;
			break;
		case 72:
			if (this->y>0)
				this->y--;
			break;
		case 77:
			if (this->x<this->world->getWidth() - 1)
				this->x++;
			break;
		case 75:
			if (this->x>0)
				this->x--;
			break;

		}
	}
}

Organism * Human::reproduction(int x, int y) {
	return new Human(this->world, x, y);
}

Human::Human(World* worldRef, int x, int y, int power, int age) : Animal(worldRef, x, y, power, age)
{
	this->sign = 'H';
}