//header file for image, containing the class declarations
#pragma once
#include "Bridges.h"
#include "Color.h"
#include "ColorGrid.h"
#include <vector>

using namespace bridges;
using namespace std;

class Image {
    private:
        // image dimensions
        unsigned int width, height;
        int highestNum;
        string filename;
        //struct to hold the rgb values of each index
        struct RGB {
            unsigned char R = 0;
            unsigned char G = 0;
            unsigned char B = 0;
        };
        vector<RGB> pixels; //the stored values in a vector

    public:
        Image();     // constructor - creates an empty image object,
                     // creates an image object by reading the input file
        Image(string filename);
        //creates an image object using the given dimensions
        Image(int col, int row);
        ~Image();    // destructor  - provide as many destructors as needed

                     // accessors/mutators
        int getWidth();
        void setWidth(int w);
        int getHeight();
        void setHeight(int h);
        void setFilename(string filename);

        //gets the rgb values at the specified pixel location, using width and height
        RGB& get(unsigned int a, unsigned int b);

        // reads an image from  the given input image file
        void read(string infile);

        // takes in the image and displays it using
        // the color grid
        void display(ColorGrid* cg);

        // Converts RGB to grayscale 
        void toGrayScale(ColorGrid* cg);

        // flips the image  horizontally each row of pixels
        void flipHorizontal(ColorGrid* cg);

        // blend an incoming image and the existing image
        // by a given blend factor (0-1.0 range)
        void blend(ColorGrid* cg, Image img2, double blendFactor);

        // flips the red component of image about 255
        void negateRed(ColorGrid* cg);
};