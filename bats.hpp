/*********************************************************************
 *** Program Filename: bats.hpp
 * ** Author: Charlene Wang
 * ** Date: 3/4/19
 * ** Description: holds the code for the bats percept and encounter message
 * ** Input: none
 * ** Output: none
 * *********************************************************************/
#ifndef BATS_HPP
#define BATS_HPP
#include <iostream>
#include <string>

#include "event.hpp"

using namespace std;

//hsa to be two of these rooms
class Bats : public Event{
private:
    string percept;
    string encounter;
public:
    Bats();
    string percept_message() {return percept;}
    string encounter_message() {return encounter;}
};

#endif
