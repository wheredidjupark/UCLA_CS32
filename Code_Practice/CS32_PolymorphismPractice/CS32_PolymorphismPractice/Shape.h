//
//  Shape.h
//  CS32_PolymorphismPractice
//
//  Created by Ju Hyeon Park on 11/6/14.
//  Copyright (c) 2014 Ju Hyeon Park. All rights reserved.
//

#ifndef Shape_h
#define Shape_h

class Shape
{
public:
    Shape();
    virtual float getArea(){ return 0;}
    virtual float getCircum(){return 0;}
private:
};

class Circle : public Shape
{
public:
    Circle(float radius);
    virtual float getArea();
    virtual float getCircum();
private:
    float m_radius;
};

class Square : public Shape
{
public:
    Square(float side);
    virtual float getArea();
    virtual float getCircum();
private:
    float m_side;
};

#endif /* defined(__CS32_PolymorphismPractice__Shape__) */
