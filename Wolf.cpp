#include "Wolf.h"
#include <string>



Wolf::Wolf()
{
	Creature::Creature();
	attack = 0;
	name = "-";
	sname = '-';
	meat = 0; 
}

void Wolf::wolfValue() {
	Creature::Creature();
	attack = rand() % 10;
	name = "Wolf";
	sname = 'W';
	meat = (rand() % 20);

}


Wolf::~Wolf()
{
}
