/**  This is the Square class header file, declaring all private variables and all public methods
     Derived from Shape, has a single coordinate that represents the side length
*/
#pragma once
#include <iostream>
#include "Shape.h"
using namespace std;

class Square : public Shape {

private:

    int thisLength;
    float thisArea = 0;

public:
    Square();  // constructor
    Square(int length);

    ~Square();    // destructor

    void calculateArea(int length);

    void printDims();

    float Shape::getArea() const;

    float Shape::getVolume() const;

    void setDims(int length);

};