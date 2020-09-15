#include "Character.h"
#include "Wand.h"
#include "Mage.h"
/**This is the Mage cpp file, implementing everything from mage header file.
Can only use wands and staff.
*/
using namespace std;

/**mage constructor that sets the name as mage and the health as 100
*/
Mage::Mage() {
	setName("Mage");
	setHealth(100);
}

/**method that adds a potion to your bags/character
	*/
void Mage::addPotion() {
	potion++;
}
/**method that returns the user to full health
	*/
void Mage::fullHealth() {
	setHealth(100);
}
/**method potion that allows user to add 35 health to their current health.
	*/
void Mage::usePotion() {
	setHealth(getHealth() + 35);
}