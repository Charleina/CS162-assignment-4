/*********************************************************************
 *** Program Filename: application.cpp
 * ** Author: Charlene Wang
 * ** Date: 3/4/19
 * ** Description: contains main function
 * ** Input: none
 * ** Output: none
 * *********************************************************************/
#include <iostream>
#include <time.h> //for time
#include <ctime>
#include <stdio.h>
#include <iomanip>
#include <stdlib.h>

#include "room.hpp"
#include "game.hpp"
#include "event.hpp"
#include "gold.hpp"
#include "bats.hpp"
#include "wumpus.hpp"
#include "pit.hpp"

using namespace std;

/*********************************************************************
 ** Function: Main
 ** Description: contains main function
 ** Parameters: none
 ** Pre-Conditions: none
 ** Post-Conditions: will do the entire game of Wumpus
 *********************************************************************/
int main(int argc, char** argv){
    //check if user input command line
    if (argc < 2) {
        cerr << "Error: must specify a value for n." << endl;
        cerr << endl;
        cerr << "usage: " << argv[0] << " <n>" << endl;
        return 1;
    }
    
    //check if the number is 4 or more
    int n = strtol(argv[1], NULL, 0);
    if (n < 4) {
        cerr << "Error: n must be a positive integer value and 4 or more." << endl;
        cerr << endl;
        cerr << "usage: " << argv[0] << " <n>" << endl;
        return 1;
    }
    
    //intialize seed
    srand(time(NULL));
    
    //creates game object
    Game g;
    
    g.set_cavesize(n);
    g.set_board();
    
    //runs game
    g.run();
    
    
    return 0;
}
