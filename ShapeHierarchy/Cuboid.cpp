/*  This is the Cuboid class, implementing all the constructors and methods contained in Cuboid header file.
    3D equivalent of a rectangle, adds a depth dimensionand defines area(surface area) and a volume
**/
#include "Cuboid.h"
#include "Rectangle.h"
#include "Square.h"
#include "Shape.h"
#include <iostream>

using namespace std;
    /**
    default constructor initialized; sets name of shape
    */
    Cuboid::Cuboid() { setName("Cuboid"); };  
    /**
    constructor with length, width, height initialized; sets name of shape
    updates length, width, height
    calls method to calculate area using length, width, height
    calls method to calculate volume using length, width, height

    @param length - length of shape given by user
    @param width - width of shape given by user
    @param height - height of shape given by user
    */
    Cuboid::Cuboid(int length, int width, int height) {
        thisLength = length;
        thisWidth = width;
        thisHeight = height;
        calculateArea(thisLength, thisWidth, thisHeight);
        calculateVolume(thisLength, thisWidth, thisHeight);
        setName("Cuboid");
    };
    /**
    destructor initialized
    */
    Cuboid::~Cuboid() {};    
    /**
    method to print the dimensions, using getName() getArea() getVolume() & getColor()
    */
    void Cuboid::printDims() {
        cout << "\nName: " << getName() << "\nArea: " << getArea() << "\nVolume: " << getVolume() << "\nColor: " << getColor() << "\n";
    };
    /**
    method used to calculate area given the length, width, height
    updates area

    @param thisLength - length given by user
    @param thisWidth - width given by user
    @param thisHeight - height given by user
    */
    void Cuboid::calculateArea(int thisLength, int thisWidth, int thisHeight) {
        thisArea = 2 * (thisLength * thisWidth + thisWidth * thisHeight + thisHeight * thisLength);
    }
    /**
    method used to calculate volume given the length, width, height
    updates volume

    @param thisLength - length given by user
    @param thisWidth - width given by user
    @param thisHeight - height axis given by user
    */
    void Cuboid::calculateVolume(int thisLength, int thisWidth, int thisHeight) {
        thisVolume = thisLength * thisWidth * thisHeight;
    }
    /**
    method used to retrieve the area

    @return thisArea - returns the area
    */
    float Cuboid::getArea() const{
        return thisArea;
    };
    /**
    method used to retrieve the volume

    @return thisVolume - returns the volume
    */
    float Cuboid::getVolume() const{
        return thisVolume;
    };
    /**
    method to set the dimensions of the shape
    updates the current dimensions

    @param length - length given by user
    @param width - width given by user
    @param height - height given by user
    */
    void Cuboid::setDims(int length, int width, int height) {
        thisLength = length;
        thisWidth = width;
        thisHeight = height;
    };
