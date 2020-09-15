#pragma once
/**This is the GreatSword class, inheriting the Sword. This is the empowered version of the sword.
GreatSword will have higher damage than the Sword.
Only the warrior will be using this.
*/

#include <iostream>
#include "Sword.h"
#include "Weapon.h"

using namespace std;

class GreatSword : public Sword {
private:

    int damage; //damage of the sword

    string color; //color of the sword

    string name; //name of the sword
public:
    /**greatsword constructor that doubles the strength
    */
    GreatSword();
    /**greatsword constructor that sets the damage

    @param dmg - sets damage of sword
    */
    GreatSword(int dmg);
    /**sword deconstructor
    */
    ~GreatSword();
    /**sets the color of the Great Sword

      @param color - new color of the sword
    */
    void setGreatSwordColor(string color);
    /**
     gets the color of the Great Sword

     @return color - current color of the sword
   */
    string getGreatSwordColor();
    /**
     sets the name of the Great Sword

     @param name - new name value
   */
    void setGreatSwordName(string name);
    /**
     gets the name of the Great Sword

     @return name - current name of the sword
   */
    string getGreatSwordName();
    /**
     gets the strength of the Great Sword

     @return strength - current strength of the sword
   */
    int getGreatSwordDamage();
    /**
     sets the damage of the Great Sword

     @param damage - new damage value for the sword
   */
    void setGreatSwordDamage(int dmg);
    /**
    Override the print virtual function in Sword.h
    */
    void printDims();

};