//MA - 9/18/23 - CSC212 - Assignment 2
// maze.h

#include <iostream>
#include <vector>
#include <string>

using namespace std;

// creating a class Maze and its methods
class Maze{
    private:
        vector<vector<int> > maze;
        int row;
        int col;
        int seed = 0;
        string fname;
    public:
        Maze(int row, int col);
        void make_path();
        void make_file(string fname);
};