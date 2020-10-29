#include "World.h"
#include "Organisms.h"
#include <cstdlib>
#include <iostream>
#include "Hogweed.h"
#include "Human.h"
#include "Sheep.h"
#include "Grass.h"
#include "Turtle.h"
#include "Antelope.h"
#include "Fox.h"
#include "SowThistle.h"
#include "Guarana.h"
#include "Wolf.h"
#include <windows.h>
#include "DeadlyNightshade.h"
#include <algorithm>
#include <fstream>
#include <string>
using namespace std;

int World::getWidth() {
	return width;
}
int World::getHeight() {
	return height;
}
int World::getTurn() {
	return turn;
}

World::World(int width, int height) {
	log = "";
	turn = 0;
	this->width = width;
	this->height = height;
	viewer = new char*[height];
	for (int i = 0;i < height;i++) {
		viewer[i] = new char[width];
		for (int j = 0;j < width;j++)
		{
			viewer[i][j] = ' ';
		}
	}
	Organisms.push_back(new Human(this, 0, 0));
	Organisms.push_back(new Sheep(this, 1, 10));
	Organisms.push_back(new Grass(this, 2, 10));
	Organisms.push_back(new Grass(this, 7, 11));
	Organisms.push_back(new Fox(this, 1, 5));
	Organisms.push_back(new Turtle(this, 5, 5));
	Organisms.push_back(new Turtle(this, 5, 2));
	Organisms.push_back(new Hogweed(this, 1, 18));
	Organisms.push_back(new Hogweed(this, 1, 19));
	Organisms.push_back(new Turtle(this, 5, 4));
	Organisms.push_back(new Antelope(this, 5, 1));
	Organisms.push_back(new Sheep(this, 11, 10));
	Organisms.push_back(new Fox(this, 11, 5));
	Organisms.push_back(new Turtle(this, 15, 5));
	Organisms.push_back(new Antelope(this, 15, 1));
	Organisms.push_back(new Guarana(this, 11, 12));
	Organisms.push_back(new Guarana(this, 19, 12));
	Organisms.push_back(new Fox(this, 11, 15));
	Organisms.push_back(new Turtle(this, 15, 15));
	Organisms.push_back(new Antelope(this, 15, 11));
	addOrganism(new DeadlyNightshade(this, 2, 2));
	addOrganism(new DeadlyNightshade(this, 18, 2));
	addOrganism(new SowThistle(this, 13, 13));
	addOrganism(new SowThistle(this, 13, 12));
	addOrganism(new Wolf(this, 12, 12));
	addOrganism(new Wolf(this, 35, 12));
	addOrganism(new Sheep(this, 4, 10));
}

void World::draw() {

	for (int i = 0;i < height;i++) {
		for (int j = 0;j < width;j++) {
			viewer[i][j] = ' ';
		}
	}
	for (int i = 0;i < Organisms.size();i++)
	{
		viewer[Organisms[i]->getLocationY()][Organisms[i]->getLocationX()] = Organisms[i]->getSign();
	}
	system("cls");

	cout << char(201);
	for (int i = 0;i < width;i++) {
		cout << char(205);
	}
	cout << char(187);
	cout << endl;
	for (int i = 0;i < height;i++) {
		cout << char(186);
		for (int j = 0;j < width;j++) {
			cout << viewer[i][j];
		}
		cout << char(186);
		cout << endl;
	}
	cout << char(200);
	for (int i = 0;i < width;i++) {
		cout << char(205);
	}
	cout << char(188);
	cout << endl;
	cout << "Turn " << turn << endl;
	cout << "n - next round" << endl;
	cout << "arrows - move human" << endl;
	cout << "x - special ability of human" << endl;
	cout << "f - finish" << endl;
	cout << "s - save the file" << endl;
	cout << "l - load the file" << endl;


	int heightLog = 0;
	int widthLog = 55;
	for (int i = 0;i < log.size();i++)
	{
		COORD pos = { widthLog,  heightLog };
		HANDLE output = GetStdHandle(STD_OUTPUT_HANDLE);
		SetConsoleCursorPosition(output, pos);
		if (log[i] == '\n')
		{
			widthLog = 55;
			heightLog++;
			continue;
		}
		cout << log[i];
		widthLog++;
	}


}



void World::doTurn(char ch) {
	turn++;
	log = "";
	//puzyrkowaja sortirowka
	for (int i = 0;i < Organisms.size();i++)
	{
		for (int j = i;j < Organisms.size();j++) {
			if (Organisms[i]->getInitiative() < Organisms[j]->getInitiative())
			{
				swap(Organisms[i], Organisms[j]);
			}
			else if (Organisms[i]->getInitiative() == Organisms[j]->getInitiative() && Organisms[i]->getAge()>Organisms[j]->getAge())
			{
				swap(Organisms[i], Organisms[j]);
			}
		}


	}
	int count = Organisms.size();
	for (int i = 0;i < count && i<Organisms.size();i++)
	{
		Organisms[i]->action(ch);
		for (int j = 0;j < Organisms.size() && i < Organisms.size();j++) {
			if (Organisms[i]->sameLocation(Organisms[j])) {

				if (Organisms[i]->collision(Organisms[j]) == false)
					break;

			}
		}
	}
}

void World::deleteOrganism(Organism *o)
{

	this->Organisms.erase(std::remove(this->Organisms.begin(), this->Organisms.end(), o), this->Organisms.end());
	delete o;
}

Organism * World::getOrganismByLocation(int x, int y)
{
	for (int i = 0;i < Organisms.size();i++)
	{
		if (Organisms[i]->getLocationX() == x && Organisms[i]->getLocationY() == y)
			return Organisms[i];
	}
	return NULL;
}

void World::addOrganism(Organism* o) {


	for (int i = 0;i < Organisms.size();i++)
	{
		if (Organisms[i]->getLocationX() == o->getLocationX() && Organisms[i]->getLocationY() == o->getLocationY())
			return;
	}
	Organisms.push_back(o);
}

void World::save() {

	system("cls");
	string nazwaPliku;

	cout << "Podaj nazwe pliku do zapisu: ";
	cin >> nazwaPliku;
	std::fstream fs;
	fs.open(nazwaPliku, std::fstream::in | std::fstream::out | std::fstream::app);
	for (int i = 0;i < Organisms.size();i++)
	{
		fs << Organisms[i]->getSign() << " " << Organisms[i]->getLocationX() << " " << Organisms[i]->getLocationY() << " " << Organisms[i]->getPower() << " " << Organisms[i]->getAge() << endl;
	}

	fs.close();

}

void World::load() {

	system("cls");
	string nazwaPliku;
	cout << "Podaj nazwe pliku do zapisu: ";
	while (Organisms.size())
		this->deleteOrganism(Organisms[0]);

	cin >> nazwaPliku;
	std::fstream fs;
	fs.open(nazwaPliku, std::fstream::in);
	while (!fs.eof())
	{
		char sign;
		int x, y, power, age;

		fs >> sign >> x >> y >> power >> age;
		switch (sign)
		{
		case 'F':
			this->addOrganism(new Fox(this, x, y, power, age));
			break;
		case 'A':
			this->addOrganism(new Antelope(this, x, y, power, age));
			break;
		case 'H':
			this->addOrganism(new Human(this, x, y, power, age));
			break;
		case 'g':
			this->addOrganism(new Grass(this, x, y, power, age));
			break;
		case 'u':
			this->addOrganism(new Guarana(this, x, y, power, age));
			break;
		case 'h':
			this->addOrganism(new Hogweed(this, x, y, power, age));
			break;
		case 's':
			this->addOrganism(new SowThistle(this, x, y, power, age));
			break;
		case 'T':
			this->addOrganism(new Turtle(this, x, y, power, age));
			break;
		case 'W':
			this->addOrganism(new Wolf(this, x, y, power, age));
			break;
		case 'd':
			this->addOrganism(new DeadlyNightshade(this, x, y, power, age));
			break;
		case 'S':
			this->addOrganism(new Sheep(this, x, y, power, age));
			break;
		default:
			break;
		}
	}
	fs.close();
}
void World::addToLog(std::string o)
{
	log += o;
}