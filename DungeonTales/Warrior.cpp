/**This is the Warrior cpp file, implementing everything from the warrior header file.
Can only use swords and greatswords.
*/
#include "Character.h"
#include "Warrior.h"

using namespace std;

/**warrior constructor that sets the name as warrior and the health as 150
*/
Warrior::Warrior() {
	setHealth(150);
	setName("Warrior");
}

/**method that adds a potion to your bags/character
	*/
void Warrior::addPotion() {
	potion++;
}
/**method that returns the user to full health
	*/
void Warrior::fullHealth() {
	setHealth(120);
}
/**method potion that allows user to add health to their current health.
	*/
void Warrior::usePotion() {
	setHealth(getHealth() + 35);
}