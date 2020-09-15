#pragma once
/**This is the Staff class, inheriting the Wand. This is an empowered version of the wand, doing more damage.
Only the mage will be using this.
*/

#include <iostream>
#include "Wand.h"
#include "Weapon.h"

using namespace std;

class Staff : public Wand {
private:

    int damage;

    string color;

    string name;
public:
    /**staff constructor that doubles the damage
    */
    Staff();
    /**staff constructor that takes in a new damage value

    @param dmg - takes in a new damage value and updates it
    */
    Staff(int dmg);
    /**staff deconstructor
    */
    ~Staff();
    /**sets the color of the Staff

      @param color - takes in new color
    */
    void setStaffColor(string color);
    /**
     gets the color of the Staff

     @return color - returns current color
   */
    string getStaffColor();
    /**sets the name of the Staff

     @param name - takes in new name of weapon
   */
    void setStaffName(string name);
    /**gets the name of the Staff

     @return name - current name of weapon
   */
    string getStaffName();
    /** gets the magic strength of the Staff

     @return Mstrength - current magic strength of staff
   */
    int getStaffDamage();
    /**sets the damage of the Staff

     @param dmg - takes in new damage value
   */
    void setStaffDamage(int dmg);
    /**
    Override the print virtual function
    */
    void printDims();

};