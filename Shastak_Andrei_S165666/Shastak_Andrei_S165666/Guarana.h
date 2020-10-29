#pragma once
#include "Plant.h"
class Guarana :
	public Plant
{
public:
	Guarana(World* worldref, int x, int y);
	~Guarana();
	Organism * reproduction(int x, int y) override;
	bool ifReflectedAtack(Organism* other);
	Guarana(World* worldRef, int x, int y, int power, int age);

};
