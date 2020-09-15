/**This is the wand cpp file, implementing everything from the wand header.
*/

#include "Wand.h"
#include <iostream>

using namespace std;


/**wand default constructor that sets the weapon damage and name
*/
Wand::Wand() {
    setWeaponDamage(75);
    setWeaponName("Wand");
}
/**wand constructor that sets the name, color,
and damage

@param name - name of wand
@param color - color of wand
@param dmg - damage of wand
*/
Wand::Wand(const string name, const string color, const int dmg) {
    this->name = name;
    this->color = color;
    damage = dmg;
}
/**wand deconstructor
*/
Wand::~Wand() {}; //destructor
 /**
  sets the color of the wand

  @param color - takes in new color value
*/
void Wand::setWandColor(const string col) {
    this->color = col;
}
/**
 gets the color of the wand

 @return color - current color of wand
*/
string Wand::getWandColor() {
    return color;
}
/**method that allows you to set the name of the wand

@param name - will take in the new name
*/
void Wand::setWandName(string name) {
    this->name = name;
}
/**
 gets the name of the wand

 @return name - current name of weapon
*/
string Wand::getWandName() {
    return name;
}
/**
 sets the damage of the wand

 @param dmg - takes in new damage value
*/
void Wand::setDamage(int dmg) {
    damage = dmg;
}
/**
 gets the damage of the wand

 @return damage - current damage value
*/
int Wand::getDamage() {
    return damage;
}
/** prints out the name and the color of the wand
   */
void Wand::printDims() {
    std::cout << "Wand Name = " << getWandName();
    std::cout << "Wand Color = " << getWandColor();
}