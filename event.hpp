/*********************************************************************
 *** Program Filename: event.hpp
 * ** Author: Charlene Wang
 * ** Date: 3/4/19
 * ** Description:
 * ** Input: none
 * ** Output: none
 * *********************************************************************/
#ifndef EVENT_HPP
#define EVENT_HPP
#include <iostream>
#include <string>
#include <time.h> //for time
#include <ctime>
#include <stdio.h>
#include <iomanip>
#include <stdlib.h>

using namespace std;

class Event {
public:
    virtual string encounter_message() = 0;//encounter
    virtual string percept_message() = 0;
    
};

#endif
