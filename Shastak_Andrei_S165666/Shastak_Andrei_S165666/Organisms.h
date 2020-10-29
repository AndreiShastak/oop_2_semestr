#pragma once
#include "World.h"
#include <string>
class Organism
{

public:
	Organism(World* worldRef, int x, int y);
	Organism(World* worldRef, int x, int y, int power, int age);
	~Organism();

	char getSign();

	int getInitiative();

	int getLocationX();

	int getLocationY();

	int getPower();

	void setLocationX(int);

	void setLocationY(int);

	void setPower(int);

	virtual void multiply(int x, int y) = 0;

	virtual void action(char ch) = 0;

	virtual bool ifReflectedAtack(Organism* other) = 0;//bool czyOdbilAtak
	int getAge();

	bool sameLocation(Organism*);
	void recoverPosition();
	virtual bool collision(Organism* other)
	{
		return true;
	};

	virtual Organism * reproduction(int x, int y) = 0;
protected:

	World* world;

	int age;

	char sign;

	int power;

	int initiative;

	int x;
	int y;
	int lastMove;
};

