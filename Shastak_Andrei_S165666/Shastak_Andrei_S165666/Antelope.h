#pragma once
#include "Animals.h"

class Antelope :
	public Animal
{
public:
	Antelope(World* worldRef, int x, int y);
	~Antelope();
	void action(char ch);
	bool ifReflectedAtack(Organism* other);
	bool collision(Organism* other);
	Organism * reproduction(int x, int y);
	Antelope(World* worldRef, int x, int y, int power, int age);
};

