#pragma once
#include "Animals.h"
class Turtle :
	public Animal
{
public:
	Turtle(World* worldref, int x, int y);
	~Turtle();
	void action(char ch);
	bool ifReflectedAtack(Organism* other);//bool czyOdbilAtak
	Organism * reproduction(int x, int y);
	Turtle(World* worldRef, int x, int y, int power, int age);
};
