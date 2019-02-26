/*********************************************************************
 *** Program Filename: wumpus.hpp
 * ** Author: Charlene Wang
 * ** Date: 3/4/19
 * ** Description:
 * ** Input: none
 * ** Output: none
 * *********************************************************************/
#ifndef WUMPUS_HPP
#define WUMPUS_HPP
#include <iostream>
#include <string>
#include "event.hpp"

using namespace std;

//75% wumpus will move
class Wumpus : public Event{
private:
    string percept;
    string encounter;
public:
    Wumpus();
    string percept_message() {return percept;}
    string encounter_message() {return encounter;}
    
};
#endif
