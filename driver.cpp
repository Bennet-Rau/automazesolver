//Driver for the auto maze solver in c++

#include "maze_solver.h"
#include <iostream>
#include <fstream>

using namespace std;


int printMenu();
void printMazeFromFile(string);

int main(){

    int userOption;
    mazeSolver maze; 
    string file = "maze.txt";
    cell start = maze.getStart();
    cell end = maze.getEnd();



    do{
        userOption = printMenu();

        switch(userOption){

            case '1':
                cout << "This is the maze file " << endl;
                printMazeFromFile(file);
                cout << endl;

            case '2':
                maze.findStartEnd();
                cout << "The starting point of the maze is at positon: " << start.row + 1 << ", " << start.col + 1 << endl;
                cout << "The ending point of the maze is at positon: " << end.row + 1 << ", " << end.col + 1 << endl;

            case '3':
                cout << "This is the path of the maze from start to end" << endl;
                maze.findPath();
                maze.printPath();
                cout << endl;

            default:
                break;
        }


    }while(userOption != 0);
    


    return 1;
}

int printMenu(){
    int menuOption;
    
    cout << "=========Automatic Mazer Sovler=========" << endl;
    cout << "1: Print maze from file." << endl;
    cout << "2: Print location of starting point and ending point." << endl;
    cout << "3: Print solved maze." << endl;
    cout << "0: Exit program." << endl;
    cout << "Please select and option: ";
    cin >> menuOption;

    return menuOption;

}

void printMazeFromFile(string file){

    char inputCH;
    ifstream input(file);

    if(input.is_open() == false){
        cerr << "Could not open the file" << endl;
        return;
    }

    while(input.get(inputCH)){
        if(inputCH == '\n'){
            cout << endl;
        }
        else{
            cout << inputCH << ", ";
        }
    }

}