#include "Terrain.h"
#include "unitTerrain.h"
#include "Wolf.h"
#include "Ogre.h"
#include <iostream>
#include <iomanip>
#include "time.h"
#include <windows.h>

Terrain:: Terrain() {
	fillEdge(); 
	for (int i = 1; i < 12; i++) {
		for (int j = 1; j < 12; j++) {
			
			unitTerrain base;
		}
	}
}

Terrain::Terrain(char fill) {
	fillEdge();
	for (int i = 1; i < 11; i++) {
		for (int j = 1; j < 11; j++) {
			base[i][j].space = fill; 
		
		}
	}
}

void Terrain::generateTerrain(fstream inputFile) {
	
	int i, j;
	inputFile >> i >> j;
	while (!"XXX") {
		inputFile >> base[i][j].type;
		inputFile >> i >> j;
	}


}
void Terrain::generateCreatures() {
	srand((unsigned int)time(NULL));
	int p1, p2; 
	p1 = (rand() % 6) - 1 ;
	p2 = (rand() % 6) - 1;
	//Wolf *pnw;
	
	
	for (int i = 0; i < 5; i++) {
		Wolf nw;
		nw.wolfValue();
		//pnw = &nw;
		while (base[p1][p2].checkifOccupied()) {
			p1 = (rand() % 6) - 1;
			p2 = (rand() % 6) - 1;
		
		}
		base[p1][p2].w = nw;
		base[p1][p2].space = nw.sname;
		
		p1 = (rand() % 6) - 1;
		p2 = (rand() % 6) - 1;
	}

	p1 = (rand() % 6) + 4;
	p2 = (rand() % 6) + 4;
	

	for (int i = 0; i < 5; i++) {
		Ogre no;
		no.ogreValue();
		while (base[p1][p2].checkifOccupied()) {
			p1 = (rand() % 6) + 4;
			p2 = (rand() % 6) + 4;
		}
		base[p1][p2].o = no;
		base[p1][p2].space = no.sname;
		p1 = (rand() % 6) + 4;
		p2 = (rand() % 6) + 4;
	}

}
void Terrain::generateChest(int &i, int &j) {
	srand((unsigned int)time(NULL));
	i = (rand() % 11) ;
	j = (rand() % 11) ;
	while (base[i][j].checkifOccupied()) {
		i = (rand() % 11) ;
		j = (rand() % 11) ;
	}
	base[i][j].space = 'C';
}

//void Terrain::printSurroundings(int pi, int pj) {
//	cout << setw(5);
//	cout << " *** CURRENT SURROUNDINGS *** " << endl;
//
//	if (pi < 1 && pj < 1) { 																				// If Top left corner
//		cout << setw(15) << "X X X" << endl;
//		for (int i = pi; i <= pi + 1; i++) {
//			cout << setw(12) << "X ";
//			for (int j = pj; j <= pj + 1; j++) {
//				//base[i][j].printWhich();
//				
//				cout << base[i][j].space << " ";
//
//			}
//			cout << endl;
//		}
//	}
//
//	else if (pi < 1 && pj > 8) {																			// If Top right corner
//		cout << setw(15) << "X X X" << endl;
//		for (int i = pi; i <= pi + 1; i++) {
//			cout << setw(11);
//			for (int j = pj - 1; j <= pj; j++) {
//
//				//base[i][j].printWhich();
//				cout << base[i][j].space << " ";
//
//			}
//			cout << "X" << endl;
//		}
//	}
//
//	else if (pi > 8 && pj < 1) { 																			// If bottom left corner
//		for (int i = pi - 1; i <= pi; i++) {
//			cout << setw(12) << "X ";
//			for (int j = pj; j <= pj + 1; j++) {
//
//				//base[i][j].printWhich();
//				cout << base[i][j].space << " ";
//			}
//			cout << endl;
//		}
//		cout << setw(15) << "X X X" << endl;
//	}
//
//	else if (pi > 8 && pj > 8) { 																			// If bottom right corner
//		for (int i = pi - 1; i <= pi; i++) {
//			cout << setw(11);
//			for (int j = pj - 1; j <= pj; j++) {
//
//				//base[i][j].printWhich();
//				cout << base[i][j].space << " ";
//			}
//			cout << "X" << endl;
//		}
//		cout << setw(15) << "X X X" << endl;
//	}
//
//	else if (pi < 1) { 																						// If top side
//		cout << setw(15) << "X X X" << endl;
//		for (int i = pi; i <= pi + 1; i++) {
//			cout << setw(11);
//			for (int j = pj - 1; j <= pj + 1; j++) {
//
//			//	base[i][j].printWhich();
//				cout << base[i][j].space << " ";
//			}
//			cout << endl;
//		}
//	}
//
//	else if (pj < 1) {  																					// If left side
//		for (int i = pi - 1; i <= pi + 1; i++) {
//			cout << setw(12) << "X ";
//			for (int j = pj; j <= pj + 1; j++) {
//
//				//base[i][j].printWhich();
//				cout << base[i][j].space << " ";
//			}
//			cout << endl;
//		}
//	}
//
//	else if (pj > 8) { 																						// If right side
//		for (int i = pi - 1; i <= pi + 1; i++) {
//			cout << setw(11);
//			for (int j = pj - 1; j <= pj; j++) {
//
//				//base[i][j].printWhich();
//				cout << base[i][j].space << " ";
//			}
//			cout << "X" << endl;
//		}
//	}
//
//	else if (pi > 8) {  																					// If bottom side
//		for (int i = pi - 1; i <= pi; i++) {
//			cout << setw(11);
//			for (int j = pj - 1; j <= pj + 1; j++) {
//
//				//base[i][j].printWhich();
//				cout << base[i][j].space << " ";
//			}
//			cout << endl;
//		}
//		cout << setw(15) << "X X X" << endl;
//	}
//
//	else {
//		for (int i = pi - 1; i <= pi + 1; i++) {
//			cout << setw(11);
//			for (int j = pj - 1; j <= pj + 1; j++) {
//				cout << base[i][j].space << " "; 
//
//			}
//			cout << endl;
//		}
//
//	}
//	cout << endl;
//
//	cout << endl << endl; 
//	cout << "       " << "X = OUT OF BOUNDS" << endl; 
//	cout << "       "  << "Y = YOUR CHARACTER" << endl;
//	cout << "       "  << "W = Wolf, O = Ogre" << endl;
//	cout << "       " << "D = Dead Creature" << endl;
//	cout << "       "  << "C = TREASURE" << endl;
//	cout << endl; 
//}

void Terrain::printAll() {
	cout << " *** --- MAP --- *** " << endl;
	for (int i = 0; i < 12; i++) {
		for (int j = 0; j < 12; j++) {
			cout << base[i][j].space << " "; 
		}
		cout << endl; 
	}
	cout << endl;
}

void Terrain::printHere(int row, int col) {
	gotorowcolumn(row, col);
	printAll();

}

void Terrain::gotorowcolumn(int r, int c) {
	COORD p = {c, r};
	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), p);

}
void Terrain::fillEdge() {
	for (int x = 0; x < 12; x++) {
		base[0][x].space = 'X';
		base[11][x].space = 'X';
		base[x][0].space = 'X'; 
		base[x][11].space = 'X'; 
	}

}
void Terrain::flushNumRowAtrc(int num, int r, int c) {
	gotorowcolumn(r, c);
	for (int i = 0; i < num; i++) {
		cout << "                                                                                                           " << endl; 
	}
	gotorowcolumn(r, c);
}

void Terrain::transfermapping(Terrain &base2, int pi, int pj) {
	for (int i = pi - 1; i <= pi + 1; i++) {
		for (int j = pj - 1; j <= pj + 1; j++) {
			base2.base[i][j].space = base[i][j].space;
		}
	}

}