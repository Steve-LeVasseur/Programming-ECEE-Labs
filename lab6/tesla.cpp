#include <iostream>
#include <cmath>
#include <cstdlib>
#include <string>
#include <vector>
#include <time.h>

using namespace std;

void CheckWalls(int i, int j){ // Gives player a message to keep from running through walls
    if (j == 16){
        cout << "There is a wall to your immediate right" << endl;
    }
    else if (j == 1){
        cout << "There is a wall to your immediate left" << endl;
    }
    if (i == 1){
        cout << "There is a wall in the upward direction" << endl;
    }
    else if (i == 16){
        cout << "There is a wall in the downward direction" << endl;
    }
    return;
}

int PlayerRowPosition(const vector<vector<int>> &Room){ // Evaluates player position after movement
    for (int i = 0; i < 17; i++){
        for (int j = 0; j < 17; j++){
            if (Room[i][j] == 1){
                return i;
            }
        }
    }
}

int PlayerColumnPosition(const vector<vector<int>> &Room){ // Evaluates player position after movement
    for (int i = 0; i < 17; i++){
        for (int j = 0; j < 17; j++){
            if (Room [i][j] == 1){
                return j;
            }
        }
    }
}

//int ElonMovement(int eI, int eJ){

//}

int CheckElon(int I, int J, int StarSaves, int eI, int eJ){ // Causes a confrontation with Elon if player is next to him
    if (((eI == I + 1) || (eI == I - 1)) && ((eJ == J + 1) || (eJ == J - 1))){
        cout << "Elon has found you!!!" << endl;
        if (StarSaves == 1){
            cout << "You manage to repel him this time, but you probably won't be able to again." << endl;
            return 0;
        }
        if (StarSaves == 0){
            cout << "Exhausted from the first encounter, you stand no chance as Elon overpowers you in his Mark III Iron Man suit." << endl << "When you awaken, it is due to the roars of rocket engines. Yuo find yourself in the Roadster but with nowhere to go. The rocket opens, and the last thing you see is the majesty of space.";
            return 3;
        }
    }
}

int CheckCars (int I, int J, vector< vector<int> > Room){ // Causes endgame if Roadster is found. Otherwise gives a sad message
    if (Room[I || I + 1 || I - 1][J || J + 1 || J - 1] == 5){

        return 1;
    }
    else if (Room[I || I + 1 || I - 1][J || J + 1 || J - 1] == 6){
        cout << "You found the Yugo..." << endl;
        return 0;
    }
    else if (Room[I || I + 1 || I - 1][J || J + 1 || J - 1] == 7){
        cout << "You found the Pinto..." << endl;
        return 0;
    }
    return 0;
}


int main(){
    srand(time(NULL));

    // Establish the Story
    cout << "(Press enter to continue. Try it now)" << endl;
    cin.ignore();

    cout << "You're walking in the woods. There's no one around and your phone is dead. Out of the corner of your eye, you spot it:" << endl << endl;
    cin.ignore();
    cout << "The Tesla/SpaceX/Boring Company Top Secret Warehouse and Testing Facility" << endl << endl;
    cin.ignore();
    cout << "You enter the warehouse. You only see one small light illuminating a table with some research notes on it." << endl;
    cin.ignore();
    cout << "Flipping through the notes you find that somewhere in the facility are 3 vehicles: " << endl << "a Ford Pinto, a Yugo, and a Tesla Roadster" << endl;
    cin.ignore();
    cout << "Due to your rational fear of cars that will explode the moment you enter them, you decide to use the Roadster to escape." << endl;
    cin.ignore();
    cout << "Once you find the Roadster you can escape. You may find tools that can help you in here, but you may also find dangers." << endl;
    cin.ignore();

    // Layout and Movement instructions
    cout << "The warehouse is comparable to a 15x15 grid. You wandered to a random location to read the notes." << endl;
    cout << "Use wsad (all lowercase) to move around the room." << endl;

    // Create the room
    int StarPoints = 0;
    int rows = 17;
    int columns = 17;
    vector<vector<int>> Room;
    Room.resize(rows, vector<int>(columns, 0));

    // Create the walls. A wall is marked as a 9 on the two-dimensional vector
    for (unsigned i = 0; i < 17; i++){
        Room[i][0] = 9;
        Room[i][16] = 9;
        Room[0][i] = 9;
        Room[16][i] = 9;
    }

    // Place player and objects. Player = 1, Elon = 2, Roadster = 5, Yugo = 6, Pinto = 7.
    BadRandoms:
    int initialI = (rand() % 15) + 1;
    int initialJ = (rand() % 15) + 1;
    int yI = (rand() % 15) + 1;
    int yJ = (rand() % 15) + 1;
    int pI = (rand() % 15) + 1;
    int pJ = (rand() % 15) + 1;
    int rI = (rand() % 15) + 1;
    int rJ = (rand() % 15) + 1;
    int eI = (rand() % 15) + 1;
    int eJ = (rand() % 15) + 1;

    if (((yI == pI) && (yJ == pJ)) || ((yI == rI) && (yJ == rJ)) || ((rI == pI) && (rJ == pJ)) || ((initialI == eI) && (initialJ == eJ))){
        goto BadRandoms; // Just in case incompatible objects are overlapping
    }
    Room[initialI][initialJ] = 1;
    Room[eI][eJ] = 2;
    Room[rI][rJ] = 5;
    Room[yI][yJ] = 6;
    Room[pI][pJ] = 7;


    // Game Begins for Real
    int GameComplete = 0;
    int StarSaves = 1;
    int Z;
    char input;
    do{
        int I = PlayerRowPosition(Room);
        int J = PlayerColumnPosition(Room);
        Z = CheckElon(I, J, StarSaves, eI, eJ); //Check for Elon
        StarSaves = Z;
        if (StarSaves == 3){ // Game over if caught by Elon
            GameComplete = 1;
            StarPoints += 1;
            break;
        }
        CheckWalls(I, J); // Check for walls
        int Zed = CheckCars(I, J, Room); // Check for cars
        GameComplete = Zed;
        if (GameComplete == 1){
            cout << "You found the Roadster!" << endl;
            return 0;

        }
        cout << "Input a movement command" << endl; // Movement input and evaluation
        cin >> input;
        if (input == 'w'){
            Room[I][J] = 0;
            Room[I-1][J] = 1;
        }
        else if (input == 'a'){
            Room[I][J] = 0;
            Room[I][J-1] = 1;
        }
        else if (input == 's'){
            Room[I][J] = 0;
            Room[I+1][J] = 1;
        }
        else if (input == 'd'){
            Room[I][J] = 0;
            Room[I][J+1] = 1;
        }

    }while(GameComplete == 0);
    return 0;

}
