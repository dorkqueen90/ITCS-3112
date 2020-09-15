/**  This is the Rectangle class header file, declaring all private variables and all public methods
     Derived from Square, has also a second coordinate that represents its width
*/
#pragma once
#include "Square.h"
#include "Shape.h"

using namespace std;

class Rectangle : public Square {

private:

    int thisLength, thisWidth;
    float thisArea = 0;

public:
    Rectangle();  // constructor
    Rectangle(int length, int width);
    ~Rectangle();    // destructor

    void printDims();

    void calculateArea(int length, int width);

    float Shape::getArea() const;

    float Shape::getVolume() const;

    void setDims(int length, int width);
};