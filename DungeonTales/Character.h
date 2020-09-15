#pragma once
/** This is the character class, representing the player. All adventurers start as a character.
This class will hold all the game logic that the player will
need to get through the game.
*/
#include <iostream>
#include "Weapon.h"

using namespace std;

class Character {

private:
	string name;
	int health;
	bool alive;
	int potion;
	Weapon* starterWeapon;
	int counter = 0;

public:
	/**default constructor that sets the health to 100
	*/
	Character();

	/**method that allows you to set the health

	@param h - will take in the new health value
	*/
	void setHealth(int h);
	/**method that returns the current health
	@return health - the current health of the character
	*/
	int getHealth();
	/**method that allows you to set the name

	@param n - will take in the new name
	*/
	void setName(string n);
	/**method that returns the name of the character
	@return name - the current name of the character
	*/
	string getName();
	/**method gameLoop that is intended to run the course of the game
	contains all game logic and calls other methods
	*/
	void gameLoop();


	/**method weaponType that allows the user to choose a weapon
	depending on if they are a mage or a warrior, the options
	will be different

	@param person - takes in the character in order to see if they're a warrior or mage
	*/
	void weaponType();
	/**method leftOptions that will hold different menu options and
	what happens to the user once they choose the left path
	*/
	void leftOptions();
	/**method rightOptions that will hold different menu options and
	what happens to the user once they choose the right path
	*/
	void rightOptions();
	/**method battleOptions that will allow for combat attacks, run away,
	and/or use a potion.
	*/
	void battleOptions();
	/**method potion that allows user to add health to their current health.
	*/
	void usePotion();
	/**method isAlive that returns if character is alive or not

	@return alive - current status of character
	*/
	bool isAlive();
	/**method that returns the user to full health
	*/
	void fullHealth();
	/**method potion that allows user to add health to their current health.
	*/
	void addPotion();
};