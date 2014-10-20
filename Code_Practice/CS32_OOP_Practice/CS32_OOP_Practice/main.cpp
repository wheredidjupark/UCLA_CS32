//
//  main.cpp
//  CS32_OOP_Practice
//
//  Created by Ju Hyeon Park on 10/19/14.
//  Copyright (c) 2014 Ju Hyeon Park. All rights reserved.
//

#include <iostream>
using std::cout;

class Stomach
{
public:
    Stomach();
    ~Stomach();
    void eat();
private:
    int gas;
};

Stomach::Stomach()
{
    gas = 0;
}

Stomach::~Stomach()
{
    while (gas-- > 0)
        cout <<"pffft!";
}

void Stomach::eat()
{
    gas++;
}

int main(int argc, const char * argv[])
{
    Stomach s;
    
    s.eat();
    
    return 0;
}
