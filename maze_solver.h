#ifndef MAZE_SOLVER_BFS_H
#define MAZE_SOLVER_BFS_H

#include <vector>
#include <queue>
#include <iostream>
#include <fstream>


using namespace std;

struct cell{
    int row, col;

    cell(): row(0), col(0) {}
    cell(int r, int c) : row(r), col(c) {}
};

class mazeSolver {
        int rows, cols, index_x, index_y;
        vector<vector<char>> maze;
        vector<vector<bool>> visitedVector;
        vector<vector<int, int>> solverMaze;

    public:
        mazeSolver();
        mazeSolver(int, int);

        int getNumCols();
        void setNumCols(int);

        int getNumRows();
        void setNumRows(int);

        bool readMazeFromFile(string& file);
        bool findPath(cell start, cell end);
        void printPath(cell start, cell end);




};

#endif



