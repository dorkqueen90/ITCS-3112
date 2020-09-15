/**  This is the Ellipse class, implementing all the constructors and methods contained in Ellipse header file.
    Derived from circle, has an additional dimension; the two dimension represent the major and minor axes of the ellipse. 
    Area is Pi*major-axis*minor axis
*/
#define _USE_MATH_DEFINES

#include "Ellipse.h"
#include "Circle.h"
#include "Shape.h"
#include "math.h"

using namespace std;
    //sets default color to none
    string ellipseColor = "none";
    /**
    default constructor initialized; sets name of shape
    */
    Ellipse::Ellipse() { setName("Ellipse"); };  
    /**
    constructor with axis' initialized; sets name of shape, sets axis
    calls method to calculate area using the major and minor axis

    @param major - major axis of shape given by user
    @param minor - minor axis of shape given by user
    */
    Ellipse::Ellipse(int major, int minor) {
        thisMajor = major;
        thisMinor = minor;
        calculateArea(thisMajor, thisMinor);
        setName("Ellipse");
        ellipseColor = "none";
    };
    /**
    constructor with axis' initialized; sets name of shape, sets axis
    calls method to calculate area using the major and minor axis
    updates current shape's color

    @param major - major axis of shape given by user
    @param minor - minor axis of shape given by user
    @param color - color given by user
    */
    Ellipse::Ellipse(int major, int minor, string color) {
        thisMajor = major;
        thisMinor = minor;
        ellipseColor = color;
        calculateArea(thisMajor, thisMinor);
        setName("Ellipse");
    };
    /**
    destructor initialized
    */
    Ellipse::~Ellipse() {};    
    /**
    method to print the dimensions, using getName() getArea() getVolume() & the current color
    */
    void Ellipse::printDims() {
        cout << "\nName: " << getName() << "\nArea: " << getArea() << "\nVolume: " << getVolume() << "\nColor: " << ellipseColor << "\n";
    };
    /**
    method used to calculate area given the major and minor axis
    updates area

    @param thisMajor - major axis given by user
    @param thisMinor - minor axis given by user
    */
    void Ellipse::calculateArea(int thisMajor, int thisMinor) {
        thisArea = (M_PI * thisMajor * thisMinor);
    }
    /**
    method used to retrieve the area

    @return thisArea - returns the area
    */
    float Ellipse::getArea() const{
        return thisArea;
    };
    /**
    method used to retrieve the volume

    @return 0 - returns 0 for volume
    */
    float Ellipse::getVolume() const {
        return 0;
    };
    /**
    method to set the dimensions of the shape
    updates the current dimensions

    @param major - major axis given by user
    @param minor - minor axis given by user
    */
    void Ellipse::setDims(int major, int minor) {
        thisMajor = major;
        thisMajor = minor;
    };
