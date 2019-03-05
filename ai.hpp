/*********************************************************************
 *** Program Filename: ai.hpp
 * ** Author: Charlene Wang
 * ** Date: 3/4/19
 * ** Description: holds the code for the ai class
 * ** Input: none
 * ** Output: none
 * *********************************************************************/
#ifndef AI_HPP
#define AI_HPP
#include <iostream>
#include <string>
#include <vector>

using namespace std;

class Ai {
private:
    vector<int> move;
    bool oscillating;
    int next, movesize;
    
public:
    Ai();
    void set_oscillating(bool x) { this->oscillating = x;}
    bool check_oscillating() {return this->oscillating;}
    void add_move(int direction);
    void start_return();
    int return_moves();
    
};

#endif
