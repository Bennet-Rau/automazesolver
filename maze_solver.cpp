
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
            foundPathMaze[rowIndex][colIndex] = inputCH;
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
                setEnd(end);
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


bool mazeSolver::findPath() {

    findStartEnd();

    int numRows = getNumRows();
    int numCols = getNumCols();
    cell start = getStart();
    cell end = getEnd();
    stack<cell> dfsStack;
    dfsStack.push(start);

    //define possible moves (left, right, up, down)
    int dirRows[] = {-1, 1, 0, 0};
    int dirCols[] = {0, 0, -1, 1};

    //initialize the visited array with false
    for (int i = 0; i < numRows; i++) {
        for (int j = 0; j < numCols; j++) {
            visited[i][j] = false;
        }
    }

    //While loop to search maze for correct path using back tracking
    while (!dfsStack.empty()) {

        cell current = dfsStack.top();
        int row = current.row;
        int col = current.col;

        //Case for path found and storing it in the 2d array, showing the paths using X
        if (row == end.row && col == end.col) { 

            while (dfsStack.empty() == false) {
                cell pathCell = dfsStack.top();
                foundPathMaze[pathCell.row][pathCell.col] = 'X';
                dfsStack.pop();
            }
            return true;
        }

        //Mark the current cell as visited
        visited[row][col] = true;
        //Set found next to false
        bool foundNext = false;

        //Explore neighboring cells to find the path
        for(int i = 0; i < 4; ++i){

            int newRow = row + dirRows[i];
            int newCol = col + dirCols[i];

            if(isValid(newRow, newCol, numRows, numCols) && maze[newRow][newCol] != 'W' && visited[newRow][newCol] == false){
                dfsStack.push(cell(newRow, newCol));
                foundNext = true;
            }
        }

        // If no valid path is found, backtrack
        if(foundNext == false){
            dfsStack.pop();
        }
    }

    return false;
}




void mazeSolver::printPath(){
    //Prints the path
    cout << "Path from Start to End:" << endl;
    for (int i = 0; i < getNumRows(); i++) {
        for (int j = 0; j < getNumCols(); j++) {
            cout << foundPathMaze[i][j] << ' ';
        }
        cout << endl;
    }
}
