/**This is the Sword cpp file, implementing everything from the sword header file.
Only the warrior will be using this.
*/
#include <iostream>
#include "Sword.h"

using namespace std;

/**sword default constructor that sets weapon damage and name
*/
Sword::Sword() {
    setWeaponDamage(50);
    setWeaponName("Sword");
}
/**sword constructor that sets the name, color,
and damage

@param name - name of sword
@param color - color of sword
@param dmg - damage of sword
*/
Sword::Sword(const string name, const string color, const int dmg) {
    this->name = name;
    this->color = color;
    damage = dmg;
}
/**sword deconstructor
*/
Sword::~Sword() {}; //destructor
/**
  sets the color of the sword

  @param color - takes in new color value
*/
void Sword::setSwordColor(const string col) {
    this->color = col;
}
/**
 gets the color of the sword

 @return color - current color of sword
*/
string Sword::getSwordColor() {
    return color;
}
/**method that allows you to set the name of the sword

@param name - will take in the new name
*/
void Sword::setSwordName(string name) {
    this->name = name;
}
/**
 gets the name of the sword

 @return name - current name of weapon
*/
string Sword::getSwordName() {
    return name;
}
/**
 sets the damage of the sword

 @param dmg - takes in new damage value
*/
void Sword::setDamage(int dmg) {
    dmg = damage;
}
/**
 gets the damage of the sword

 @return damage - current damage value
*/
int Sword::getDamage() {
    return damage;
}
/** prints out the name and the color of the wand
    */
void Sword::printDims() {
    std::cout << "Sword Name = " << getSwordName();
    std::cout << "Sword strength = " << getDamage();
}
