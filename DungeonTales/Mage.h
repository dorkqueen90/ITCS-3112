#pragma once
#include "Character.h"
#include "Weapon.h"
/**This is the Mage class, inheriting Character. This class type will do more damage, while having a smaller health pool.
Can only use wands and staff.
*/
using namespace std;

class Mage : public Character {

private:
	int health;
	string name;
	bool alive;
	int potion;

public:
	/**mage constructor that sets the name as mage
	*/
	Mage();

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