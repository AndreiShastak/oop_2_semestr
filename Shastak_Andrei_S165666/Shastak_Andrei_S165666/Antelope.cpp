#include "Antelope.h"

Antelope::Antelope(World* worldRef, int x, int y) :
	Animal(worldRef, x, y)
{
	this->power = 4;
	this->initiative = 4;
	this->sign = 'A';
}
Antelope::~Antelope()
{
}

void Antelope::action(char ch)
{
	Animal::action(ch);
	Animal::action(ch);
}

bool Antelope::ifReflectedAtack(Organism* other) {
	if (rand() % 2 == 0)
	{
		other->recoverPosition();
		return true;
	}
	return false;

}

bool Antelope::collision(Organism* other) {
	if (rand() % 2 == 0) {

		return Animal::collision(other);
	}
	else {
		switch (rand() % 4) {
		case 0:
			if (this->y < this->world->getHeight() - 1 && world->getOrganismByLocation(x, y + 1) == NULL)
				this->y++;
			break;
		case 1:
			if (this->y > 0 && world->getOrganismByLocation(x, y - 1) == NULL)
				this->y--;
			break;
		case 2:
			if (this->x < this->world->getWidth() - 1 && world->getOrganismByLocation(x + 1, y) == NULL)
				this->x++;
			break;
		case 3:
			if (this->x > 0 && world->getOrganismByLocation(x - 1, y) == NULL)
				this->x--;
			break;
		default:
			this->recoverPosition();
			break;
		}
	}
	return true;
}

Organism * Antelope::reproduction(int x, int y) {
	return new Antelope(this->world, x, y);
}

Antelope::Antelope(World* worldRef, int x, int y, int power, int age) : Animal(worldRef, x, y, power, age)
{
	this->sign = 'A';
}