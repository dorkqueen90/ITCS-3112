/**  This is the abstract class declarations for Shape
     Declaring all protected variables & public methods needed
*/
#pragma once

using namespace std;
// pure abstract class
class Shape {      

protected:
    // color of shape
    string thisColor;         
    // shape name ("Square", "Rectangle",  etc.)
    string thisName;        

public:
    Shape();  // constructor
    Shape(const string name, const string col);

    ~Shape();   // destructor

    // set color of shape
    void setColor(string col);    
    // get color of shape
    string getColor();                

    // set name of shape
    void   setName(string col);  
    // get name of shape
    string getName();               


    // prints the shape's  name, area, volume and color
    virtual void printDims();      

                                             
    // get shape dimensions
    virtual float  getArea() const = 0;
    virtual float  getVolume() const = 0;
};
