/*********************************************************************
 *** Program Filename: wumpus.cpp
 * ** Author: Charlene Wang
 * ** Date: 3/4/19
 * ** Description:
 * ** Input: none
 * ** Output: none
 * *********************************************************************/
#include "wumpus.hpp"

/*********************************************************************
  ** Function: Wumpus
  ** Description: constructor
  ** Parameters: none
  ** Pre-Conditions: needs to be called
  ** Post-Conditions: intializes certain variables
  *********************************************************************/
Wumpus :: Wumpus(){
    this->percept = "You smell a terrible stench.";
    this->encounter = "The Wumpus has angrily eaten you...";
}
