/*********************************************************************
 *** Program Filename: room.hpp
 * ** Author: Charlene Wang
 * ** Date: 3/4/19
 * ** Description:
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
    Event * event;
    int event_type;
public:
    Room();
    Room(const Room& r);
    void operator=(const Room& ro);
    
    void set_event(int which);
    int check_event() {return this->event_type;}
    void clear_event();
    void encounter_access();
    void percept_access();
    
};
#endif
