
//
//  Arena.h
//  CS32_Project1
//
//  Created by Ju Hyeon Park on 10/18/14.
//  Copyright (c) 2014 Ju Hyeon Park. All rights reserved.
//

#ifndef Arena_h
#define Arena_h

#include <string>
#include "globals.h"
#include "History.h" //ADDED

class Player;
class Zombie;

class Arena
{
public:
    // Constructor/destructor
    Arena(int nRows, int nCols);
    
    ~Arena();
    
    // Accessors
    int     rows() const;
    int     cols() const;
    Player* player() const;
    int     zombieCount() const;
    int     getCellStatus(int r, int c) const;
    int     numberOfZombiesAt(int r, int c) const;
    void    display(std::string msg) const;
    
    // Mutators
    void setCellStatus(int r, int c, int status);
    bool addZombie(int r, int c);
    bool addPlayer(int r, int c);
    void moveZombies();
    History& history(); //ADDED
    
private:
    int     m_grid[MAXROWS][MAXCOLS];
    int     m_rows;
    int     m_cols;
    Player* m_player;
    Zombie* m_zombies[MAXZOMBIES];
    int     m_nZombies;
    int     m_turns;
    History m_history; //ADDED. didn't know i should be putting the private here... 
    
    // Helper functions
    void checkPos(int r, int c) const;
    bool isPosInBounds(int r, int c) const;
};

#endif
