#pragma once
#include "Animals.h"
class Wolf :
	public Animal
{
public:
	Wolf(World* world, int x, int y);
	~Wolf();
	bool specialCollision(Organism*);
	bool Action();
	Organism * reproduction(int x, int y);
	Wolf(World* worldRef, int x, int y, int power, int age);
};