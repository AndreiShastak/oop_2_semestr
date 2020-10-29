#pragma once
#include "Animals.h"

class Human :
	public Animal
{
private:
	int turn;
public:
	Human(World* worldRef, int x, int y);
	~Human();
	void action(char ch);
	Organism * reproduction(int x, int y);
	Human(World* worldRef, int x, int y, int power, int age);
};


