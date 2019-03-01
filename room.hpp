/*********************************************************************
 *** Program Filename: room.hpp
 * ** Author: Charlene Wang
 * ** Date: 3/4/19
 * ** Description: holds the code for the Room functions that interact with events 
 * ** Input: none
 * ** Output: none
 * *********************************************************************/
#ifndef ROOM_HPP
#define ROOM_HPP
#include <iostream>
#include <string>
#include <time.h> //for time
#include <ctime>
#include <stdio.h>
#include <iomanip>
#include <stdlib.h>

#include "event.hpp"
#include "pit.hpp"
#include "bats.hpp"
#include "gold.hpp"
#include "wumpus.hpp"

using namespace std;

class Room {
private:
    Event * event; //can contain an event or not
    int event_type; //will hold number to verify which event it is
public:
    Room();
    Room(const Room& r);
    void operator=(const Room& ro);
    //getter
    int check_event() {return this->event_type;}
    //setter
    void set_event(int which);
 
    void clear_event();
    void encounter_access();
    void percept_access();
    
};
#endif
