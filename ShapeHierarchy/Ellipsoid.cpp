/**  This is the Ellipsoid class, implementing all the constructors and methods contained in Ellipsoid header file.
    3D equivalent of an ellipse. Volume = (4/3)* Pi*a*b*c, where a, b, c represent the 3 axes of the ellipsoid. 
    Ignoring area and returning 0, as the formula is complicated
*/
#define _USE_MATH_DEFINES

#include "Ellipsoid.h"
#include "Ellipse.h"
#include "Circle.h"
#include "Shape.h"
#include <math.h>

using namespace std;
    //sets default color to none
    string ellipsoidColor = "none";
    /**
    default constructor initialized; sets name of shape
    */
    Ellipsoid::Ellipsoid() { setName("Ellipsoid"); };  
    /**
    constructor with axis' initialized; sets name of shape, sets axis'
    calls method to calculate volume using the three axis'

    @param axis1 - first axis of shape given by user
    @param axis2 - second axis of shape given by user
    @param axis3 - third axis of shape given by user
    */
    Ellipsoid::Ellipsoid(int axis1, int axis2, int axis3) {
        axisA = axis1;
        axisB = axis2;
        axisC = axis3;
        calculateVolume(axisA, axisB, axisC);
        setName("Ellipsoid");
        ellipsoidColor = "none";
    };
    /**
    constructor with axis' initialized; sets name of shape, sets axis'
    calls method to calculate volume using the three axis'
    updates current shape's color

    @param axis1 - first axis of shape given by user
    @param axis2 - second axis of shape given by user
    @param axis3 - third axis of shape given by user
    @param color - color given by user
    */
    Ellipsoid::Ellipsoid(int axis1, int axis2, int axis3, string color) {
        axisA = axis1;
        axisB = axis2;
        axisC = axis3;
        ellipsoidColor = color;
        calculateVolume(axisA, axisB, axisC);
        setName("Ellipsoid");
    };
    /**
    destructor initialized
    */
    Ellipsoid::~Ellipsoid() {};    
    /**
    method to print the dimensions, using getName() getArea() getVolume() & using the current color
    */
    void Ellipsoid::printDims() {
        cout << "\nName: " << getName() << "\nArea: " << getArea() << "\nVolume: " << getVolume() << "\nColor: " << ellipsoidColor << "\n";
    };
    /**
    method used to calculate volume given the 3 axis
    updates volume

    @param axisA - first axis given by user
    @param axisB - second axis given by user
    @param axisC - third axis given by user
    */
    void Ellipsoid::calculateVolume(int axisA, int axisB, int axisC) {
        thisVolume = (4 / 3) * M_PI * axisA * axisB * axisC;
    }
    /**
    method used to retrieve the volume

    @return thisVolume - returns the volume
    */
    float Ellipsoid::getVolume() const {
        return thisVolume;
    };
    /**
    method used to retrieve the area

    @return 0 - returning 0 for the area as per instructions
    */
    float Ellipsoid::getArea() const {
        return 0;
    };
    /**
    method to set the dimensions of the shape
    updates the current dimensions

    @param axis1 - first axis given by user
    @param axis2 - second axis given by user
    @param axis3 - third axis given by user
    */
    void Ellipsoid::setDims(int axis1, int axis2, int axis3) {
        axisA = axis1;
        axisB = axis2;
        axisC = axis3;
    };
