#pragma once
/**This is the Wand class. This class will hold the stats related to the Wand, only mages will be using this.
*/
#include "Weapon.h"
#include <iostream>

using namespace std;

class Wand : public Weapon {

private:
    string color; // color of wand

    string name; // name of wand

    int damage; // damage of wand

public:
    /**wand default constructor
    */
    Wand();
    /**wand constructor that sets the name, color,
    and damage

    @param name - sets name of wand
    @param color - sets color of wand
    @param dmg - sets damage of wand
    */
    Wand(const string name, const string color, const int dmg);
    /**wand deconstructor
    */
    ~Wand(); //destructor
     /** sets the color of the wand

      @param color - takes in new color value
    */
    void setWandColor(const string col);
    /** gets the color of the wand

     @return color - current color of wand
   */
    string getWandColor();
    /**method that allows you to set the name of the wand

    @param name - will take in the new name
    */
    void setWandName(string name);
    /**  gets the name of the wand

     @return name - current name of weapon
   */
    string getWandName();
    /** sets the damage of the wand

     @param dmg - takes in new damage value
   */
    void setDamage(int dmg);
    /** gets the damage of the wand

     @return damage - current damage value
   */
    int getDamage();

    /** prints out the name and the color of the wand
    */
    void printDims();

};