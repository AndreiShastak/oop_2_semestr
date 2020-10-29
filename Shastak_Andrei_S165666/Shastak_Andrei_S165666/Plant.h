#pragma once
#include "Organisms.h"
class Plant :
	public Organism
{
public:
	Plant(World* worldref, int x, int y);

	~Plant();

	void multiply(int x, int y);
	void action(char ch);
	bool collision(Organism* other);
	bool ifReflectedAtack(Organism* other) { return false; };
	virtual Organism * reproduction(int x, int y) = 0;
	Plant(World* worldRef, int x, int y, int power, int age);
};
