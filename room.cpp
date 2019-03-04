/*********************************************************************
 *** Program Filename: room.cpp
 * ** Author: Charlene Wang
 * ** Date: 3/4/19
 * ** Description: this contains the implementation for the room class
 * ** Input: none
 * ** Output: none
 * *********************************************************************/
#include "room.hpp"

/*********************************************************************
 ** Function: Room
 ** Description: constructor
 ** Parameters: none
 ** Pre-Conditions: needs to be called
 ** Post-Conditions: intializes certain variables
 *********************************************************************/
Room :: Room(){
    //cout << "room constructor called" << endl;
    event_type = 0;
    event = NULL;
}

/*********************************************************************
 ** Function: Room
 ** Description: constructor
 ** Parameters: none
 ** Pre-Conditions: needs to be called
 ** Post-Conditions: intializes certain variables
 *********************************************************************/
Room :: Room(const Room& r){
    this->event_type = r.event_type;
    this->event = r.event;
}

/*********************************************************************
 ** Function: operator=
 ** Description: constructor
 ** Parameters: none
 ** Pre-Conditions: needs to be called
 ** Post-Conditions: intializes certain variables
 *********************************************************************/
void Room :: operator=(const Room& ro){
    this->event_type = ro.event_type;
    this->event = ro.event;
}

/*********************************************************************
 ** Function: set_event
 ** Description: will set the room to that event
 ** Parameters: int which
 ** Pre-Conditions: variables, classes, objects, and functions need to exist
 ** Post-Conditions: sets the room to that event
 *********************************************************************/
void Room :: set_event(int which){
    if(which == 2){
        this->event = new Wumpus;
        this->event_type = 4;
    }
    else if(which == 3) {
        this->event = new Gold;
        this->event_type = 1;
    }
    else if(which == 4 || which == 5){
        this->event = new Bats;
        this->event_type = 2;
    }
    else if(which == 6 || which == 7){
        this->event = new Pit;
        this->event_type = 3;
    }
    else if(which == 1)
    {
        //this is where the player starts
        this->event_type = 0;
    }
    
}

/*********************************************************************
 ** Function: clear_event
 ** Description: will set the event in room to empty
 ** Parameters: none
 ** Pre-Conditions: none
 ** Post-Conditions: sets the event to empty
 *********************************************************************/
void Room :: clear_event(){
    delete event;
    Event* event = NULL;
    this->event_type = 0;
}

/*********************************************************************
 ** Function: encounter
 ** Description: will print out encounter message
 ** Parameters: none
 ** Pre-Conditions: none
 ** Post-Conditions: none
 *********************************************************************/
void Room :: encounter_access(){
    cout << this->event->encounter_message() << endl;
}

/*********************************************************************
 ** Function: percept
 ** Description: will print out percept
 ** Parameters: none
 ** Pre-Conditions: none
 ** Post-Conditions: none
 *********************************************************************/
void Room :: percept_access(){
    cout << this->event->percept_message() << endl;
}
