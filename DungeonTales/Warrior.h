#pragma once
/**This is the Warrior class, inheriting Character. This class type will have a greater health pool.
Can only use swords and greatswords.
*/
#include "Character.h"
#include "Weapon.h"

using namespace std;

class Warrior : public Character {

private:
	int health;
	string name;
	bool alive;
	int potion;

public:
	/**warrior constructor that sets the name as warrior
	*/
	Warrior();

	/**method that adds a potion to your bags/character
	*/
	void addPotion();
	/**method that returns the user to full health
	*/
	void fullHealth();
	/**method potion that allows user to add health to their current health.
	*/
	void usePotion();
};