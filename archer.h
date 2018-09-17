#pragma once
#include "Hero.h"
#include "Terrain.h"

class archer :public Hero
{
private:

public:
	int speed; 
	
	archer();
	void BattleMode(Terrain &a, int enemypi, int enemypj);
	void printstats();

	~archer();
};
