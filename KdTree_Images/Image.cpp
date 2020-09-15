//image class with the implementations from the header file
//contains all methods to take in image and start partitioning it
#include <iostream>
#include <fstream>
#include <vector>
#include "Image.h"
#include "Bridges.h"
#include "Color.h"
#include "ColorGrid.h"
#include "KdTreeElement.h"

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
//constructor for main to send in
KdTreeElement<int, int>* Image::buildImageTree(ColorGrid* cg) {
    reg region{ 0, getWidth(), 0, getHeight() };
    regions.push_back(region);
    buildImageTree(region, 0, cg, dim_flag);

    return nullptr;
}
//insert method to build the tree
KdTreeElement<int, int>* Image::buildImageTree(reg region, int level, ColorGrid* cg, bool dim_flag) {
    int count;
    //create tree element
    if (dim_flag) {
        count = 0; //x
    }
    else {
        count = 1;
    }
       
    root = new KdTreeElement<int, int>(regions.size()+1, count);
    
    if (level == maxLevel) {
        return nullptr;
    }
    else {
        reg rootRegion = region;
        //check region homogeneity
        bool homogeneous = IsRegionHomogeneous(region, cg);

        if (!homogeneous) {
            level++;
            //check dim flag/partition on X or Y
            if (dim_flag) {
                //x
                reg leftRegion{ rootRegion.xmin, (rootRegion.xmax / 2), rootRegion.ymin, rootRegion.ymax };
                regions.push_back(leftRegion);
                colorPartition(leftRegion, cg);
                root->setLeft(buildImageTree(leftRegion, level, cg, !dim_flag));

                reg rightRegion{ (rootRegion.xmax / 2), rootRegion.xmax, rootRegion.ymin, rootRegion.ymax };
                regions.push_back(rightRegion);
                colorPartition(rightRegion, cg);
                root->setRight(buildImageTree(rightRegion, level, cg, !dim_flag));
            }
            else {
                //y
                reg topRegion{ rootRegion.xmin, rootRegion.xmax, rootRegion.ymin, (rootRegion.ymax / 2) };
                regions.push_back(topRegion);
                colorPartition(topRegion, cg);
                root->setLeft(buildImageTree(topRegion, level, cg, !dim_flag));

                reg bottomRegion{ rootRegion.xmin, rootRegion.xmax, (rootRegion.ymax / 2), rootRegion.ymax };
                regions.push_back(bottomRegion);
                colorPartition(bottomRegion, cg);
                root->setRight(buildImageTree(bottomRegion, level, cg, !dim_flag));
            }
            
            return root;
        }
        colorRegion(region, cg);
        return nullptr;
    }
} 
//testing to see if the region is homogeneous
bool Image::IsRegionHomogeneous(reg region, ColorGrid* cg) {
    //sum up pixel colors
    int counter = 1;
    int r, g, b;
    for (int i = region.ymin + 1; i <= region.ymax - 1; i++) {
        for (int j = region.xmin + 1; j <= region.xmax - 1; j++) {
            RGB& color = get(i, j);
            r = (int)color.R;
            g = (int)color.G;
            b = (int)color.B;
            avgR += r;
            avgG += g;
            avgB += b;
            counter++;
        }
    } //find average for each r, g, & b values for region
    avgR = avgR / counter -1;
    avgG = avgG / counter -1;
    avgB = avgB / counter -1;
    //iterate through region pixels and compare to 
    //if above/below 10 not homogeneous/false, else true
    for (int i = region.ymin + 1; i < region.ymax - 1; i++) {
        for (int j = region.xmin + 1; j < region.xmax - 1; j++) {
            RGB& color = get(i, j);
            r = (int)color.R;
            g = (int)color.G;
            b = (int)color.B;
            if (r < (avgR-10) || r > (avgR+10)) {
                return false;
            }
            if (g < (avgG - 10) || g > (avgG + 10)) {
                return false;
            }
            if (b < (avgB - 10) || b > (avgB + 10)) {
                return false;
            }
        }
    }
    return true;
}
//colors the region partitioned using the colorgrid
void Image::colorPartition(reg region, ColorGrid* cg) {
    for (int i = region.xmin; i < region.xmax; i++) {
        cg->set(region.ymin, i, Color("turquoise"));
        cg->set(region.ymax -1, i, Color("turquoise"));
    }
    for (int j = region.ymin; j < region.ymax; j++) {
        cg->set(j, region.xmin, Color("turquoise"));
        cg->set(j, region.xmax - 1,  Color("turquoise"));
    }
}
//simple method to test if region is homogeneous regarding a 2-color image
bool Image::simpleHomogeneous(reg region, ColorGrid* cg) {

    int r, g, b, r2, g2, b2;
    RGB& color1 = get(region.ymin + 1, region.xmin + 1);
    r = (int)color1.R;
    g = (int)color1.G;
    b = (int)color1.B; 

    //iterate through region pixels and compare 
    for (int i = region.ymin + 1; i < region.ymax - 1; i++) {
        for (int j = region.xmin + 1; j < region.xmax - 1; j++) {
            RGB& color2 = get(i, j);
            r2 = (int)color2.R;
            g2 = (int)color2.G;
            b2 = (int)color2.B;

            if (r != r2) {
                return false;
            }
            if (g != g2) {
                return false;
            }
            if (b != b2) {
                return false;
            }
        }
    }
    return true;        
}
//color the regions by the average
void Image::colorRegion(reg region, ColorGrid* cg) {
    int r, g, b;
    int counter = 1;
    for (int i = region.ymin + 1; i < region.ymax - 1; i++) {
        for (int j = region.xmin + 1; j < region.xmax - 1; j++) {
            RGB& color = get(i, j);
            r = (int)color.R;
            g = (int)color.G;
            b = (int)color.B;
            avgR += r;
            avgG += g;
            avgB += b;
            counter++;
        }
    } //find average for each r, g, & b values for region
    avgR = avgR / counter -1;
    avgG = avgG / counter -1;
    avgB = avgB / counter -1;
    for (int i = region.ymin + 1; i < region.ymax - 1; i++) {
        for (int j = region.xmin + 1; j < region.xmax - 1; j++) {
            cg->set(i, j, Color(avgR, avgG, avgB));
        }
    }
}