/*********************************************************************
 *** Program Filename: game.cpp
 * ** Author: Charlene Wang
 * ** Date: 3/4/19
 * ** Description:
 * ** Input: none
 * ** Output: none
 * *********************************************************************/
#include "game.hpp"

using namespace std;
/*********************************************************************
 ** Function: Game
 ** Description: constructor
 ** Parameters: none
 ** Pre-Conditions: needs to be called
 ** Post-Conditions: intializes certain variables
 *********************************************************************/
Game :: Game(){
    cout<< "game constructor called" << endl;
    this->cavesize = 0;
    
    this->spotx = 0;
    this->spoty = 0; //where the user is
    this->startx = 0;
    this->starty = 0;
    
    this->arrows = 3;
    
    this->wumpusx = 0;
    this->wumpusy = 0;
    this->startwumpusx = 0;
    this->startwumpusy = 0;
    
    this->wumpus = false;
    this->gold = false;
    this->alive = true;
    this->win = false;
    
    this->batsx=0;
    this->batsy=0;
    this->batx=0;
    this->baty=0;
    this->pitx=0;
    this->pity=0;
    this->pittx=0;
    this->pitty=0;
    this->goldx=0;
    this->goldy=0;
    
    //creates the arrays
    /*(for(int row = 0; row < this->cavesize; row++){
        vector<Room*> r;
        for(int column = 0; column < cavesize; column++){
            r.push_back(new Room);
        }
        caves.push_back(r);
    }
    */
    //caves = vector<vector<Room> > (cavesize, vector<Room>(cavesize));
    //cout << caves[0][0]->check_event() << endl;
    
}

/*********************************************************************
 ** Function: set_board
 ** Description: will set up arrays and board for game
 ** Parameters: none
 ** Pre-Conditions: none
 ** Post-Conditions: caves vector will be set up and positions wil  be set for starting game
 *********************************************************************/
void Game :: set_board(){
    //creates the arrays
    caves = vector<vector<Room> >(cavesize, vector<Room>(cavesize));
    
    cout << "board is being set up" << endl;
    //will set up the board
    int r = 0, c = 0, randomevent = 0, count = 0;
    for(int i = 0; i < cavesize; i++){
        r = rand() % cavesize;
        c = rand() % cavesize;
        if(count == 7)
            break;
        else if(caves.at(r).at(c).check_event() == 0){
            count++;
            randomevent = rand() % 7 + 1;
            this->caves.at(r).at(c).set_event(randomevent);
            if(randomevent == 1) // where the rope is
            {
                this->spotx = r;
                this->startx = r;
                this->spoty = c;
                this->starty = c;
            }
            else if(randomevent == 2)
            {
                this->wumpusx = r;
                this->wumpusy = c;
                this->startwumpusx = r;
                this->startwumpusy = c;
            }
            else if( randomevent == 3)
            {
                this->goldx = r;
                this->goldy = c;
            }
            else if( randomevent == 4)
            {
                this->batsx=r;
                this->batsy=c;
            }
            else if(randomevent == 5)
            {
                this->batx = r;
                this->baty = c;
            }
            else if( randomevent == 6)
            {
                this->pitx=r;
                this->pity=c;
            }
            else
            {
                this->pittx=r;
                this->pitty=c;
            }
        }
    }
}

/*********************************************************************
 ** Function: run
 ** Description: will run entire game
 ** Parameters: none
 ** Pre-Conditions: none
 ** Post-Conditions: game will start and end
 *********************************************************************/
void Game :: run(){
    this->welcome();
    
    do{
        hidden_coordinates();
        prompt();
        hidden_coordinates();
        percept();
    } while( this->alive || !win);
    
    if(!win)
    {
        bool error = true;
        do{
            error = true;
            
            cout << "Unfortunately it looks like you lost.. Would you like to play again with the same map or different map? Or would you like to quit? ('same'/'different'/'quit)" << endl;
            
            string answer;
            cin >> answer;
            
            if(answer == "same")
                game_reset();
            else if(answer == "different")
                game_restart();
            else if(answer == "quit")
                cout << "Thanks for playing!!" << endl;
            else{
                cout << "invalid input, please try again." << endl;
                error = false;
            }
            
        } while(!error);
    }
    else
        cout << "CONGRATULATIONS!! You made it back to where you started with the gold and succeeded in your mission to Hunt the Wumpus!" << endl;
    //game over here
    
}

/*********************************************************************
 ** Function: prompt
 ** Description:
 ** Parameters: none
 ** Pre-Conditions: none
 ** Post-Conditions: none
 *********************************************************************/
void Game :: prompt(){
    
    bool error = true;
    do{
        cout << "Would you like to move or shoot an arrow? ('move'/'arrow')" << endl;
        
        string answer;
        cin >> answer;
        
        error = true;
        if(answer == "move" || answer == "Move")
        {
            bool error2 = true;
            do{
                cout << "What direction would you like to move? (n/s/e/w)" << endl;
                
                string direction;
                cin >> direction;
                
                error2 = true;
                
                if(direction == "n" || direction == "w" || direction == "s" || direction == "e")
                    error2 = move_user(direction);
                
                else{
                    cout << "Invalid input, try again" << endl;
                    error2 = false;
                }
                
            } while(!error2);
            
        }
        
        else if( answer == "arrow" || answer == "Arrow")
        {
            if(arrows == 0){
                cout<< "You are out of arrows, why don't you choose to move instead?" << endl;
                error = false;
            }
            
            else
            {
                bool error2 = true;
                do{
                    cout << "What direction would you like to shoot? (n/s/e/w)" << endl;
                    
                    string direction;
                    cin >> direction;
                    
                    error2 = true;
                    
                    if(direction == "n" || direction == "w" || direction == "w" || direction == "e")
                        move_arrow(direction);
                    
                    else{
                        error2 = false;
                        cout << "Invaid input, try again" << endl;
                    }
                    
                } while(!error2);
            }
        }
        
        else{
            error = false;
            cout << "Invalid input, try again." << endl;
        }
        
    } while(!error);
}

/*********************************************************************
 ** Function: move_user
 ** Description:
 ** Parameters: int direction
 ** Pre-Conditions:
 ** Post-Conditions:
 *********************************************************************/
bool Game :: move_user(string direction){
    //for north
    if(direction == "n" && (spoty - 1) >= 0)
    {
        spoty -= 1;
        int whichevent = caves.at(spotx).at(spoty).check_event();
        if(whichevent > 0)
        {
            enact_event(whichevent);
        }
        else if(spotx == startx && spoty == starty && gold && wumpus && alive)
            this->win = true;
        
        return true;
    }
    
    //for south
    else if(direction == "s" && (spoty + 1)<= cavesize)
    {
        spoty += 1;
        int whichevent = caves.at(spotx).at(spoty).check_event();
        if(whichevent > 0)
        {
            enact_event(whichevent);
        }
        else if(spotx == startx && spoty == starty && gold && wumpus && alive)
            this->win = true;
        
        return true;
        
    }
    //for east
    else if(direction == "e" && (spotx + 1) <= cavesize)
    {
        spotx += 1;
        int whichevent = caves.at(spotx).at(spoty).check_event();
        if(whichevent > 0)
        {
            enact_event(whichevent);
        }
        else if(spotx == startx && spoty == starty && gold && wumpus && alive)
            this->win = true;
        
        return true;
        
    }
    //for west
    else if(direction == "w" && (spotx -1) >= 0)
    {
        spotx -= 1;
        int whichevent = caves.at(spotx).at(spoty).check_event();
        if(whichevent > 0)
        {
            enact_event(whichevent);
        }
        
        else if(spotx == startx && spoty == starty && gold && wumpus && alive)
            this->win = true;
        
        return true;
    }
    else{
        cout << "Out of bounds! Try again." << endl;
        return false;
    }
        
}

/*********************************************************************
 ** Function: enact_event
 ** Description:
 ** Parameters: int which
 ** Pre-Conditions:
 ** Post-Conditions:
 *********************************************************************/
void Game :: enact_event(int which){
    caves.at(spotx).at(spoty).encounter_access();
    if(which == 1)
        this->gold = true;
    else if(which == 2)
        this->superbat();
    else if(which == 3)
        this->alive = false;
    else if(which == 4)
        this->alive = false;
}

/*********************************************************************
 ** Function: move_arrow
 ** Description:
 ** Parameters: int direction
 ** Pre-Conditions:
 ** Post-Conditions:
 *********************************************************************/
void Game :: move_arrow(string direction){
    this->arrows--;
    //for north
    if(direction == "1")
        for(int i = 0; i <= 3; i++)
        {
            if(spoty == wumpusy && spotx + i == wumpusx)
            {
                cout << "The arrow flew into the room of the Wumpus and pierced the Wumpus right in the heart! The Wumpus is now dead" << endl;
                caves.at(spotx + i).at(spoty).clear_event();
                wumpus = true;
                return;
            }
        }
    
    //for south
    else if(direction == "2" )
        for(int i = 0; i <= 3; i++)
        {
            if(spoty == wumpusy && spotx - i == wumpusx)
            {
                cout << "The arrow flew into the room of the Wumpus and pierced the Wumpus right in the heart! The Wumpus is now dead" << endl;
                caves.at(spotx - i).at(spoty).clear_event();
                wumpus = true;
                return;
            }
        }
    
    //for east
    else if(direction == "3")
        for(int i = 0; i <= 3; i++)
        {
            if(spoty + i == wumpusy && spotx == wumpusx)
            {
                cout << "The arrow flew into the room of the Wumpus and pierced the Wumpus right in the heart! The Wumpus is now dead" << endl;
                caves.at(spotx).at(spoty + i).clear_event();
                wumpus = true;
                return;
            }
        }
    //for west
    else if(direction == "4")
        for(int i = 0; i <= 3; i++)
        {
            if(spoty - i == wumpusy && spotx == wumpusx)
            {
                cout << "The arrow flew into the room of the Wumpus and pierced the Wumpus right in the heart! The Wumpus is now dead" << endl;
                caves.at(spotx).at(spoty - i).clear_event();
                this->wumpus = true;
                return;
            }
        }
    //for when the arrow misses
    wumpus_flee();
    if(arrows == 0 && wumpus == false)
    {
        this->alive = false;
        cout << "You have run out of arrows! GAME OVER" << endl;
    }
}

/*********************************************************************
 ** Function: percept
 ** Description:
 ** Parameters: none
 ** Pre-Conditions: none
 ** Post-Conditions: none
 *********************************************************************/
void Game :: percept(){
    if(alive){
        for(int i = spotx - 1; i <= spotx + 1; i++){
            for(int j = spoty - 1; j <= spoty + 1; j++){
                if(caves.at(i).at(j).check_event() > 0 && (spotx != i && spoty != j))
                    this->caves.at(i).at(j).percept_access();
            }
        }
    }
    //the else would be that the player is no longer alive
}

/*********************************************************************
 ** Function: superbat
 ** Description:
 ** Parameters: none
 ** Pre-Conditions: none
 ** Post-Conditions: none
 *********************************************************************/
void Game :: superbat(){
    spotx = rand() % cavesize + 1;
    spoty = rand() % cavesize + 1;
    int which = caves.at(spotx).at(spoty).check_event();
    if( which > 0)
        enact_event(which);
}

/*********************************************************************
 ** Function: welcome
 ** Description: will intro user to game
 ** Parameters: none
 ** Pre-Conditions: none
 ** Post-Conditions: none
 *********************************************************************/
void Game :: welcome(){
    cout << "***********************************************" << endl;
    cout << "          Welcome to Hunt the Wumpus!          " << endl;
    cout << "***********************************************" << endl << endl;
    cout << "You are an adventure and you have ventured into a cave by sliding down a rope!" << endl << endl;
    cout << "Now your objectives are to:" << endl;
    cout << "    ->Find the Chest of Gold" << endl;
    cout << "    ->Hunt and kill the Wumpus using your arrows (you only have 3!)" << endl;
    cout << "    ->Find your way back to your rope, it will be your escape rope" << endl;
     cout << "***********************************************" << endl;
    cout << "Use your Percept ability to sense your surroundings!" << endl;
    cout << "When you think the Wumpus is in a room in a certain direction, shoot an arrow in that direction!" << endl;
    cout << "Good luck, Don't get eaten by the Wumpus!" << endl;
}

/*********************************************************************
 ** Function: wumpus_flee
 ** Description:
 ** Parameters: none
 ** Pre-Conditions: none
 ** Post-Conditions: none
 *********************************************************************/
void Game :: wumpus_flee(){
    int percent = rand() % 4 + 1;
    
    if(percent > 1)
    {
        cout << "You have Woken up the Wumpus and the Wumpus has fled to another room in cave!" << endl << endl;
        this->caves.at(wumpusx).at(wumpusy).clear_event();
        
        bool newposition = false;
        
        while(!newposition){
            int tempx = wumpusx;
            int tempy = wumpusy;
            
            this->wumpusx = rand() % cavesize + 1;
            this->wumpusy = rand() % cavesize + 1;
            
            if(wumpusx == spotx && wumpusy == spoty)
                newposition = newposition;
            
            else if(wumpusx == tempx && wumpusy == tempy)
                newposition = newposition;
            
            else if(caves.at(wumpusx).at(wumpusy).check_event() > 0)
                newposition = newposition;
            
            else
                newposition = true;
        }
        caves.at(wumpusx).at(wumpusy).set_event(2);
    }
    
}

/*********************************************************************
 ** Function: game_reset
 ** Description: will reset the game with the same map
 ** Parameters: none
 ** Pre-Conditions: none
 ** Post-Conditions: variables set back to what they were before
 *********************************************************************/
void Game :: game_reset(){
    this->spotx = startx;
    this->spoty = starty;
    this->arrows = 3;
    this->wumpusx = startwumpusx;
    this->wumpusy = startwumpusy;
    
    run();
}

/*********************************************************************
 ** Function: game_restart
 ** Description: wiill restart the game with different map
 ** Parameters: none
 ** Pre-Conditions: none
 ** Post-Conditions: new variables and game restarted
 *********************************************************************/
void Game :: game_restart(){
    for(int i = 0; i < cavesize; i++)
        for(int j = 0; j < cavesize; j++)
            caves.at(i).at(j).clear_event();
    
    bool error = true;
    do{
        cout << "What size would you like this time? (can not be less than 4)" << endl;
        
        int answer;
        cin >> answer;
        
        error = true;
        
        if(answer >= 4){
            this->cavesize = answer;
        }
        else
        {
            cout << "Invalid input, try again" << endl;
            error = false;
        }
        
    } while(!error);
    
    set_board();
    
    this->arrows = 3;
    
    run();
}

/*********************************************************************
 ** Function: hidden_cordinates
 ** Description:
 ** Parameters: none
 ** Pre-Conditions: none
 ** Post-Conditions:
 *********************************************************************/
void Game :: hidden_coordinates(){
    cout << "users spot row and column: " << spotx << " " << spoty << endl;
    cout << "wumpus spot row and column: " << wumpusx << " " << wumpusy << endl;
    cout << "bats 1: " << batsx << " " << batsy << endl;
    cout << "bats 2: " << batx << " " << baty << endl;
    cout << "pit 1: " << pitx << " " << pity << endl;
    cout << "pit2: " << pittx << " " << pitty << endl;
    cout << "gold: "<< goldx << " " << goldy << endl;
}
