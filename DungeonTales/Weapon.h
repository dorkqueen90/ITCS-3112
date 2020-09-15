/**This is a weapon header that will be the base of the character's weapon. Holds all declarations for the base weapon.
All characters will start with this weapon. 
*/
#pragma once

#include <iostream>

using namespace std;

class Weapon {
private:

    int damage;

    string name;

public:
    /**Default weapon constructor
    */
    Weapon();
    /**
     sets the name of the weapon

     @param inName - takes in new name of weapon
   */
    void setWeaponName(string inName);
    /**
     gets the name of the weapon

     @return name - current name of weapon
   */
    string getWeaponName();
    /**
     gets the damage of the weapon

     @return damage - current damage of weapon
   */
    int getWeaponDamage();
    /**
     sets the damage of the weapon

     @param inDamage - takes in new damage value
   */
    void setWeaponDamage(int inDamage);
    

    
};