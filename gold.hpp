/*********************************************************************
 *** Program Filename: gold.hpp
 * ** Author: Charlene Wang
 * ** Date: 3/4/19
 * ** Description:
 * ** Input: none
 * ** Output: none
 * *********************************************************************/
#ifndef GOLD_HPP
#define GOLD_HPP
#include <iostream>
#include <string>
#include "event.hpp"

using namespace std;

class Gold : public Event{
private:
    string encounter;
    string percept;
public:
    Gold();
    string percept_message() {return percept;}
    string encounter_message() {return encounter;}
};
#endif
