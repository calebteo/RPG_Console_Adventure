#include "Hero.h"
#include "Terrain.h"
#include <iomanip>
#include <iostream>
#include <conio.h>
#include <Windows.h>
using namespace std;

Hero::Hero()
{
	Creature::Creature(); 
	armour = rand() % 5;
	pi = 1;  
	pj = 1;
	energy = 100; 
}
bool Hero:: checkIfWin(int i, int j) {
	if (getpi() == i && getpj() == j) {
		return true;
	}
	return false;
}

bool Hero:: checkCreatures(Terrain base, int &a, int &b) {


	//if (getpi() < 1 && getpj() < 1) {									//If Top left corner
	//	for (int i = getpi(); i <= getpi() + 1; i++) {
	//		for (int j = getpj(); j <= getpj() + 1; j++) {
	//			if (base.base[i][j].w.sname == 'W' || base.base[i][j].o.sname == 'O') {
	//				a = i;
	//				b = j;
	//				return true;
	//			}

	//		}
	//	}
	//}

	//else if (getpi() < 1 && getpj() > 8) {				      			// If top right corner
	//	for (int i = getpi(); i <= getpi() + 1; i++) {
	//		for (int j = getpj() - 1; j <= getpj(); j++) {
	//			if (base.base[i][j].w.sname == 'W' || base.base[i][j].o.sname == 'O') {
	//				a = i;
	//				b = j;
	//				return true;
	//			}
	//		}
	//	}
	//}

	//else if (getpi() > 8 && getpj() < 1) {																				// If bottom left corner
	//	for (int i = getpi() - 1; i <= getpi(); i++) {
	//		for (int j = getpj(); j <= getpj() + 1; j++) {
	//			if (base.base[i][j].w.sname == 'W' || base.base[i][j].o.sname == 'O') {
	//				a = i;
	//				b = j;
	//				return true;
	//			}
	//		}
	//	}
	//}

	//else if (getpi() > 8 && getpj() > 8) {																				// If bottom right corner
	//	for (int i = getpi() - 1; i <= getpi(); i++) {
	//		for (int j = getpj() - 1; j <= getpj(); j++) {

	//			if (base.base[i][j].w.sname == 'W' || base.base[i][j].o.sname == 'O') {

	//				a = i;
	//				b = j;
	//				return true;
	//			}
	//		}
	//	}
	//}

	//else if (getpi() < 1) {																							// If top side
	//	for (int i = getpi(); i <= getpi() + 1; i++) {
	//		for (int j = getpj() - 1; j <= getpj() + 1; j++) {
	//			if (base.base[i][j].w.sname == 'W' || base.base[i][j].o.sname == 'O') {
	//				a = i;
	//				b = j;
	//				return true;
	//			}
	//		}
	//	}
	//}

	//else if (getpj() < 1) { 																							// If left side
	//	for (int i = getpi() - 1; i <= getpi() + 1; i++) {
	//		for (int j = getpj(); j <= getpj() + 1; j++) {
	//			if (base.base[i][j].w.sname == 'W' || base.base[i][j].o.sname == 'O') {
	//				a = i;
	//				b = j;
	//				return true;
	//			}
	//		}
	//	}
	//}



	//else if (getpj() > 8) {																								// If right side
	//	for (int i = getpi() - 1; i <= getpi() + 1; i++) {
	//		for (int j = getpj() - 1; j <= getpj(); j++) {
	//			if (base.base[i][j].w.sname == 'W' || base.base[i][j].o.sname == 'O') {
	//				a = i;
	//				b = j;
	//				return true;
	//			}
	//		}
	//	}
	//}

	//else if (getpi() > 8) {																								// If bottom side
	//	for (int i = getpi() - 1; i <= getpi(); i++) {
	//		for (int j = getpj() - 1; j <= getpj() + 1; j++) {
	//			if (base.base[i][j].w.sname == 'W' || base.base[i][j].o.sname == 'O') {
	//				a = i;
	//				b = j;
	//				return true;
	//			}
	//		}
	//	}
	//}

	//else if {
		for (int i = getpi() - 1; i <= getpi() + 1; i++) {
			for (int j = getpj() - 1; j <= getpj() + 1; j++) {
				if (base.base[i][j].w.sname == 'W' || base.base[i][j].o.sname == 'O') {
					a = i;
					b = j;
					return true;
				}

			}
		}
	//}


	return false;
}

void Hero::BattleMode(Terrain &a, int enemypi, int enemypj, int row, int col) {
	a.gotorowcolumn(row, col);
	cout << "---- ENTERING BATTLE ----" << endl;
	a.flushNumRowAtrc(10, row + 1, col);
	if (a.base[enemypi][enemypj].w.sname == 'W') {
		Wolf penemy = a.base[enemypi][enemypj].w;

		while (health > 0 && penemy.health > 0) {
			penemy.attackmove(health, armour);

			cout << penemy.name << " attacked " << name << endl << endl;
			cout << "Armour block " << armour << " point(s) of damaged." << endl;

			cout << "Your Health: " << health << setw(15);
			cout << penemy.name << " Health: " << penemy.health << endl << endl;

			if (health <= 0) {
				break;
			}

			char answer;
			cout << "Would you like to attack? (y/n) ";
			answer = _getch();
			cout << endl;

			if (answer == 'y') {
				Creature::attackmove(penemy.health);
				cout << name << " attacked " << penemy.name << endl;
			}
			a.flushNumRowAtrc(7, row + 1, col);
		}
		a.flushNumRowAtrc(7, row, col);

		if (penemy.health <= 0) {
			cout << penemy.name << " is dead." << endl;
			a.base[enemypi][enemypj].space = 'D';
			a.base[enemypi][enemypj].w.sname = 'D';



			char answer;
			cout << penemy.name << " dropped meat, would you like to eat it? (y/n) ";
			answer = _getch();

			if (answer == 'y') {

				cout << "Health increased from " << health << " to ";
				health = health + penemy.meat;
				if (health >= 100) {
					health = 100;
				}

				cout << health << endl;
			}

		}
		if (health <= 0) {
			return;
		}

	}

	else if (a.base[enemypi][enemypj].o.sname == 'O') {
		Ogre penemy = a.base[enemypi][enemypj].o;

		while (health > 0 && penemy.health > 0) {
			penemy.attackmove(health, armour);

			cout << penemy.name << " attacked " << name << endl << endl;
			cout << "Armour block " << armour << " point(s) of damaged." << endl;

			cout << "Your Health: " << health << setw(15);
			cout << penemy.name << " Health: " << penemy.health << endl << endl;

			if (health <= 0) {
				break;
			}

			char answer;
			cout << "Would you like to attack? (y/n) ";
			answer = _getch();
			cout << endl;

			if (answer == 'y') {
				Creature::attackmove(penemy.health);
				cout << name << " attacked " << penemy.name << endl << endl;
				
			}
			a.flushNumRowAtrc(7, row + 1, col);
			
		}
		a.flushNumRowAtrc(7, row, col);
			if (penemy.health <= 0) {
				cout << penemy.name << " is dead." << endl;
				a.base[enemypi][enemypj].space = 'D';
				a.base[enemypi][enemypj].o.sname = 'D';


				char answer;
				cout << penemy.name << " dropped meat, would you like to eat it? (y/n) ";
				answer = _getch();

				if (answer == 'y') {

					cout << "Health decrease from " << health << " to ";
					health = health - penemy.meat;
					cout << health << endl;
				}

			}
		}
}


void Hero:: move(char l, Terrain &base, Terrain &printBase) {
	printBase.base[getpi()][getpj()].space = '-';
	if (l == 'w') {
		setpi(getpi() - 1);
	}
	else if (l == 's') {
		setpi(getpi() + 1);
	}
	else if (l == 'a') {
		setpj(getpj() - 1);
	}
	else if (l == 'd') {
		setpj(getpj() + 1);
	}
	base.transfermapping(printBase, getpi(), getpj());
	printBase.base[getpi()][getpj()].space = 'Y';
	energy = energy - 5; 
}


int Hero::getpi() {
	return pi; 
}
int Hero::getpj() {
	return pj; 
}
void Hero::setpi(int x) {
	pi = x;
}
void Hero::setpj(int x) {
	pj = x;
}

void Hero::printstats() {
	cout << "- - - HERO'S STATS - - -" << endl; 
	cout << "Hero's Health: " << health << endl; 
	cout << "Hero's Energy: " << energy << endl; 
	cout << "Hero's Armour: " << armour << endl; 
	cout << endl;
}
Hero::~Hero()
{
}

