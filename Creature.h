#pragma once
#include<string>
using namespace std; 

class Creature
{
public:
	string name; 
	int health; 
	int attack;

	Creature();
	void attackmove(int &enemyH, int block);
	void attackmove(int &enemyH);
	~Creature();
};

