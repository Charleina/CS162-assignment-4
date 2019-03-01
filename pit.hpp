/*********************************************************************
 *** Program Filename: pit.hpp
 * ** Author: Charlene Wang
 * ** Date: 3/4/19
 * ** Description: contains the percepts and encounter message for pit
 * ** Input: none
 * ** Output: none
 * *********************************************************************/
#ifndef PIT_HPP
#define PIT_HPP
#include <iostream>
#include <string>
#include "event.hpp"

using namespace std;

//can only be two of thsee
class Pit : public Event {
private:
    string percept;
    string encounter;
public:
    Pit();
    string percept_message() { return percept; }
    string encounter_message() {return encounter; }
};
#endif
