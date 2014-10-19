
//
//  Game.h
//  CS32_Project1
//
//  Created by Ju Hyeon Park on 10/18/14.
//  Copyright (c) 2014 Ju Hyeon Park. All rights reserved.
//

#ifndef Game_h
#define Game_h

#include <string>

class Arena;


bool charToDir(char ch, int& dir); //only used by Game class
bool recommendMove(const Arena& a, int r, int c, int& bestDir); //used by only Game class
int computeDanger(const Arena& a, int r, int c); //used by recommendMove function.

class Arena;

class Game
{
public:
    // Constructor/destructor
    Game(int rows, int cols, int nZombies);
    ~Game();
    
    // Mutators
    void play();
    
private:
    Arena* m_arena;
    
    // Helper functions
    std::string takePlayerTurn();
};


#endif
