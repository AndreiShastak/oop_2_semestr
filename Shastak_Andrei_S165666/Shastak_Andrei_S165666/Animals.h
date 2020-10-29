#pragma once
#include "Organisms.h"
#include <stdlib.h>   
#include <time.h>

class Animal :public Organism {
public:
	Animal(World* worldRef, int x, int y);
	~Animal();
	void multiply(int x, int y);
	void action(char ch);
	bool collision(Organism* other);
	bool ifReflectedAtack(Organism* other) { return false; };
	virtual Organism * reproduction(int x, int y) = 0;
	Animal(World* worldRef, int x, int y, int power, int age);

};
