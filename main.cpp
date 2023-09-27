//MA - 9/18/23 - CSC212 - Assignment 2
// main.cpp

/*
program to randomly generate a maze from inputed number of rows and columns
every cell needs to be reached from the start and there needs to be one path
from start to finish
*/

#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <fstream>
#include <sstream>
#include "maze.h"

using namespace std;

int main(int argc, char*argv[]) {

    // storing input from users
    int seed = stoi(argv[1]);
    int row = stoi(argv[2]);
    int col = stoi(argv[3]);
    string fname = argv[4];
    
    // generating maze
    srand(seed);
    Maze mymaze(row,col);

    // generating path through maze
    mymaze.make_path();

    // storing maze in output file
    mymaze.make_file(fname);

    return 0;
}