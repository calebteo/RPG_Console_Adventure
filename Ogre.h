#pragma once
#include "Creature.h"

class Ogre:public Creature
{
public:
	char sname;
	int meat; 
	Ogre();
	void ogreValue();
	~Ogre();
};

