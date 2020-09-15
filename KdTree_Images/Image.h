//header class holding the declarations of the methods and variables needed
#pragma once
#include "Bridges.h"
#include "Color.h"
#include "ColorGrid.h"
#include <vector>
#include "KdTreeElement.h"

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
    //struct to hold the location of the regions
    struct reg {
        int xmin = 0;
        int xmax = 0;
        int ymin = 0;
        int ymax = 0;
    } ;
    vector<reg> regions;

public:
    Image();     // constructor - creates an empty image object,
                 // creates an image object by reading the input file
    Image(string filename);
    //creates an image object using the given dimensions
    Image(int col, int row);
    ~Image();    // destructor  - provide as many destructors as needed

    //int* region; //xmin, ymin, xmax, ymax
    int level = 0;  //starts at 0 for root
    int maxLevel = 10;
    bool dim_flag = false;  //partitioning dimension, flips with each level
    //average rgb values
    int avgR;
    int avgG;
    int avgB;

                 // accessors/mutators
    int getWidth();
    void setWidth(int w);
    int getHeight();
    void setHeight(int h);
    void setFilename(string filename);

    //original root declaration
    KdTreeElement<int, int>* root;

    //gets the rgb values at the specified pixel location, using width and height
    RGB& get(unsigned int a, unsigned int b);

    // reads an image from  the given input image file
    void read(string infile);

    // takes in the image and displays it using
    // the color grid
    void display(ColorGrid* cg);

    //constructor for main to send in
    KdTreeElement<int, int>* buildImageTree(ColorGrid* cg);

    //insert method to build the tree
    KdTreeElement<int, int>* buildImageTree(reg region, int level, ColorGrid* cg, bool flag);

    //testing to see if the region is homogeneous
    bool IsRegionHomogeneous(reg region, ColorGrid* cg);

    //colors the region partitioned using the colorgrid
    void colorPartition(reg region, ColorGrid* cg);

    //simple method to test if region is homogeneous regarding a 2-color image
    bool simpleHomogeneous(reg region, ColorGrid* cg);

    //color the region based on the average
    void colorRegion(reg region, ColorGrid* cg);
};