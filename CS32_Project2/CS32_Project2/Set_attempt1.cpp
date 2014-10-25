//
//  Set.cpp
//  CS32_Project2
//
//  Created by Ju Hyeon Park on 10/22/14.
//  Copyright (c) 2014 Ju Hyeon Park. All rights reserved.
//

#include "Set.h"


Set::Set()
{
    next = nullptr;
    prev = nullptr;
}

bool Set::empty() const
{
    return size() == 0; //the easiest method
    
    //longer method. you are basically writing the size() again...
    /*
    int i =0;
    Set lastStored = *this;
    while( lastStored.next != nullptr)
    {
        i++;
        lastStored.next = lastStored.next->next;
    }
    
    if(i == 0)
        return true;
    else
        return false;
     */

}


Set::Set(const Set& source)
{

}



Set::~Set()
{
    
    
}

Set::Set &operator=(const Set& source)
{
    
    return *this;
}



int Set::size() const
{
    //my first attempt: works but less clean.
    /*
    int i = -1;
   
    Set end = *this;
    while( end.next != nullptr) //until you find the last item, increment each cycle by 1.
    {
        i++;
        end.next = end.next->next;
    }
    
    return i;
     */
    
    int i =0;
    Set lastStored = *this;
    while( lastStored.next != nullptr)
    {
        i++;
        lastStored.next = lastStored.next->next;
    }
    return i;

}

bool Set::insert(const ItemType& value)
{
 if(contains(value))
     return false;
    
    //go to the very end of our linked list
    
    Set *end = this;
    while(end->next != nullptr)
    {
        end = end->next;
    }
    //reached the last Set pointer now.
    
    Set *newest = new Set; //we add the value at the end of our linked list
    newest->m_data = value;
    newest->next = nullptr;
    newest->prev = end;
    end->next = newest;
    return true;

}

bool Set::erase(const ItemType& value)
{
    if(this->contains(value))
    {
        //check for the location
        Set *check = this;
        
        while(check->m_data != value)
        {
            check = check->next;
        }
        if(check->next == nullptr) //case 1: if the value is at the end of our linked list
        {
            Set *previous = check->prev;
            delete check;
            previous->next = nullptr;
        }
        else //case2: if the value is in some place other than the end.
        {
            Set *previous = check->prev;
            Set *thenext = check->next;
            previous->next = check->next;
            thenext->prev = check->prev;
            delete check;

        }
    }
    else //case 3: value is not in the linked list
    {
        return false;
    }
    
    return false;}

bool Set::contains(const ItemType& value) const
{
    ItemType target;
    Set finder = *this;
    target = this->m_data;
    while(target != value && finder.next != nullptr)
    {
        finder.next = finder.next->next; //the reason why you want finder.next != nullptr
        target = finder.m_data;
    }
    if(target == value)
        return true;
    
    return false;
}

bool Set::get(int pos, ItemType& value) const //need things to fix.....
{
    Set finder = *this; //goes to the position. start with the Set that has m_data... set it as the 0th

    if(pos < 0 || pos >= size())
    {
        return false;
    }
    else
    {
        for(int k=0, i =size(); k < i; k++)
        {
            finder.next = finder.next->next;
        }
        value = finder.m_data;
        return true;
    }
}

void Set::swap(Set&other)
{
    
    Set copy_other = other; //copies the other.
    other.next->prev = next->prev;
    other.next = next;
    next->prev = copy_other.next->prev;
    next = copy_other.next;
     
}