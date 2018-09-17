#include "Creature.h"
#include <random>
#include<iostream>
using namespace std;

Creature::Creature()
{
	name; 
	health = 100; 
	attack = rand() % 20 + 5; 
}

void Creature::attackmove(int &enemyH, int block) {
	int tempattack = attack - block;
	if (block > attack) {
		tempattack = 0; 

	}
	
	enemyH = enemyH - tempattack; 
}

void Creature::attackmove(int &enemyH) {
	enemyH = enemyH - attack;
}

Creature::~Creature()
{

}
