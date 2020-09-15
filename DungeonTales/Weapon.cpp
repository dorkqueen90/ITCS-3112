/**This is a weapon cpp file, holds all implementations from the weapon header file.
*/
#include <iostream>
#include "Weapon.h"

using namespace std;


    /**Default weapon constructor
    */
    Weapon::Weapon() {}
    /**
     sets the name of the weapon

     @param inName - takes in new name of weapon
   */
    void Weapon::setWeaponName(string inName){
        name = inName;
    }
    /**
     gets the name of the weapon

     @return name - current name of weapon
   */
    string Weapon::getWeaponName(){
        return name;
    }
    /**
     gets the damage of the weapon

     @return damage - current damage of weapon
   */
    int Weapon::getWeaponDamage(){
        return damage;
    }
    /**
     sets the damage of the weapon

     @param inDamage - takes in new damage value
   */
    void Weapon::setWeaponDamage(int inDamage){
        damage = inDamage;
    }
    
