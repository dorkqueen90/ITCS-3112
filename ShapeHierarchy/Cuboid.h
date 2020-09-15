/**  This is the Cuboid class header file, declaring all private variables and all public methods
     Derived from Rectangle.
     3D equivalent of a rectangle, adds a depth dimensionand defines area(surface area) and a volume
*/
#pragma once
#include "Cube.h"
#include "Rectangle.h"
#include "Square.h"
#include "Shape.h"

using namespace std;

class Cuboid : public Rectangle {

private:

    int thisLength, thisWidth, thisHeight;
    float thisArea = 0, thisVolume = 0;

public:
    Cuboid();  // constructor
    Cuboid(int length, int width, int height);
    ~Cuboid();    // destructor

    void printDims();

    void calculateArea(int thisLength, int thisWidth, int thisHeight);

    void calculateVolume(int thisLength, int thisWidth, int thisHeight);

    float Shape::getArea() const;

    float Shape::getVolume() const;

    void setDims(int length, int width, int height);
};