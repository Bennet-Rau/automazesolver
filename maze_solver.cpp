
#include "maze_solver.h"

mazeSolver::mazeSolver(){
    rows = 0;
    cols = 0;
    index_x = 0;
    index_y = 0;
}

mazeSolver::mazeSolver(int newRows, int newCols, int newIndex_x, int newIndex_y){
    rows = newRows;
    cols = newCols;
    index_x = newIndex_x;
    index_y = newIndex_y;

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
cell mazeSolver::getStart(){
    return start;
}
void mazeSolver::setStart(cell newStart){
    start = newStart;
}

cell mazeSolver::getEnd(){
    return end;
}
void mazeSolver::setEnd(cell newEnd){
    end = newEnd;
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
    char in, inputCH;
    bool countColumns = true;                    

    while(input.get(in)){
        if(in == '\n'){
            numRows++;
            countColumns = false;
        }
        else if(countColumns == true){
            if(in == 'W' || in == 'S' || in == 'O' || in == 'E'){
                numCols++;
            }
        }
    }

    // Set the maze dimensions based on what was counted
    setNumRows(numRows);
    setNumCols(numCols);

    cout << "This is the number of cols: " << numRows << endl;
    cout << "This is the number of rows: " << numCols << endl;

    
    //Sets the input read back to the start of the file
    input.clear();                                                          
    input.seekg(0, ios::beg);   


    //Reads maze into the 2d char array
    int rowIndex = 0;
    int colIndex = 0;

    while(rowIndex <= numRows){
        input.get(inputCH);
        //leaves out spaces and commas
        if (inputCH == ' ' || inputCH == ',') {
            continue;
        }
        //only looks for valid characters 
        else if(inputCH == 'W' || inputCH == 'S' || inputCH == 'O' || inputCH == 'E'){
            maze[rowIndex][colIndex] = inputCH;
            colIndex++;
        }
        //looks for endline character to increment row index
        else if(inputCH == '\n'){
            rowIndex++;
            colIndex = 0;
        }

    }

    return true;

}

bool mazeSolver::findStartEnd(){
    bool Sfound = false;
    bool Efound = false;

    for(int i = 0; i < getNumRows(); i++){
        for(int j = 0; j < getNumCols(); j++){
            if(maze[i][j] == 'S'){
                cell start(i, j);
                setStart(start);
                Sfound = true;
                cout << "Start was found at: " << i << ", " << j << endl;
            }
            if(maze[i][j] == 'E'){
                cell end(i, j);
                Efound = true;
                cout << "End was found at: " << i << ", " << j << endl;
            }
        }
    }

    

    return Sfound && Efound;
}

bool mazeSolver::isValid(int row, int col, int numRows, int numCols) {
    return row >= 0 && row < numRows && col >= 0 && col < numCols;
}

bool mazeSolver::findPath(cell start, cell end) {
    int numRows = getNumRows();
    int numCols = getNumCols();

    // Ensure start and end cells are within the bounds of the maze
    if (!isValid(start.row, start.col, numRows, numCols) ||
        !isValid(end.row, end.col, numRows, numCols)) {
        return false;
    }

    //set all indexes to false
    for(int i = 0; i < numRows; i++){
        for(int j = 0; j < numCols; j++){
            visited[i][j] = false;
        }
    }

    // Define possible moves (up, down, left, right)
    int dirRows[] = {-1, 1, 0, 0};
    int dirCols[] = {0, 0, -1, 1};

    queue<cell> q;
    q.push(start);

    while (!q.empty()) {
        cell current = q.front();
        q.pop();

        //Path found condition
        if (current.row == end.row && current.col == end.col) {
            return true; 
        }

        // Explore neighbors
        for (int i = 0; i < 4; ++i) {
            int newRow = current.row + dirRows[i];
            int newCol = current.col + dirCols[i];

            if (isValid(newRow, newCol, numRows, numCols) && maze[newRow][newCol] != 'W' && visited[newRow][newCol] == false) {
                visited[newRow][newCol] = true;
                cell newCell(newRow, newCol);
                q.push(newCell);
            }
        }
    }

    return false; 
}

