/*@author Amber Sibel
@date 2/5/20
This program is part of the Mountain Path assignment. It reads in elevation data from a file, uses a greedy algorithm to find
the path with the lowest elevation change, and displays the path in the image.
*/
#include <string>
#include <iostream>
#include <fstream>
#include <vector>

using namespace std;

#include "Bridges.h"
#include "Color.h"
#include "ColorGrid.h"

using namespace bridges;

int highestNum; //to keep up with the highest number in the array
int lowestNum; //keeping up with the smallest number in array
int columns; //total columns to make up the dimensions of the image
int rows; //total rows to make up the dimensions of the image
vector<vector<int> > dataVec; //holds the data from the file
struct coordinates { //keeps up with where you are in the image, used to change the pixel color
    int x;
    int y;
    int value;
};

//function used to convert the 1d "new" array from the dataset to a 2D array
void convertToVec(int* data, int rowCount, int colCount, int size) {
    vector<vector<int> > vec(rowCount, vector<int>(colCount));
    for (int i = 0; i < size; i++) {
        vec[i / colCount][i % colCount] = data[i];
    }
    //update to make global
    dataVec = vec;
}

//function to read in the .dat file provided and store data in array to form image
//calls the convertToVec function to convert it within the function
void readFile(string filename) {
    highestNum = INT_MIN;
    lowestNum = INT_MAX;
    int size = 0; //keeps track of the size of the data
    ifstream file;
    int num;
    int rowCount;
    int colCount;

    //find the size of the data, in order to make "new" array
    //how many ints are stored in the file
    file.open(filename, ios::in);
    while (file >> num) {
        size++;
    }
    file.close();

    //adjusting for first two entries (dimensions on the array)
    size = size - 2;

    //fill the array with the dataset
    int* data = new int[size];
    file.open(filename, ios::in);
    for (int i = 0; i < size + 2; i++) {
        //first num is colNum and second num is rowNum
        if (i == 0) {
            file >> colCount;
        }
        else if (i == 1) {
            file >> rowCount;
        }
        else {
            file >> data[i - 2];
            if (data[i - 2] > highestNum) {
                highestNum = data[i - 2];
            }
            if (data[i - 2] < lowestNum) {
                lowestNum = data[i - 2];
            }
        }
    }
    file.close();

    //convert array to 2D vector
    convertToVec(data, rowCount, colCount, size);
    //delete 1D array to free up storage
    delete data;
    //make global
    columns = colCount;
    rows = rowCount;
}



//function to scale the values in the array from 0-255, accounting for positive and negative numbers
//this range is for the pixel colors
void scaleValues() {
    for (int i = 0; i < dataVec.size(); i++) {
        for (int j = 0; j < dataVec[i].size(); j++) {
            dataVec[i][j] = ((255 * (dataVec[i][j] - (lowestNum))) / (highestNum - lowestNum));
        }
    }
}

//function to change the pixel color based on the coord the bestPath chose, uses location in struct, uses ColorGrid
void drawPath(ColorGrid* cg, coordinates* coord) {
    //set current coord to red
    cg->set(coord->x, coord->y, Color(255, 0, 0));
}

//function serving as the greedy algorithm, finds the best route through the image based on lowest elevation change
//if there is a tie for the best path, a path was chosen (usually b)
void bestPath(coordinates* coord, ColorGrid* cg) {
    //set up variables
    int n; //row
    int m; //col
    int x; //value stored in coord
    int a, b, c; //path options
    bool aInRange = true;
    bool cInRange = true;
    //initialize variables
    for (int i = 0; i < columns - 1; i++) {
        n = coord->x; //row
        m = coord->y; //col
        x = coord->value; //data within
        b = dataVec[n][m + 1];

        //check boundaries
        if ((n - 1) >= 0) {
            aInRange = true;
            a = dataVec[n - 1][m + 1];
        }
        else {
            aInRange = false;
        }
        if ((n + 1) <= rows) {
            cInRange = true;
            c = dataVec[n + 1][m + 1];
        }
        else {
            cInRange = false;
        }

        //check elevation data (smallest change in elevatoin = best path)
        if (aInRange && abs(x - a) < abs(x - b)) {
            //a is best path
            if (aInRange && cInRange && abs(x - a) < abs(x - c)) {
                coord->x = n - 1;
                coord->y = m + 1;
                coord->value = a;
                drawPath(cg, coord);
            }
        } //options if a is not in range
        if (!aInRange && abs(x - b) < abs(x - c)) {
            //b wins
            coord->x = n;
            coord->y = m + 1;
            coord->value = b;
            drawPath(cg, coord);
        }
        else if (abs(x - c) < abs(x - b)) {
            //c wins
            coord->x = n + 1;
            coord->y = m + 1;
            coord->value = c;
            drawPath(cg, coord);
        }
        else if (abs(x - c) == abs(x - b)) {
            //let b win
            coord->x = n;
            coord->y = m + 1;
            coord->value = b;
            drawPath(cg, coord);
        } //options if c is not in range
        if (!cInRange && abs(x - a) < abs(x - b)) {
            //a wins
            coord->x = n;
            coord->y = m + 1;
            coord->value = b;
            drawPath(cg, coord);
        }
        else if (abs(x - b) < abs(x - a)) {
            //b wins
            coord->x = n + 1;
            coord->y = m + 1;
            coord->value = c;
            drawPath(cg, coord);
        }
        else if (abs(x - a) == abs(x - b)) {
            //let b win
            coord->x = n;
            coord->y = m + 1;
            coord->value = b;
            drawPath(cg, coord);
        }
        //b is best path
        if (aInRange && abs(x - b) < abs(x - a)) {
            if (cInRange && abs(x - b) < abs(x - c)) {
                coord->x = n;
                coord->y = m + 1;
                coord->value = b;
                drawPath(cg, coord);
            }
        } //c is best path
        if (aInRange && cInRange && abs(x - c) < abs(x - a)) {
            if (cInRange && abs(x - c) < abs(x - b)) {
                coord->x = n + 1;
                coord->y = m + 1;
                coord->value = c;
                drawPath(cg, coord);
            }
        } //(a = b) < c, letting b win
        if (aInRange && cInRange && (abs(x - a) == abs(x - b)) && abs(x - a) < abs(x - c)) {
            coord->x = n;
            coord->y = m + 1;
            coord->value = b;
            drawPath(cg, coord);
        } //(b = c) < a, letting b win
        if (aInRange && cInRange && (abs(x - c) == abs(x - b)) && abs(x - c) < abs(x - a)) {
            coord->x = n;
            coord->y = m + 1;
            coord->value = b;
            drawPath(cg, coord);
        } // (a = c) < b, letting c win
        if (aInRange && cInRange && (abs(x - c) == abs(x - a)) && abs(x - c) < abs(x - b)) {
            coord->x = n + 1;
            coord->y = m + 1;
            coord->value = b;
            drawPath(cg, coord);
        } //all of them are equal, letting b win
        if (aInRange && cInRange && abs(x - a) == abs(x - b) && abs(x - a) == abs(x - c) && abs(x - b) == abs(x - c)) {
            coord->x = n;
            coord->y = m + 1;
            coord->value = b;
            drawPath(cg, coord);
        }
    }
}



//function to display the image with the path drawn, using ColorGrid. goes through entire vector.
//r = g = b for grey-scale. the value stores at dataVec[i][j] = the rgb pixel color.
void displayImage(ColorGrid* cg) {
    int r, g, b;
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < columns; j++) {
            r = dataVec[i][j];
            g = dataVec[i][j];
            b = dataVec[i][j];
            cg->set(i, j, Color(r, g, b));
        }
    }
}

int main() {
    // create Bridges object
    Bridges bridges(3, "ambersibel",
        "59807219965");

    //read in file
    readFile("/home/user/Downloads/california.dat"); //whatever the current file path is
    //normalize the data
    scaleValues();

    int width = rows, height = columns;
    Color baseColor = Color("white");

    ColorGrid* cg = new ColorGrid(width, height, baseColor);

    displayImage(cg);

    bridges.setDataStructure(cg);

    //set the first value in the struct
    struct coordinates currentCoord = { 0,0,0 };
    struct coordinates* coord = &currentCoord;
    coord->x = 1000;
    coord->y = -1;

    //boundaries
    if (coord->x < 0) {
        coord->x = 250;
    }
    if (coord->x > rows) {
        coord->x = 250;
    }
    if (coord->y < 0) {
        coord->y = 0;
    }
    if (coord->y >= columns) {
        coord->y = 0;
    }
    //after the boundaries have been tested:
    coord->value = dataVec[coord->x][coord->y];

    //use the greedy algorithm
    bestPath(coord, cg);

    bridges.visualize();

    return 0;
}