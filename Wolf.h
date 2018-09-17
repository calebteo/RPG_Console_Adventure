#pragma once
#include "Creature.h"

class Wolf : public Creature
{
public:
	
	int meat; 
	char sname; 

	Wolf();
	void wolfValue();
	~Wolf();
};

