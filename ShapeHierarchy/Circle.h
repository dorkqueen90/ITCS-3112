/**  This is the Circle class header file, declaring all private variables and all public methods
     Derived from Shape, has a single dimension representing its radius.
*/
#pragma once
#include <iostream>
#include "Shape.h"

using namespace std;

class Circle : public Shape {

private:

    int thisRadius;
    float thisArea = 0;

public:
    Circle();  // constructor
    Circle(int radius);
    Circle(int radius, string color);
    ~Circle();    // destructor

    void printDims();

    void calculateArea(int radius);

    float Shape::getArea() const;

    float Shape::getVolume() const;

    void setDims(int radius);
};