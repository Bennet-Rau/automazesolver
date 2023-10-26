
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

bool mazeSolver::readMazeFromFile(string &file){
    ifstream input(file);
    char character;

    //If file could not be open
    if(input.is_open() == false){
        cerr << "Could not open the file" << endl;
        return false;
    }


    // Determine the number of rows and columns in the file
    int numRows = 0;
    int numCols = 0;
    char ch;
    while (input.get(ch)) {
        if (ch == '\n') {
            numRows++; // Count newlines to determine rows
            numCols = 0; // Reset columns for the next row
        } else {
            numCols++; // Count characters to determine columns
        }
    }

    // Set the maze dimensions based on what was counted
    setNumRows(numRows);
    setNumCols(numCols);

    cout << "This is the number of cols: " << numRows << endl;
    cout << "This is the number of rows: " << numCols << endl;


    for(int rows = 0; rows <= numRows; rows++){
        for(int cols = 0; cols <= numCols; cols++){
           char character;
           input.get(character);
           maze[rows][cols] = character;

        }
    }

    return true;
}