//
//  History.h
//  CS32_Project1
//
//  Created by Ju Hyeon Park on 10/18/14.
//  Copyright (c) 2014 Ju Hyeon Park. All rights reserved.
//


#ifndef History_h
#define History_h

#include "globals.h"

/*
 you'll see they have one new command you can type: h for history. This command shows you how many brains have ever been dropped at each grid point: dot means 0, a letter character A through Y means 1 through 25 (A means 1, B means 2, etc.) and Z means 26 or more.
 
 
 
 * The constructor initializes a History object that corresponds to an Arena with nRows rows and nCols columns. You may assume (i.e., you do not have to check) that it will be called with a first argument that does not exceed MAXROWS and a second that does not exceed MAXCOLS, and that neither argument will be less than 1.
 * The record function is to be called to notify the History object that a brain has been dropped at a grid point. The function returns false if row r, column c is not within bounds; otherwise, it returns true after recording what it needs to. This function expects its parameters to be expressed in the same coordinate system as the arena (e.g., row 1, column 1 is the upper-left-most position).
 * The display function clears the screen and displays the history grid as the posted programs do. This function does clear the screen and write an empty line after the history grid; it does not print the Press enter to continue. after the display.
 

 */

class Arena;

class History
{
public:
    History(int nRows, int nCols);
    bool record(int r, int c);
    void display() const;
private:
    int m_grid[MAXROWS][MAXCOLS];
    int m_row;
    int m_col;
};

#endif