//
//  Set.cpp
//  CS32_Homework1
//
//  Created by Ju Hyeon Park on 10/21/14.
//  Copyright (c) 2014 Ju Hyeon Park. All rights reserved.
//

#include "Set.h"

Set::Set()
{
    m_size = 0;
}

bool Set::empty() const
{
    if(m_size == 0)
        return true;
    
    return false;
}

int Set::size() const
{
    return m_size;
}

bool Set::insert(const ItemType& value)
{
    int i =0;
    for(; i <m_size; i++) //check 0th~m_size item (theoretically up to 199th element)
    {
        if(set[i] == value)
            return false;
    }
    if(m_size >= DEFAULT_MAX_ITEMS)
    {
        return false;
    }
    else
    {
        set[m_size] = value;
        m_size++;
        return true;
    }
    return false;
}

bool Set::erase(const ItemType& value)
{
    if(this->contains(value))
    {
        int pos = 0;
        for(int i =0; i < m_size; i++) //find the position
        {
            if(set[i] == value)
            {
                pos = i;
            }
        }
        
        for(;pos+1 < m_size; pos++)
        {
            set[pos] = set[pos+1];
        }
        m_size--;
        return true;
    }
    else
    {
        return false;
    }
}

bool Set::contains(const ItemType& value) const
{
    for(int i =0; i < m_size; i++)
    {
        if(set[i] == value)
            return true;
    }
    return false;
}

bool Set::get(int i, ItemType &value) const
{
    if(i >= 0 && i < m_size)
    {
        value = set[i];
        return true;
    }
    else
        return false;
}
