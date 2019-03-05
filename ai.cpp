/*********************************************************************
 *** Program Filename: ai.cpp
 * ** Author: Charlene Wang
 * ** Date: 3/4/19
 * ** Description: contains the implementation for Ai class
 * ** Input: none
 * ** Output: none
 * *********************************************************************/
#include "ai.hpp"

using namespace std;

/*********************************************************************
 ** Function: Ai
 ** Description: constructor
 ** Parameters: none
 ** Pre-Conditions: needs to be called
 ** Post-Conditions: intializes certain variables
 *********************************************************************/
Ai :: Ai(){
    this->movesize = 30;
    this->move = vector<int>(movesize);
    this->oscillating = false;
    this->next = 0;
}

/*********************************************************************
 ** Function: add_move
 ** Description:
 ** Parameters: none
 ** Pre-Conditions: needs to be called
 ** Post-Conditions: intializes certain variables
 *********************************************************************/
void Ai :: add_move(int direction){
    if(move.at(movesize-1) != 0)
    {
        //double size of vector
        vector<int> temp = vector<int>(movesize * 2);
        for(int i = 0; i < movesize; i++)
            temp.at(i) = move.at(i);
        this->movesize = movesize * 2;
        this->move = temp;
    }
    //1 = north 2 = south 3 = east 4 = west
    this->move.at(next) = direction;
    this->next++;
}

/*********************************************************************
 ** Function: start_return
 ** Description: will set the next variable to the last index of move
 ** Parameters: none
 ** Pre-Conditions:
 ** Post-Conditions:
 *********************************************************************/
void Ai :: start_return(){
    this->next = movesize -1;
}

/*********************************************************************
 ** Function: return_moves
 ** Description: will return the moves the player made
 ** Parameters: none
 ** Pre-Conditions:
 ** Post-Conditions:
 *********************************************************************/
int Ai :: return_moves(){
    int x = move.at(next);
    next--;
    return x;
}

