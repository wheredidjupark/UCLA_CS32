//
//  globals.h
//  CS32_Project1
//
//  Created by Ju Hyeon Park on 10/18/14.
//  Copyright (c) 2014 Ju Hyeon Park. All rights reserved.
//

#ifndef globals_h
#define globals_h


///////////////////////////////////////////////////////////////////////////
// Manifest constants
///////////////////////////////////////////////////////////////////////////

class Arena;

int randInt(int lowest, int highest); //used by Zombie and Game class
bool attemptMove(const Arena& a, int dir, int& r, int& c); //used by Zombie & Player class. also used by recommendMove function.
void clearScreen(); //not used by any class


const int MAXROWS = 20;              // max number of rows in the arena
const int MAXCOLS = 20;              // max number of columns in the arena
const int MAXZOMBIES = 100;          // max number of zombies allowed
const int INITIAL_ZOMBIE_HEALTH = 2; // initial zombie health
const int POISONED_IDLE_TIME = 1;    // poisoned zombie idles this many
//   turns between moves

const int NORTH = 0;
const int EAST  = 1;
const int SOUTH = 2;
const int WEST  = 3;
const int NUMDIRS = 4;

const int EMPTY      = 0;
const int HAS_BRAIN  = 1;

#endif
