//Driver for the auto maze solver in c++

#include "maze_solver.h"

#include <iostream>

using namespace std;







int main(){

    mazeSolver maze;
    
    string file = "maze.txt";

    maze.readMazeFromFile(file);

    maze.findStartEnd();

    maze.findPath();


    return 1;
}