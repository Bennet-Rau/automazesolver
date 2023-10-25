
#include "maze_solver.h"

mazeSolver::mazeSolver(){
    rows = 0;
    cols = 0;
}

mazeSolver::mazeSolver(int newRows, int newCols){
    rows = newRows;
    cols = newCols;

}

int mazeSolver::getNumCols(){
    return cols;
}

void mazeSolver::setNumCols(int numCols) {
    cols = numCols;
}

int mazeSolver::getNumRows(){
    return rows;
}

void mazeSolver::setNumRows(int numRows) {
    rows = numRows;
}

