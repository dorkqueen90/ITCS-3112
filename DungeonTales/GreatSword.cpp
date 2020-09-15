/**This is the GreatSword cpp file, inplementing everything from the GreatSword header file.
Only the warrior will be using this.
*/
#include "GreatSword.h"
#include <iostream>
#include "Sword.h"

using namespace std;

/**greatsword constructor that sets the beginning weapon damage and weapon name
*/
GreatSword::GreatSword() {
    setWeaponDamage(100);
    setWeaponName("GreatSword");
}
/**greatsword constructor that sets the damage

@param dmg - new damage value for the greatsword
*/
GreatSword::GreatSword(int dmg) {
    dmg = damage;
}
/**sword deconstructor
*/
GreatSword::~GreatSword() {};
/**
  sets the color of the Great Sword

  @param color - new color of the sword
*/
void GreatSword::setGreatSwordColor(string color) {
    this->color = color;
}
/**
 gets the color of the Great Sword

 @return color - current color of the sword
*/
string GreatSword::getGreatSwordColor() {
    return color;
}
/**
 sets the name of the Great Sword

 @param name - new name value
*/
void GreatSword::setGreatSwordName(string name) {
    this->name = name;
}
/**
 gets the name of the Great Sword

 @return name - current name of the sword
*/
string GreatSword::getGreatSwordName() {
    return name;
}
/**
 gets the damage of the Great Sword

 @return damage - current damage of the sword
*/
int GreatSword::getGreatSwordDamage() {
    return damage;
}
/**
 sets the strength of the Great Sword

 @param strength - new strength value for the sword
*/
void GreatSword::setGreatSwordDamage(int dmg) {
    dmg = damage;
}
/**
Override the print virtual function in Sword.h
*/
void GreatSword::printDims() {
    std::cout << "Great Sword Name = " << getGreatSwordName();
    std::cout << "Great Sword Damage = " << getDamage();
}