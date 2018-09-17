#pragma once
#include <string>
#include <fstream>
#include "Wolf.h"
#include "Ogre.h"

using namespace std;

class unitTerrain {
public: 
	string type; 
	Wolf w; 
	Ogre o;
	char space;

	unitTerrain(); 
	bool checkifOccupied(); 
	//void printWhich(); 
};