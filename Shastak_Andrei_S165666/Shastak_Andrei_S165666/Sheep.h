#pragma once
#include "Animals.h"
class Sheep :
	public Animal
{
public:
	Sheep(World* worldref, int x, int y);
	~Sheep();
	Organism * reproduction(int x, int y);
	Sheep(World* worldRef, int x, int y, int power, int age);
};