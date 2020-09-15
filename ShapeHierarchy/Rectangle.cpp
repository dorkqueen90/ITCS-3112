/**  This is the Rectangle class, implementing all the constructors and methods contained in rectangle header file.
    Derived from Square, has also a second coordinate that represents its width
*/
#include "Rectangle.h"
#include "Square.h"
#include "Shape.h"
#include <iostream>

using namespace std;
    /**
    default constructor initialized; sets name of shape
    */
    Rectangle::Rectangle() { setName("Rectangle"); };  
    /**
    constructor with length & width initialized; sets name of shape, sets length & width
    calls method to calculate area using length & width

    @param length - length of shape given by user
    @param width - width of shape given by user
    */
    Rectangle::Rectangle(int length, int width) {
        thisLength = length;
        thisWidth = width;
        calculateArea(thisLength, thisWidth);
        setName("Rectangle");
    };
    /**
    destructor initialized
    */
    Rectangle::~Rectangle() {};    
    /**
    method to print the dimensions, using getName() getArea() getVolume() & getColor()
    */
    void Rectangle::printDims() {
        cout << "\nName: " << getName() << "\nArea: " << getArea() << "\nVolume: " << getVolume() << "\nColor: " << getColor() << "\n";
    };
    /**
    method used to calculate area given the length & width
    updates area

    @param length - length given by user
    @param width - width given by user
    */
    void Rectangle::calculateArea(int length, int width) {
        thisArea = width * length;
    }
    /**
    method used to retrieve the area

    @return thisArea - returns the area
    */
    float Rectangle::getArea() const{
        return thisArea;
    };
    /**
    method used to retrieve the volume

    @return 0 - returns 0 for volume
    */
    float Rectangle::getVolume() const {
        return 0;
    };
    /**
    method to set the dimensions of the shape
    updates the current dimensions

    @param length - length given by user
    @param width - width given by user
    */
    void Rectangle::setDims(int length, int width) {
        thisLength = length;
        thisWidth = width;
    };
