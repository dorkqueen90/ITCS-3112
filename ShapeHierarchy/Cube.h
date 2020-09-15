/**  This is the Cube class header file, declaring all private variables and all public methods
     Derived from Square. 3D equivalent of a square.  Adds a third dimension. Area and volume are defined
*/
#pragma once
#include "Square.h"
#include "Shape.h"

using namespace std;

class Cube : public Square {

private:

    int thisLength = 0;
    float thisArea = 0, thisVolume = 0;

public:
    Cube();  // constructor
    Cube(int length);
    Cube(int length, string color);
    ~Cube();    // destructor

    void printDims();

    void calculateArea(int length);
    void calculateVolume(int length);

    float Shape::getArea() const;
    float Shape::getVolume() const;

    void setDims(int length);
};