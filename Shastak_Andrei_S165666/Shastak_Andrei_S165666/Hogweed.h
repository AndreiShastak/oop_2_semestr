#pragma once
#include "Plant.h"
class Hogweed :
	public Plant
{
public:
	Hogweed(World* worldRef, int x, int y);
	~Hogweed();
	void action(char ch);

	bool ifReflectedAtack(Organism* other);
	Organism * reproduction(int x, int y);
	Hogweed(World* worldRef, int x, int y, int power, int age);

};