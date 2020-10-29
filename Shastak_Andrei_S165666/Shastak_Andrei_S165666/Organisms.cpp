#pragma once
#include <string>
#include "Organisms.h"

Organism::Organism(World* worldRef, int x, int y) {
	this->x = x;
	this->y = y;
	this->world = worldRef;
	this->lastMove = -1;
	this->age = world->getTurn();

}

Organism::Organism(World* worldRef, int x, int y, int power, int age)
{
	this->x = x;
	this->y = y;
	this->world = worldRef;
	this->lastMove = -1;
	this->age = age;
	this->power = power;
}

Organism::~Organism() {
}

char Organism::getSign() {
	return this->sign;
}

int Organism::getInitiative() {
	return initiative;
}

int Organism::getAge() {
	return age;
}

int Organism::getLocationX() {
	return this->x;
}

int Organism::getLocationY() {
	return this->y;
}

void Organism::setLocationX(int x) {
	this->x = x;
	return;
}

void Organism::setPower(int p) {
	this->power = p;
	return;
}

void Organism::setLocationY(int y) {
	this->y = y;
	return;
}

bool Organism::sameLocation(Organism* o) {
	if (this != o && this->getLocationX() == o->getLocationX() && this->getLocationY() == o->getLocationY()) {
		return true;
	}
	return false;
}

int Organism::getPower() {
	return this->power;
}

void Organism::recoverPosition()
{
	switch (lastMove) {
	case 1:
		if (this->y<this->world->getHeight() - 1)
			this->y++;
		break;
	case 0:
		if (this->y>0)
			this->y--;
		break;
	case 3:
		if (this->x<this->world->getWidth() - 1)
			this->x++;
		break;
	case 2:
		if (this->x>0)
			this->x--;
		break;
	}
}