#pragma once
#include "unitTerrain.h"

using namespace std; 

class Terrain {
public: 
	unitTerrain base[12][12]; 

	Terrain(); 
	Terrain(char fill); 
	void generateTerrain(fstream inputFile); 
	void generateCreatures();
	void generateChest(int &i, int &j);
	void printSurroundings(int pi, int pj);
	void printAll(); 
	void printHere(int row, int col);
	void fillEdge(); 
	void gotorowcolumn(int r, int c);
	void flushNumRowAtrc(int num, int r, int c);
	void transfermapping(Terrain &base2, int pi, int pj);
};