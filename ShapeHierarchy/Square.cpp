/**  This is the Square class, implementing all the constructors and methods contained in square header file.
    Derived from Shape, has a single coordinate that represents the side length
*/
#include "Square.h"
#include "Shape.h"
#include "math.h"
#include <iostream>

using namespace std;
    /**
    default constructor initialized; sets name of shape
    */
    Square::Square() { setName("Square"); }; 
    /**
    constructor with length initialized; sets name of shape, sets length
    calls method to calculate area using length

    @param length - length of shape given by user
    */
    Square::Square(int length) {
        thisLength = length;
        calculateArea(thisLength);
        setName("Square");
    };
    /**
    destructor initialized
    */
    Square::~Square() {};    
    /**
    method used to calculate area given the length
    updates area

    @param length - length given by user
    */
    void Square::calculateArea(int length) {
        thisArea = pow(length, 2);
    }
    /**
    method used to retrieve the area

    @return thisArea - returns the area
    */
    float Square::getArea() const {
        return thisArea;
    }
    /**
    method used to retrieve the volume

    @return 0 - returns 0 for volume
    */
    float Square::getVolume() const {
        return 0;
    }
    /**
    method to set the dimensions of the shape
    updates the current dimensions

    @param length - length given by user
    */
    void Square::setDims(int length) {
        thisLength = length;
    };
    /**
    method to print the dimensions, using getName() getArea() getVolume() & getColor() 
    */
    void Square::printDims() {
        cout << "\nName: " << getName() << "\nArea: " << getArea() << "\nVolume: " << 0 << "\nColor: " << getColor() << "\n";
    }
    

