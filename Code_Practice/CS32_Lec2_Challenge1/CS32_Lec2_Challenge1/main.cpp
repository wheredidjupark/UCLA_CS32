//
//  main.cpp
//  CS32_Lec2_Challenge1
//
//  Created by Ju Hyeon Park on 10/19/14.
//  Copyright (c) 2014 Ju Hyeon Park. All rights reserved.
//

#include <iostream>
using std::cout;

class Quadratic
{
public:
    Quadratic(int x2, int x1, int consta);
    ~Quadratic();
    int evaluate(int x);
private:
    int x_2;
    int x_1;
    int constant;
};


Quadratic::Quadratic(int x2, int x1, int consta)
{
    x_2 = x2;
    x_1 = x1;
    constant = consta;
    
}

Quadratic::~Quadratic()
{
    cout <<"goodbye";
}

int Quadratic::evaluate(int x)
{
    return x*x*x_2+x*x_1+constant;
}


#include <iostream>

int main(int argc, const char * argv[])
{
    Quadratic equation(4,3,5); //4x^2 + 3x +5
    cout << equation.evaluate(2) <<"\n";
    
    return 0;
}
