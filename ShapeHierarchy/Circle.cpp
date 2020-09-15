/*  This is the Circle class, implementing all the constructors and methods contained in Circle header file.
    Derived from Shape, has a single dimension representing its radius. Area is  Pi*radius*radius
*/
#define _USE_MATH_DEFINES

#include "Circle.h"
#include "Shape.h"
#include <iostream>
#include <math.h>

using namespace std;

   //sets default color to none
    string circleColor = "none";
    /**
    default constructor initialized; sets name of shape
    **/
    Circle::Circle() { setName("Circle"); }; 
    /**
    constructor with radius initialized; sets name of shape, sets radius
    calls method to calculate area using radius

    @param radius - radius of shape given by user
    */
    Circle::Circle(int radius) {
        thisRadius = radius;
        calculateArea(thisRadius);
        setName("Circle");
        circleColor = "none";
    };
    /**
    constructor with radius initialized; sets name of shape, sets radius
    calls method to calculate area using radius
    updates color of shape

    @param radius - radius of shape given by user
    @param color - color of shape given by user
    */
    Circle::Circle(int radius, string color) {
        thisRadius = radius;
        circleColor = color;
        calculateArea(thisRadius);
        setName("Circle");
    };
    /**
    destructor initialized
    */
    Circle::~Circle() {};   
    /**
    method to print the dimensions, using getName() getArea() getVolume() & current color
    */
    void Circle::printDims() {
        cout << "\nName: " << getName() << "\nArea: " << getArea() << "\nVolume: " << getVolume() << "\nColor: " << circleColor << "\n";
    };
    /**
    method used to calculate area given the radius
    updates area

    @param thisRadius - radius given by user
    */
    void Circle::calculateArea(int thisRadius) {
        thisArea = M_PI * pow(thisRadius, 2);
    }
    /**
    method used to retrieve the area

    @return thisArea - returns the area
    */
    float Circle::getArea() const{
        return thisArea;
    };
    /**
    method used to retrieve the volume

    @return 0 - returns 0 for volume
    */
    float Circle::getVolume() const {
        return 0;
    };
    /**
    method to set the dimensions of the shape
    updates the current dimensions

    @param radius - radius given by user
    */
    void Circle::setDims(int radius) {
        thisRadius = radius;
    };
