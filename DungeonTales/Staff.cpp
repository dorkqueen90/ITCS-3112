/**This is the Staff cpp file, implementing everything from the staff header file.
Only the mage will be using this.
*/
#include "Staff.h"
#include <iostream>
#include "Wand.h"

using namespace std;

/**staff constructor that sets the weapon damage and name
*/
Staff::Staff() {
    setWeaponDamage(150);
    setWeaponName("Staff");
}
/**staff constructor that takes in a new damage value

@param dmg - takes in a new damage value and updates it
*/
Staff::Staff(int dmg) {
    dmg = damage;
}
/**staff deconstructor
*/
Staff::~Staff() {};
/**
  sets the color of the Staff

  @param color - takes in new color
*/
void Staff::setStaffColor(string color) {
    this->color = color;
}
/**
 gets the color of the Staff

 @return color - returns current color
*/
string Staff::getStaffColor() {
    return color;
}
/**
 sets the name of the Staff

 @param name - takes in new name of weapon
*/
void Staff::setStaffName(string name) {
    this->name = name;
}
/**
 gets the name of the Staff

 @return name - current name of weapon
*/
string Staff::getStaffName() {
    return name;
}
/**
 gets the damage of the Staff

 @return damage - current damage of staff
*/
int Staff::getStaffDamage() {
    return damage;
}
/**
 sets the damage of the Staff

 @param dmg - takes in new damage value
*/
void Staff::setStaffDamage(int dmg) {
    dmg = damage;
}
/**
Override the print virtual function in Wand.h
*/
void Staff::printDims() {
    std::cout << "Staff Name = " << getStaffName();
    std::cout << "Staff Damage = " << getStaffDamage();
}