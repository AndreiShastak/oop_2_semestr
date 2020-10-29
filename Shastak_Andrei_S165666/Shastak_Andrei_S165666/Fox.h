#pragma once
#include "Animals.h"
class Fox :
	public Animal
{
public:
	Fox(World* worldRef, int x, int y);
	Fox(World* worldRef, int x, int y, int power, int age);

	~Fox();

	void action(char ch) override;
	Organism * reproduction(int x, int y);
};

