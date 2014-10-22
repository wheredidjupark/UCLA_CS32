//
//  StudentSet.h
//  CS32_Homework1
//
//  Created by Ju Hyeon Park on 10/21/14.
//  Copyright (c) 2014 Ju Hyeon Park. All rights reserved.
//

#ifndef StudentSet_h
#define StudentSet_h



#include "Set.h"

class StudentSet
{
public:
    StudentSet();       // Create an empty student set.
    ~StudentSet();
    StudentSet(const StudentSet& a);
    
    StudentSet& operator=(const StudentSet& a);
    
    bool add(unsigned long id);
    // Add a student id to the StudentSet.  Return true if and only if the
    // id was actually added.
    
    int size() const;  // Return the number of ids in the StudentSet.
    
    void print() const;
    // Print every student id in the StudentSet exactly once, one per line.
    
private:
    Set *student_item;
};

#endif //StudentSet_h
