#pragma once
#include <iostream>
#include <vector>
#include <conio.h>

class Organism;
class World
{
private:
	int turn;
	int width;
	int height;
	char**viewer;

	std::vector<Organism *> Organisms;
	std::string log;
public:
	World(int width, int height);
	void draw();
	void doTurn(char ch);
	int getWidth();
	int getHeight();
	void deleteOrganism(Organism * o);
	Organism * getOrganismByLocation(int x, int y);
	int getTurn();
	void addOrganism(Organism *);
	void save();
	void load();
	void addToLog(std::string s);
};

