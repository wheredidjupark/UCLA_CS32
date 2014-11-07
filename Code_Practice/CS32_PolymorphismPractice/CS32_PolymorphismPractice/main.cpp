//
//  main.cpp
//  CS32_PolymorphismPractice
//
//  Created by Ju Hyeon Park on 11/6/14.
//  Copyright (c) 2014 Ju Hyeon Park. All rights reserved.
//

#include <iostream>
#include "Shape.h"
#include <string>

using std::string;
using std::cout;

void PrintAreaCircum(Shape &shape);


class Diary
{
public:
    Diary(const string & title);
    std::string getTitle();
    virtual void writeEntry(const string& entry);
    virtual std::string read(); //returns all the entries written in the diary so far
    virtual ~Diary()
    {
        
    }
private:
    std::string m_title;
    std::string m_entry;
};

Diary::Diary(const string& title)
{
    m_title = title;
}

string Diary::getTitle()
{
    return m_title;
}

void Diary::writeEntry(const string& entry)
{
    m_entry += entry;
}

string Diary::read()
{
    return m_entry;
}

class SecretDiary : public Diary
{
public:
    SecretDiary();
    virtual void writeEntry(const string& entry);
    virtual std::string read();
    virtual ~SecretDiary()
    {
        
    }
private:
};

SecretDiary::SecretDiary(): Diary("TOP-SECRET")
{
}

void SecretDiary::writeEntry(const string &entry)
{
    Diary::writeEntry(entry + ". We just used SecretDiary's write entry function"); //encode the entry
}

string SecretDiary::read()
{
    return (Diary::read() + ". We just used SecretDiary's read function");
}



int main()
{
    Circle c(5);
    Square s(10);
    
    PrintAreaCircum(c);
    
    SecretDiary a;
    //a.writeEntry("This is a test");
    
    Diary *b= &a;
    b->writeEntry("this is a test");
    
    cout << b->read();

    
//new exercise:
    
    
    return 0;
}

void PrintAreaCircum(Shape &shape)
{
    std::cerr <<shape.getArea();
    std::cerr <<std::endl;
    std::cerr <<shape.getCircum();

}