#include "Ogre.h"



Ogre::Ogre()
{
	name = "-";
	sname = '-';
	meat = 0;

}

void Ogre::ogreValue() {
	Creature::Creature();
	attack = rand() % 20;
	name = "Ogre";
	sname = 'O';
	meat = (rand() % 10);

}

Ogre::~Ogre()
{
}
