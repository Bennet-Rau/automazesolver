//maze solver header file
//Auhtor: Bennet Rau

#ifndef MAZE_SOLVER_H
#define MAZE_SOLVER_H

#include <iostream>
#include <fstream>
#include <stack>

#define MAX_X 25
#define MAX_Y 25


using namespace std;

struct cell{
    int row, col;

    cell(): row(0), col(0) {}
    cell(int r, int c) : row(r), col(c) {}
};

class mazeSolver {
        int rows, cols, index_x, index_y;
        cell start, end;
        char maze[MAX_X][MAX_Y], foundPathMaze[MAX_X][MAX_Y];
        bool visited[MAX_X][MAX_Y];
        //vector<vector<int, int> > solverMaze;

    public:
        mazeSolver();
        mazeSolver(int, int, int, int);

        int getNumCols();
        void setNumCols(int);

        int getNumRows();
        void setNumRows(int);

        cell getStart();
        void setStart(cell);

        cell getEnd();
        void setEnd(cell);

        bool readMazeFromFile(string& file);
        bool findPath();
        void printPath();
        bool isValid(int, int, int, int);
        bool findStartEnd();




};
#include "maze_solver.cpp"
#endif



