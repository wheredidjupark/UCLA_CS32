
//
//  Zombie.h
//  CS32_Project1
//
//  Created by Ju Hyeon Park on 10/18/14.
//  Copyright (c) 2014 Ju Hyeon Park. All rights reserved.
//

#ifndef Zombie_h
#define Zombie_h

class Arena; //pointer to Arena just requires that Arena is a type of class

class Zombie
{
public:
    // Constructor
    Zombie(Arena* ap, int r, int c);
    
    // Accessors
    int  row() const;
    int  col() const;
    bool isDead() const;
    
    // Mutators
    void move();
    
private:
    Arena* m_arena;
    int    m_row;
    int    m_col;
    int    m_health;
    int    m_idleTurnsRemaining;
};


#endif
