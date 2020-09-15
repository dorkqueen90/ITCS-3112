/* KdTree_Images.cpp : This file contains the 'main' function. Program execution begins and ends there.
@author Amber Sibel
@date 3/21/20
This program is intended to read in a ppm image, display it, then partition it and show the image again with the partitioning lines.
*/

#include <iostream>
#include <string>
#include "Image.h"
#include "Bridges.h"
#include "Color.h"
#include "ColorGrid.h"
#include "KdTreeElement.h"

using namespace bridges;
using namespace std;

int main()
{
    // create Bridges object
    Bridges bridges(6.2, "ambersibel",
        "59807219965");
    //reading in string, using correct file location
    string filename = "C:\\Users\\Amber\\Downloads\\mickey_mouse.ppm";

    //implement constructors
    Image image(filename); //reads in filename

    int width = image.getWidth(), height = image.getHeight();
    Color baseColor = Color("white");
    //create colorgrid
    ColorGrid* cg = new ColorGrid(height, width, baseColor);
    //start calling the different method processes on the image
    image.display(cg);

    bridges.setDataStructure(cg);
    //the original image
    bridges.visualize();
    //call the insert method on the image
    image.buildImageTree(cg);
    //visualize after partitioning
    bridges.visualize();
}

/*     Unfortunaley I ran out of time. I have made all the necessary methods and spent days debugging.
       However, my partitioning is not quite right; it almost looks like it's leaving out the right child,
       but I can't find evidence of this. I've also tried using both homogeneous methods, while debugging
       through both, and neither seem to be working to guide the partitioning lines. Truely sorry, will
       manage my time better for the next one.
*/