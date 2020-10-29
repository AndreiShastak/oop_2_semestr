#pragma once
#include "Plant.h"
class Grass :
	public Plant
{
public:
	Grass(World* worldref, int x, int y);
	~Grass();
	Organism * reproduction(int x, int y);
	Grass(World* worldRef, int x, int y, int power, int age);

};
