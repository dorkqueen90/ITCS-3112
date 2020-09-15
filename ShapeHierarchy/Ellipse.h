/**  This is the Ellipse class header file, declaring all private variables and all public methods
     Derived from circle, has an additional dimension;
*/
#pragma once
#include <iostream>
#include "Circle.h"
#include "Shape.h"

using namespace std;

class Ellipse : public Circle {

private:

    int thisMajor, thisMinor;
    float thisArea = 0;

public:
    Ellipse();  // constructor
    Ellipse(int major, int minor);
    Ellipse(int major, int minor, string color);
    ~Ellipse();    // destructor

    void printDims();

    void calculateArea(int major, int minor);

    float Shape::getArea() const;

    float Shape::getVolume() const;

    void setDims(int major, int minor);
};