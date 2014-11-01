//
//  main.cpp
//  StackClass Practice
//
//  Created by Ju Hyeon Park on 10/31/14.
//  Copyright (c) 2014 Ju Hyeon Park. All rights reserved.
//

#include <iostream>


typedef int ItemType;
const size_t STACK_MAXSIZE = 100;

class Stack
{
public:
    Stack();
    bool push(const ItemType& item);
    ItemType top();
    void pop();
    
private:
    ItemType stack[STACK_MAXSIZE];
    int m_size;
    
};

Stack::Stack()
{
    m_size=0;
}
bool Stack::push(const ItemType& item)
{
    if(m_size >= STACK_MAXSIZE)
        return false;
    
    stack[m_size] = item;
    m_size++;
    return true;
}

ItemType Stack::top()
{
    if(m_size == 0)
    {
        return NULL; //give no element
    }
    return stack[m_size-1];
}

void Stack::pop()
{
    if(m_size ==0)
    {
        std::cerr<<"no item in the Stack!";
        return;
    }
    
    stack[m_size-1] = NULL;
    m_size--;
}



int main(int argc, const char * argv[])
{
    Stack istack;
    istack.push(1);
    std::cout <<istack.top() <<std::endl;
    istack.pop();
    istack.pop();
    
}
