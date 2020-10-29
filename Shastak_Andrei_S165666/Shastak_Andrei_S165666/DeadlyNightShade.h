#pragma once
#include "Plant.h"
class DeadlyNightshade :
	public Plant
{
public:
	DeadlyNightshade(World* worldRef, int x, int y);
	DeadlyNightshade(World* worldRef, int x, int y, int power, int age);
	~DeadlyNightshade();
	bool ifReflectedAtack(Organism* other);
	Organism * reproduction(int x, int y);
};