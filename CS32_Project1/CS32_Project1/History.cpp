//
//  History.cpp
//  CS32_Project1
//
//  Created by Ju Hyeon Park on 10/18/14.
//  Copyright (c) 2014 Ju Hyeon Park. All rights reserved.
//

#include "History.h"
#include <iostream>
#include "Arena.h"
#include "globals.h"
using namespace std;



/*
 you'll see they have one new command you can type: h for history. This command shows you how many brains have ever been dropped at each grid point: dot means 0, a letter character A through Y means 1 through 25 (A means 1, B means 2, etc.) and Z means 26 or more.
 
 
 
 * The constructor initializes a History object that corresponds to an Arena with nRows rows and nCols columns. You may assume (i.e., you do not have to check) that it will be called with a first argument that does not exceed MAXROWS and a second that does not exceed MAXCOLS, and that neither argument will be less than 1.
 * The display function clears the screen and displays the history grid as the posted programs do. This function does clear the screen and write an empty line after the history grid; it does not print the Press enter to continue. after the display.
 
 
 */

History::History(int nRows, int nCols)
{
    m_row = nRows;
    m_col = nCols;
    
       for(int i = 0; i < nRows; i++)
    {
        for(int j =0; j < nCols; j++)
        {
            m_grid[i][j] = 0;
        }
    }
}

//The record function is to be called to notify the History object that a brain has been dropped at a grid point. The function returns false if row r, column c is not within bounds; otherwise, it returns true after recording what it needs to. This function expects its parameters to be expressed in the same coordinate system as the arena (e.g., row 1, column 1 is the upper-left-most position).

bool History::record(int r, int c) //PURELY DID IT WITHOUT HELP XDDD
{
    if(r < 1 || r > MAXROWS || c < 1 || c > MAXCOLS)
        return false;
    else
    {
        m_grid[r-1][c-1]++; // notifies the History object that a brain has been dropped at a grid point.
        return true;
    }
}


void History::display() const //PURELY DID IT WITHOUT HELP XDDD
{
    clearScreen();
    for(int i =0; i <m_row; i++)
    {
        for(int j=0; j <m_col; j++)
        {
            if(m_grid[i][j] == 0)
                cout << ".";
            else
            {
                if(m_grid[i][j] < 26)
                {
                    cout << static_cast<char>('A' + m_grid[i][j]);
                }
                else
                {
                    cout <<'Z';
                }
            } // not represented by A and Z at the moment...

        }
        cout <<endl;
    }
    cout << endl;
}
