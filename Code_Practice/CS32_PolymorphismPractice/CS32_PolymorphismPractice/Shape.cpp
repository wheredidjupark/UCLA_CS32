//
//  Shape.cpp
//  CS32_PolymorphismPractice
//
//  Created by Ju Hyeon Park on 11/6/14.
//  Copyright (c) 2014 Ju Hyeon Park. All rights reserved.
//

#include "Shape.h"

Shape::Shape()
{
    //nothing. it's an abstract base class
}

Circle::Circle(float radius)
{
    m_radius = radius;
}

float Circle::getArea()
{
    return (3.14*m_radius*m_radius);
}

float Circle::getCircum()
{
    return (2*3.14*m_radius);
}

Square::Square(float side)
{
    m_side = side;
}

float Square::getArea()
{
    return (m_side * m_side);
}

float Square::getCircum()
{
    return (4*m_side);
}