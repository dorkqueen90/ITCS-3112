/**  This is the Ellipsoid class header file, declaring all private variables and all public methods
     Derived from Ellipse.
*/
#pragma once
#include <iostream>
#include "Ellipse.h"
#include "Circle.h"
#include "Shape.h"

using namespace std;

class Ellipsoid : public Ellipse {

private:

    int axisA, axisB, axisC;
    float thisVolume = 0;

public:
    Ellipsoid();  // constructor
    Ellipsoid(int axis1, int axis2, int axis3);
    Ellipsoid(int axis1, int axis2, int axis3, string color);
    ~Ellipsoid();    // destructor

    void printDims();

    void calculateVolume(int axis1, int axis2, int axis3);

    float Shape::getVolume() const;

    float Shape::getArea() const;

    void setDims(int axis1, int axis2, int axis3);
};