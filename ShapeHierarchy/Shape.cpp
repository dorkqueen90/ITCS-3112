/**  This is the abstract class implementations
     Implementing all the constructors and methods contained in Shape header file. 
*/
#include <iostream>
#include "Shape.h"
#include <iostream>
using namespace std;   

    /**
    default constructor initialized; sets name of shape
    */
    Shape::Shape() {};  
    /**
    constructor with name & color initialized
    updates name and color

    @param length - length of shape given by user
    */
    Shape::Shape(const string name, const string col) {
        thisColor = col;
        thisName = name;
    };
    /**
    destructor initialized
    */
    Shape::~Shape() {};   // destructor

    /**
    method to set the color of the shape
    updates thisColor

    @param col - color given by user
    */
    void Shape::setColor(string col) {
        thisColor = col;
    };    
    /**
    method used to retrieve the color of the shape

    @return thisColor - returns the color
    */
    string Shape::getColor() {
        return thisColor;
    };               

    /**
    method to set the name of the shape
    updates thisName

    @param name - name given by user
    */
    void   Shape::setName(string name) {
        thisName = name;
    };  
    /**
    method used to retrieve the name

    @return thisName - returns the name
    */
    string Shape::getName() {
        return thisName;
    };               
    /**
    method to print the dimensions, using getName() getArea() getVolume() & getColor()
    */
    void Shape::printDims() {
        cout << "\nName: " << getName() << "\nArea: " << getArea() << "\nVolume: " << getVolume() << "\nColor: " << getColor() << "\n";
    };      

                                             
    /**
    method used to retrieve the area

    @return 0 - for initializing purposes
    */
    float  Shape::getArea() const { return 0; };
    /**
    method used to retrieve the volume

    @return 0 - for initializing purposes
    */
    float  Shape::getVolume() const { return 0; };
