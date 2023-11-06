//Author: Bennet Rau
//Driver for the auto maze solver in c++
//Takes in a maze of up to size 25. 
//W = walls
//O = open spaces 
//S = start
//E = end
//X = path taken from start to end by maze solving algorithm

#include "maze_solver.h"

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

            case 1:
                cout << "This is the maze file " << endl;
                cout << "Where 'W' means walls 'S' means start 'E' means end and 'O' means open space for moving. " << endl;
                printMazeFromFile(file);
                cout << endl;

                break;

            case 2:
                maze.readMazeFromFile(file);
                maze.findStartEnd();
                cout << endl;

                break;

            case 3:
                cout << "This is the path of the maze from start to end" << endl;
                maze.readMazeFromFile(file);
                maze.findPath();
                maze.printPath();
                cout << endl;
                cout << "Where 'X' shows the path taken by maze solving algorithm" << endl << endl;

                break;

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
            cout << inputCH;
        }
    }

}