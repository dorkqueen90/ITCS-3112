//image class with the implementations from the header file
//contains all methods for manipulating the images
#include <iostream>
#include <fstream>
#include <vector>
#include "Image.h"
#include "Bridges.h"
#include "Color.h"
#include "ColorGrid.h"

using namespace std;
using namespace bridges;

//implementations to constructors
Image::Image() { };

Image::Image(string filename) {
    setFilename(filename);
    read(filename);
}

Image::Image(int col, int row) {
    read(filename);
}
//implementing destructor
Image::~Image() {};

//implementations to accessors/mutators 
void Image::setWidth(int w) {
    Image::width = w;
}

void Image::setHeight(int h) {
    Image::height = h;
}

void Image::setFilename(string f) {
    Image::filename = f;
}

int Image::getHeight() {
    return Image::height;
}

int Image::getWidth() {
    return Image::width;
}

// reads an image from  the given input image file
void Image::read(string filename) {

    RGB tmp;
    string _R, _G, _B;
    ifstream fp(filename);
    string magicNum;
    fp >> magicNum;
    fp >> width >> height >> highestNum;

    for (unsigned int i = 0; i < width * height; i++) {
        fp >> _R >> _G >> _B;
        tmp.R = atoi(_R.c_str());
        tmp.G = atoi(_G.c_str());
        tmp.B = atoi(_B.c_str());

        pixels.push_back(tmp);
    }
    fp.close();
}

//gets the rgb values at the specified pixel location, using width and height
Image::RGB& Image::get(unsigned int h, unsigned int w) {
    return pixels[(h * width) + w];
}

// takes in the image and displays it using ColorGrid
void Image::display(ColorGrid* cg) {
    int r, g, b;
    for (int i = 0; i < height; i++) {
        for (int j = 0; j < width; j++) {
            RGB& color = get(i, j);
            r = (int)color.R;
            g = (int)color.G;
            b = (int)color.B;
            cg->set(i, j, Color(r, g, b));
        }
    }
}

// Converts RGB to grayscale
void Image::toGrayScale(ColorGrid* cg) {
    int r, g, b, grey;
    for (int i = 0; i < height; i++) {
        for (int j = 0; j < width; j++) {
            RGB& color = get(i, j);
            r = (int)color.R;
            g = (int)color.G;
            b = (int)color.B;
            grey = r * 0.299 + g * 0.587 + 0.114 * b;
            cg->set(i, j, Color(grey, grey, grey));
        }
    }
}

// flips the image  horizontally each row of pixels
void Image::flipHorizontal(ColorGrid* cg) {
    for (int i = 0; i < height-1; i++) {
        for (int j = 0; j < width/2; j++) {

            RGB& position = get(i, j);
            RGB& rightPosition = get(i, width - j);
            RGB temp = position;
            position = rightPosition;
            rightPosition = temp;
        }
    }
    display(cg);
}

// blend an incoming image and the existing image
// by a given blend factor (0-1.0 range)
void Image::blend(ColorGrid* cg, Image img2, double blendFactor) {
    //assume img2 size < this.image size
    //center img2 and blend with this.image
    int centeredHeight = (height-img2.height)/2;
    int centeredWidth = (width-img2.width)/2;

    int r, g, b, thisR, thisG, thisB, img2R, img2G, img2B;
 
    for (int i = 0; i < img2.height; i++) {
        for (int j = 0; j < img2.width; j++) {
            RGB& color = get(i+ centeredHeight, j+ centeredWidth);
            thisR = (int)color.R;
            thisG = (int)color.G;
            thisB = (int)color.B;
            RGB& colorTwo = img2.get(i, j);
            img2R = (int)colorTwo.R;
            img2G = (int)colorTwo.G;
            img2B = (int)colorTwo.B;
            r = blendFactor * thisR + (1. - blendFactor) * img2R;
            g = blendFactor * thisG + (1. - blendFactor) * img2G;
            b = blendFactor * thisB + (1. - blendFactor) * img2B;
            cg->set(i+ centeredHeight, j+ centeredWidth, Color(r, g, b));
        }
    }
}

//flips the red component of image about 255
void Image::negateRed(ColorGrid* cg) {
    int r, g, b;
    for (int i = 0; i < height; i++) {
        for (int j = 0; j < width; j++) {
            RGB& color = get(i, j);
            r = 255 - (int)(color.R);
            g = (int)color.G;
            b = (int)color.B;
            cg->set(i, j, Color(r, g, b));
        }
    }
}
