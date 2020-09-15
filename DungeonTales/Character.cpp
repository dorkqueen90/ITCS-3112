/**This is the character cpp file, implementing all declarations in the character header file. This class has all the game logic that the player will
need to get through the game.
*/
#include "Mage.h"
#include "Warrior.h"
#include "Character.h"
#include "GreatSword.h"
#include "Staff.h"
#include <iostream>
#include <ctime>

using namespace std;


/**default constructor that sets the character to alive, starts them with 1 potion,
and creates their starter weapon
*/
Character::Character() {
	alive = true;
	potion = 1;
	starterWeapon = new Weapon();
}

/**method that allows you to set the health

@param h - will take in the new health value
*/
void Character::setHealth(int h) {
	health = h;
}
/**method that returns the current health

@return health - the current health of the character
*/
int Character::getHealth() {
	return health;
}
/**method that allows you to set the name

@param n - will take in the new name
*/
void Character::setName(string n) {
	name = n;
}
/**method that returns the name of the character

@return name - the current name of the character
*/
string Character::getName() {
	return name;
}

/**method gameLoop that is intended to run the course of the game
contains all game logic and calls other methods
loops through 5 times, allowing the character to attempt to live
through 5 turns, then ends
*/
void Character::gameLoop() {

	int direction;

	for (int i = 0; i < 10; i++) {

		if (isAlive() && counter <= 4) {
			//left or right
			cout << "You've come upon a crossroads, which way would you like to go?" << endl;
			cout << "1. Left\n2. Right" << endl;
			while (!(cin >> direction)) {
				cin.clear();
				cin.ignore(100, '\n');
				cout << "Please enter 1 or 2" << endl;
			}
			//left option
			if (direction == 1) {
				leftOptions();
			} //right option
			else if (direction == 2) {
				rightOptions();
			}
		}
		//exit if you're dead
		if (isAlive() == false) {
			cout << "You have died. Game Over." << endl;
			exit(0);
		}
		//exit if you've stayed alive through 4 turns
		if (counter > 4) {
			cout << "Congratulations! You've made it to the end of the dungeon." << endl;
			exit(0);
		}
		counter++;
	}
}

/**method weaponType that allows the user to choose a weapon
depending on if they are a mage or a warrior, the options
will be different
*/
void Character::weaponType() {
	string name = getName();
	int choice;

	//if warrior, options are sword and greatSword
	if (name == "Warrior") {
		cout << "Would you prefer to use:\n1. Sword\n2. Great Sword" << endl;
		while (!(cin >> choice)) {
			cin.clear();
			cin.ignore(100, '\n');
			cout << "Please enter 1 or 2" << endl;
		}
		if (choice == 1) {
			cout << "You have chosen Sword.\nA sword appears in your hand." << endl;
			starterWeapon = new Sword();
		}
		if (choice == 2) {
			cout << "You have chosen Great Sword.\nA Great Sword appears in your hand." << endl;
			starterWeapon = new GreatSword();
		}
	}
	//if mage, options are wand and staff
	else if (name == "Mage") {
		cout << "Would you prefer to use:\n1. Wand\n2. Staff" << endl;
		while (!(cin >> choice)) {
			cin.clear();
			cin.ignore(100, '\n');
			cout << "Please enter 1 or 2" << endl;
		}
		if (choice == 1) {
			cout << "You have chosen Wand.\nA wand appears in your hand." << endl;
			starterWeapon = new Wand();
		}
		if (choice == 2) {
			cout << "You have chosen Staff.\nA staff appears in your hand." << endl;
			starterWeapon = new Staff();
		}
	}
	else {
		exit(0);
	}
}
/**method leftOptions that will hold different menu options and
what happens to the user once they choose the left path
*/
void Character::leftOptions() {
	srand((unsigned int)time(NULL));
	int random = rand() % 5;

	//5 options for going left
	switch (random) {
	case 0:
		cout << "You come across an odd-shaped object that looks like a fish. You find that it is a health potion, you add it to your bag" << endl;
		addPotion();
		break;
	case 1:
		cout << "You hear a loud rumble and turn to see a giant eight-legged bull rushing towards you." << endl;
		battleOptions();
		break;
	case 2:
		cout << "It's too quiet in here and it's making you nervous. You decide to sing a song to lighten your spirits.\n You continue on." << endl;
		break;
	case 3:
		cout << "You accidentally step on a loose stone. Before you know it, the entire floor is falling from under you. You fall to your death." << endl;
		alive = false;
		break;
	case 4:
		cout << "You run into a large spider web. As you struggle to break free, the spider comes towards you from the ceiling." << endl;
		battleOptions();
		break;
	}
}
/**method rightOptions that will hold different menu options and
what happens to the user once they choose the right path
*/
void Character::rightOptions() {
	srand((unsigned int)time(NULL));
	int random = rand() % 5;

	//5 options for going left
	switch (random) {
	case 0:
		cout << "You decided to sharpen your weapon before continuing on into the dungeon, to keep your wits sharp and weapon sharper.\nYou continue on." << endl;
		break;
	case 1:
		cout << "As you continue through the dungeon, a little ball of blue light heads towards you. It hits you in the face and you fall backwards." << endl;
		cout << "You lose 25 health from falling." << endl;
		health = health - 25;
		break;
	case 2:
		cout << "You pick up a rock along the path and throw it into the darkness in front of you.... Something throws it back at you full force.... at your head. YOU DIE." << endl;
		alive = false;
		break;
	case 3:
		cout << "From out of a close-by prison, an undead hears you rustling about and slowly comes to eat your brains." << endl;
		battleOptions();
		break;
	case 4:
		cout << "As you make your way through the dungeon, you come across a fairy. The fairy decides you to be harmless and refreshes your health to full." << endl;
		fullHealth();
		break;
	}
}
/**method battleOptions that will allow for combat attacks, run away,
and/or use a potion.
*/
void Character::battleOptions() {
	srand((unsigned int)time(NULL));
	int attackChance = rand() % 10;
	int decision;

	cout << "What will you do?" << endl;
	//attack, use potion, run away
	cout << "1. Attack\n2. Use Health Potion\n3. Attempt to run away" << endl;
	while (!(cin >> decision)) {
		cin.clear();
		cin.ignore(100, '\n');
		cout << "Please enter 1, 2, or 3" << endl;
	}
	switch (decision) {
	case 1: //attack option
		cout << "You've decided to attack. You throw all your power at the monster and... " << endl;
		//less chance of survival if you have a weaker weapon
		if (starterWeapon->getWeaponName() == "Sword") {
			if (attackChance >= 6) {
				cout << "You hit the monster with just the right force. The monster dies." << endl;
				cout << "You've lost 50 health in the process. You continue on the path." << endl;
				setHealth(getHealth() - 50);
			}
			else {
				cout << "Your weapon seems to be lacking, you miss. The monster comes at you full force. You die." << endl;
				alive = false;
			}
		} //wands are stronger than swords
		if (starterWeapon->getWeaponName() == "Wand") {
			if (attackChance >= 5) {
				cout << "You hit the monster with just the right force. The monster dies." << endl;
				cout << "You've lost 50 health in the process. You continue on the path." << endl;
				setHealth(getHealth() - 50);
			}
			else {
				cout << "Your weapon seems to be lacking, you miss. The monster comes at you full force. You die." << endl;
				alive = false;
			}
		}
			//better chance of killing the monster if you have a better weapon
		if (starterWeapon->getWeaponName() == "GreatSword") {
			if (attackChance >= 3) {
				cout << "You abolished the monster before he can get an attack off. You continue on the path." << endl;
			}
			else {
				cout << "Luck is not in your favor, you miss. The monster strikes you. You die." << endl;
				alive = false;
			}
		} //staves are stronger than great swords
		if (starterWeapon->getWeaponName() == "Staff") {
			if (attackChance >= 2) {
				cout << "You abolished the monster before he can get an attack off. You continue on the path." << endl;
			}
			else {
				cout << "Luck is not in your favor, you miss. The monster strikes you. You die." << endl;
				alive = false;
			}
		}
		break;
	case 2: //use potion
		cout << "You've decided to use a potion. You restore 35 health." << endl;
		usePotion();
		battleOptions();
		break;
	case 3: //change to run away
		cout << "You've decided to try and run away....." << endl;
		if (attackChance >= 6) {
			cout << "You succeed and get away safetly.\nYou continue on the path." << endl;
		}
		else {
			cout << "You turn to run and trip on the way out. The monster eats your face. You die." << endl;
			alive = false;
		}
		break;
	}
}
/**method potion that allows user to add health to their current health.
*/
void Character::usePotion() {
	if (potion > 0) {
		setHealth(getHealth() + 35);
	}
	else
		cout << "Sorry, you have no potions left....." << endl;
}
/**method isAlive that returns if character is alive or not

@return alive - current status of character
*/
bool Character::isAlive() {
	return alive;
}
/**method that returns the user to full health
	*/
void Character::fullHealth() {
	setHealth(100);
}
/**method potion that allows user to add health to their current health.
	*/
void Character::addPotion() {
	potion++;
}
