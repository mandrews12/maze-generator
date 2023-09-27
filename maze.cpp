//MA - 9/18/23 - CSC212 - Assignment 2
// maze.cpp

#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <fstream>
#include "maze.h"

using namespace std;

// generates default maze
Maze::Maze(int rows, int cols) {
    row = rows;
    col = cols;

    // Creating maze with initial value of 15 in all cells (every cell has 4 walls to start)
    for (int i = 0; i < row; i++) {
        vector<int> cols;
        for (int j = 0; j < col; j++) {
            cols.push_back(15);
        }
        maze.push_back(cols);
    }
}

// generating path through maze 
void Maze::make_path(){

    // starts at cell 0,0 and marks it as visited and appends to array
    vector<pair<int,int> >A;
    maze[0][0] = 7;
    A.push_back(make_pair(0,0));

    while (A.size() > 0) {
        // gets current cell to check for neghbors
        int r = A[(A.size()-1)].first;
        int c = A[(A.size()-1)].second;
        pair <int,int> current(r,c);
        A.pop_back();
        vector<char> neighbors;

        // checks if neghbors have been visited, if not append them to neighbors array
        if (r > 0) {
            if(maze[r-1][c] == 15) {
                neighbors.push_back('n');
            }
        }
        if(r < row-1) {
            if(maze[r+1][c] == 15) {
                neighbors.push_back('s');
            }
        }
        if(c < col-1) {
            if(maze[r][c+1] == 15) {
                neighbors.push_back('e');
            }
        }
        
        if(c > 0) {
            if(maze[r][c-1] == 15) {
                neighbors.push_back('w');
            }
        }
        
        // if there are neghbors that have not been visited, find one to connect the path
        if (neighbors.size() != 0){
            A.push_back(current);

            // choose one random neghbor
            int idx = std::rand() / ((RAND_MAX + 1u) / neighbors.size());
            char neigh = neighbors[idx];

            // gets rid of wall between current and neghbor
            if (neigh == 'n') {
                maze[r-1][c] -= 4;
                maze[r][c] -= 8;
                A.push_back(make_pair(r-1,c));
            }
            if (neigh == 's') {
                maze[r+1][c] -= 8;
                maze[r][c] -= 4;
                A.push_back(make_pair(r+1,c));
            }
            if (neigh == 'e') {
                maze[r][c+1] -= 1;
                maze[r][c] -= 2;
                A.push_back(make_pair(r,c+1));
            }
            if (neigh == 'w') {
                maze[r][c-1] -= 2;
                maze[r][c] -= 1;
                A.push_back(make_pair(r,c-1));
                
            }
        }
        
    }

    // disolves south wall on ending cell
    maze[row-1][col-1] -= 4;

}

// writing the maze to a file
void Maze::make_file(string fname) {
    ofstream myfile;
    myfile.open (fname);
    for (int i = 0; i < maze.size(); i++) {
        for (int j = 0; j < maze[i].size(); j++){
            myfile << maze[i][j] << " ";
        }
        myfile << endl;
    }
    myfile.close();
}

