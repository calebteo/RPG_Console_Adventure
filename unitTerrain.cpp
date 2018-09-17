#include "unitTerrain.h"
#include <iostream>
#include <fstream>
using namespace std; 

unitTerrain::unitTerrain () {
	type = "-";
	space = '-';
	
}

bool unitTerrain:: checkifOccupied() {
	if (space != '-'){
			return true;
		}
	return false; 

}


/*void unitTerrain:: printWhich() {

	if (o->sname == 'O') {
		cout << o->sname << " ";
	}
	else if (w->sname == 'W') {
		cout << w->sname << " ";
	}
	else {
		cout << space << " ";
	}

}*/