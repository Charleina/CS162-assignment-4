/*********************************************************************
 *** Program Filename: game.hpp
 * ** Author: Charlene Wang
 * ** Date: 3/4/19
 * ** Description: contains the game logic
 * ** Input: none
 * ** Output: none
 * *********************************************************************/
#ifndef GAME_HPP
#define GAME_HPP
#include <iostream>
#include <vector>
#include <string>
#include <stdlib.h>
#include <random>
#include <algorithm>
#include <iterator>

#include "room.hpp"
#include "event.hpp"
//#include "ai.hpp"

using namespace std;

class Game {
private:
    vector< vector<Room> > caves;
    int cavesize;
    
    int spotx, spoty; //where the user is
    int startx, starty;
    
    int arrows;
    
    int wumpusx, wumpusy; //where the user is
    int startwumpusx, startwumpusy;
    
    bool wumpus;
    bool gold;
    bool alive;
    bool win;
    
    
    //for hidden map
    int batsx, batsy, batx, baty;
    int pitx, pity, pittx, pitty;
    int goldx, goldy;
    
    /*//for ai
    int previousturn, previousturn2;
    string ai_direction;
    bool goodeventnearby, badeventnearby, shoot;
    Ai ai;
    */
    
public:
    Game(); //creates vectors
    
    void set_cavesize(int size) { this->cavesize = size; }
    void set_board();
    
    void run();//runs actual game
    void prompt();
    
    bool move_user(string direction);
    void move_arrow(string direction);
    void enact_event(int which);
    void percept();
    void superbat();
    
    void welcome();
    void game_reset();
    void game_restart();
    void wumpus_flee();
    
    void hidden_coordinates();
    /*
    void run_ai();
    void ai_prompt(bool nearby);
    void move_ai(int direction);
    void move_airandom(bool oscillating);
    void strategic_move_ai();
    void ai_percept();*/
};

#endif
