//
//  newSet.cpp
//  CS32_Homework1
//
//  Created by Ju Hyeon Park on 10/21/14.
//  Copyright (c) 2014 Ju Hyeon Park. All rights reserved.
//



#include "newSet.h"

Set::Set()
{
    set = new ItemType[DEFAULT_MAX_ITEMS];
    m_size = 0;
    m_capacity = DEFAULT_MAX_ITEMS;
}

Set::Set(int n)
{
    set = new ItemType[n];
    m_size = 0;
    m_capacity = n;
}

Set::Set(const Set & source)
{
    
    m_capacity = source.m_capacity;
    m_size = source.m_size;
    
    set = new ItemType[m_capacity];
    for(int i =0; i < m_size; i++)
    {
        set[i] = source.set[i];
    }
    
    
}

Set::~Set()
{
    delete [] set;
}

bool Set::empty() const
{
    
    //correct
    /*
    if(m_size == 0)
        return true;
    return false;
     */
    return size() == 0;
}// Return true if the set is empty, otherwise false.

Set& Set::operator=(const Set& source)
{
    /*
    delete [] set;
    m_size = source.m_size;
    m_capacity = source.m_capacity;
    
    set = new ItemType[m_capacity];
    for(int i=0; i <m_size; i++)
    {
        set[i] = source.set[i];
    }
    
   return (*this);
     */
    
    if (this != &source)
    {
        Set temp(source);
        swap(temp);
    }
    return *this;
}

int Set::size() const
{
    return m_size;
}// Return the number of items in the set.

bool Set::insert(const ItemType& value)
{
    int i =0;
    if(contains(value))
        return false;
    
    if(m_size >= m_capacity)
    {
        return false;
    }
    
    else
    {
        *(set+m_size) = value;
        m_size++;
        return true;
    }
    return false;
}
// Insert value into the set if it is not already present.  Return
// true if the value was actually inserted.  Return false if the
// value was not inserted (perhaps because it is already in the set
// or because the set has a fixed capacity and is full).

bool Set::erase(const ItemType& value)
{
    
    if(contains(value)) //contains(value) is equivalent to this->contains(value)
    {
        int pos = 0;
        for(int i =0; i < m_size; i++) //find the position
        {
            if(*(set+i) == value)
            {
                pos = i;
            }
        }
        
        for(;pos < m_size; pos++)
        {
            *(set+pos) = *(set+pos+1);
        }
        m_size--;
        return true;
    }
    else
    {
        return false;
    }

}
// Remove the value from the set if present.  Return true if the
// value was removed; otherwise, leave the set unchanged and
// return false.

bool Set::contains(const ItemType& value) const
{
    for(int i =0; i < m_size; i++)
    {
        if(*(set+i) == value)
            return true;
    }
    return false;
}
// Return true if the value is in the set, otherwise false.

bool Set::get(int i, ItemType& value) const
{
    if(i >= 0 && i < m_size)
    {
        value = *(set+i);
        return true;
    }
    else
        return false;
}
// If 0 <= i < size(), copy into value an item in the set and
// return true.  Otherwise, leave value unchanged and return false.
// (See below for details about this function.)

void Set::swap(Set& other)
{
    //long and unnecessary amount of work...
    /*
    ItemType temp[other.m_capacity]; //stores all other.
    
    for(int i=0; i < other.m_size; i++)
    {
        temp[i] = other.set[i];
    }
    
    delete [] other.set;
    other.set = new ItemType[m_capacity];
    
    for(int i=0; i < m_size; i++)
    {
        other.set[i] = set[i];
    }
    
    delete [] set;
    set = new ItemType[other.m_capacity];
    
    for(int i =0; i <other.m_size; i++)
    {
        set[i] = temp[i];
    }
    */
    
    //shorter version
    ItemType* tempData = set;
    set = other.set;
    other.set = tempData;
     
    int copy_temp = m_size;
    m_size = other.m_size;
    other.m_size = copy_temp;
    
    int copy_temp_capacity = m_capacity;
    m_capacity = other.m_capacity;
    other.m_capacity = copy_temp_capacity;
    
}
// Exchange the contents of this set with the other one.

/*
 
 
 Set a(1000);   // a can hold at most 1000 distinct items
 Set b(5);      // b can hold at most 5 distinct items
 Set c;         // c can hold at most DEFAULT_MAX_ITEMS distinct items
 ItemType v[6] = { six distinct values of the appropriate type };
 
 // No failures inserting 5 distinct items into b
 for (int k = 0; k < 5; k++)
 assert(b.insert(v[k]));
 
 // Failure if we try to insert a sixth distinct item into b
 assert(!b.insert(v[5]));
 
 // When two Sets' contents are swapped, their capacities are swapped
 // as well:
 a.swap(b);
 assert(!a.insert(v[5]));

*/