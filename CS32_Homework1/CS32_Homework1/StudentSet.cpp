//
//  StudentSet.cpp
//  CS32_Homework1
//
//  Created by Ju Hyeon Park on 10/21/14.
//  Copyright (c) 2014 Ju Hyeon Park. All rights reserved.
//

#include "StudentSet.h"
#include "Set.h"
#include <iostream>

StudentSet::StudentSet()
{
    student_item = new Set;
}


bool StudentSet::add(unsigned long id)
{
    return student_item->insert(id);
}


int StudentSet::size() const  // Return the number of ids in the StudentSet.
{
    return student_item->size();
}

void StudentSet::print() const
{
    ItemType temp;
    for(int i =0; i < student_item->size(); i++)
    {
        student_item->get(i, temp);
        std::cout <<temp;
    }
}
