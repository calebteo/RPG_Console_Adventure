#pragma once
#include "Hero.h"
#include "Terrain.h"

class caster :public Hero
{
private:

public:
	int spell_boost;

	caster();
	void BattleMode(Terrain &a, int enemypi, int enemypj);
	void printstats();
	void attackmove(int &enemyH);

	~caster();
};
