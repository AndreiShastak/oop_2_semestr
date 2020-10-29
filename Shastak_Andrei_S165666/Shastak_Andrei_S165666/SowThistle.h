#pragma once
#include "Plant.h"
class SowThistle :
	public Plant
{
public:
	SowThistle(World* worldref, int x, int y);
	~SowThistle();
	void action(char ch);
	Organism * reproduction(int x, int y);
	SowThistle(World* worldRef, int x, int y, int power, int age);
};