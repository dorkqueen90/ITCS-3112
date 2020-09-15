/**  This is the Cube class, implementing all the constructors and methods contained in Cube header file.
    3D equivalent of a square.  Adds a third dimension. Area and volume are defined
*/
#include "Cube.h"
#include "Square.h"
#include "Shape.h"
#include "math.h"
#include <iostream>

using namespace std;
    //sets default color to none
    string cubeColor = "none";
    /**
    default constructor initialized; sets name of shape
    */
    Cube::Cube() { setName("Cube"); };  
    /**
    constructor with length initialized; sets name of shape, sets length
    calls method to calculate area using length
    calls method to calculate volume using length

    @param length - length of shape given by user
    */
    Cube::Cube(int length) {
        thisLength = length;
        calculateArea(thisLength);
        calculateVolume(thisLength);
        setName("Cube");
        cubeColor = "none";
    };
    /**
    constructor with length initialized; sets name of shape, sets length
    calls method to calculate area using length
    calls method to calculate volume using length
    updates color of shape

    @param length - length of shape given by user
    @param color - color of shape given by user
    */
    Cube::Cube(int length, string color) {
        thisLength = length;
        cubeColor = color;
        calculateArea(thisLength);
        calculateVolume(thisLength);
        setName("Cube");
    };
    /**
    destructor initialized
    */
    Cube::~Cube() {};    
    /**
    method to print the dimensions, using getName() getArea() getVolume() & current color
    */
    void Cube::printDims() {
        cout << "\nName: " << getName() << "\nArea: " << getArea() << "\nVolume: " << getVolume() << "\nColor: " << cubeColor << "\n";
    };
    /**
    method used to calculate area given the length
    updates area

    @param thisLength - length given by user
    */
    void Cube::calculateArea(int thisLength) {
        thisArea = 6 * pow(thisLength, 2);
    }/**
    method used to calculate volume given the length
    updates volume

    @param thisLength - length given by user
    */
    void Cube::calculateVolume(int thisLength) {
        thisVolume = pow(thisLength, 3);
    }
    /**
    method used to retrieve the area

    @return thisArea - returns the area
    */
    float Cube::getArea() const {
        return thisArea;
    };
    /**
    method used to retrieve the volume

    @return thisVolume - returns the volume
    */
    float Cube::getVolume() const {
        return thisVolume;
    };
    /**
    method to set the dimensions of the shape
    updates the current dimensions

    @param length - length given by user
    */
    void Cube::setDims(int length) {
        thisLength = length;
    };
