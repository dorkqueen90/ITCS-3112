/**DungeonTales.cpp : This file contains the 'main' function. Program execution begins and ends there.
@authors Parker Randolph, Amber Sibel
@date 04/10/2020
Text based adventure game where you make decisions based on a menu of options, some of which include
battles, crossroads to decide between, or mysterious things happening to you. Will you come out alive?
Or die trying to reach the finish line.
*/
#include "Character.h"
#include "Mage.h"
#include "Warrior.h"
#include <iostream>

using namespace std;

int main() {

	cout << "Welcome to Dungeon Tales, your adventure awaits..." << endl;

	//Character* person;
	int option;


	//mage or warrior?
	cout << "Which class would you like to be?" << endl;
	cout << "1. Warrior" << "\n2. Mage" << endl;
	//input validation
	while (!(cin >> option)){
	cin.clear();
	cin.ignore(100, '\n');
	cout << "Please enter 1 or 2" << endl;	
	}

	//warrior option
	if (option == 1) {
		Warrior* person = new Warrior();
		cout << "You have chosen to become a warrior. You now have 150 health." << endl;
		//menu for choosing a weapon type (allowing for submenu)
		person->weaponType();
		person->gameLoop();
	} //mage option
	else if (option == 2) {
		Mage* person = new Mage();
		cout << "You have chosen to become a mage. You now have 100 health." << endl;
		//menu for choosing a weapon type (allowing for submenu)
		person->weaponType();
		person->gameLoop();
	}


	

}