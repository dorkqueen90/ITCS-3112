/* Image_Fun.cpp : This file contains the 'main' function. Program execution begins and ends there
    @author Amber Sibel
    @date   2/20/20
    Class assignment for 3112, program runs multiple processes on an image
    All processes are visualized on bridges website
*/  

#include <iostream>
#include <string>
#include "Image.h"
#include "Bridges.h"
#include "Color.h"
#include "ColorGrid.h"

using namespace bridges;
using namespace std;

int main()
{
    // create Bridges object
    Bridges bridges(4, "ambersibel",
        "59807219965");
    //reading in string, using correct file location
    string filename = "C:\\Users\\Amber\\Downloads\\yosemite.ppm";
    string filename2 = "C:\\Users\\Amber\\Downloads\\Lenna.ppm";

    //implement constructors
    Image image1(filename); //reads in filename
    Image image2(filename2);
    
    int width = image1.getWidth(), height = image1.getHeight();
    Color baseColor = Color("white");
    //create colorgrid
    ColorGrid* cg = new ColorGrid(height, width, baseColor);
    //start calling the different method processes on the image
    image1.display(cg);

    bridges.setDataStructure(cg);
    //visualize after every method call to see new image
    bridges.visualize();

    image1.toGrayScale(cg);

    bridges.visualize();

    image1.flipHorizontal(cg);

    bridges.visualize();

    image1.blend(cg, image2, 0.4);

    bridges.visualize();

    image1.negateRed(cg);

    bridges.visualize();

}