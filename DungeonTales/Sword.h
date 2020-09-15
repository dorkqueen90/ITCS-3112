#pragma once
/**This is the Sword class. This class will hold the stats related to the Sword.
Only the warrior will be using this.
*/
#include <iostream>
#include "Weapon.h"

using namespace std;

class Sword : public Weapon {
private:
    string color; // color of sword

    string name; // name of sword

    int damage; // damage of sword

public:
    /**sword default constructor
    */
    Sword();
    /**sword constructor that sets the name, color,
    and damage

    @param name - sets name of sword
    @param color - sets color of sword
    @param dmg = sets damage of sword
    */
    Sword(const string name, const string color, const int dmg);
    /**sword deconstructor
    */
    ~Sword(); //destructor
    /**sets the color of the sword

      @param color - takes in new color value
    */
    void setSwordColor(const string col);
    /**gets the color of the sword

     @return color - current color of sword
   */
    string getSwordColor();
    /**method that allows you to set the name of the sword

    @param name - will take in the new name
    */
    void setSwordName(string name);
    /** gets the name of the sword

     @return name - current name of weapon
   */
    string getSwordName();
    /** sets the damage of the sword

     @param dmg - takes in new damage value
   */
    void setDamage(int dmg);
    /**gets the damage of the sword

     @return dmg - current damage value
   */
    int getDamage();

    /** prints out the name and the color of the wand
    */
    void printDims();

};