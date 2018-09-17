#pragma once
#include "Creature.h"
#include "Terrain.h"

class Hero :public Creature
{
private: 
	int pi, pj;
public:
	int armour; 
	int energy; 

	Hero();
	void BattleMode(Terrain &a, int enemypi, int enemypj, int row, int col);
	bool checkIfWin(int i, int j);
	bool checkCreatures(Terrain base, int &a, int &b); 
	void move(char l, Terrain &base, Terrain &printBase);
	void printstats();

	int getpi();
	int getpj(); 
	void setpi(int x);
	void setpj(int x);
	~Hero();
};

