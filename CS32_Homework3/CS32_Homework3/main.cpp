//
//  main.cpp
//  CS32_Homework3
//
//  Created by Ju Hyeon Park on 11/7/14.
//  Copyright (c) 2014 Ju Hyeon Park. All rights reserved.
//
//You are developing software for Crapple's next device, the iBad. Among its capabilities is the ability to access video, audio, and text files. Every file has a name. Each kind of file has a distinctive action that's taken when it is opened. A client can ask to redisplay a file; for most kinds of files, this just refreshes the screen, but some kinds of files may do something interesting. Declare and implement the classes named in the sample program below in such a way that the program compiles, executes, and produces exactly the output shown. (A real implementation would actually play videos and show pictures, but for now we'll stick to simple text output.) Do not change the implementations ofopenAndRedisplay or main.


//redisplay needs to be virtual

#include <iostream>
#include <string>
using namespace std;

//Your declarations and implementations would go here
class File
{
public:
    File(string s);
    string name() const;
    virtual void open() const=0;
    virtual void redisplay() const;
    virtual ~File();
private:
    string m_name;
};

File::File(string s)
{
    m_name = s;
}
string File::name() const
{
    return m_name;
}

void File::redisplay() const
{
    cout <<"refresh the screen";
}

File::~File()
{
    //do nothing..
}

////////////////
////////////////

class TextMsg : public File
{
public:
    TextMsg(string s) : File(s)
    {}
    virtual void open() const;
    virtual ~TextMsg();
};

void TextMsg::open() const
{
    cout <<"open text message";
}

TextMsg::~TextMsg()
{
    cout << "Destroying " <<File::name() <<", a text message"<<endl;
}
////////////////
////////////////

class Video : public File
{
public:
    Video(string s, int seconds);
    virtual void open() const;
    virtual void redisplay() const;
    virtual ~Video();
private:
    int m_length;
};

Video::Video(string s,int seconds):File(s)
{
    m_length = seconds;
}

void Video::open() const
{
    cout <<"play " << m_length <<" second video";
}

void Video::redisplay() const
{
    cout <<"replay video";
}

Video::~Video()
{
    cout <<"Destroying " <<File::name() << ", a video" <<endl;
}

////////////////
////////////////

class Picture : public File
{
public:
    Picture(string s) : File(s)
    {}
    virtual void open() const;
    virtual ~Picture();
};

void Picture::open() const
{
    cout <<"show picture";
}

Picture::~Picture()
{
    cout <<"Destroying the picture " << File::name() <<endl;
}


//////////////////
//////////////////
//BELOW ARE CODES GIVEN BY THE CLASS

void openAndRedisplay(const File* f)
{
    cout << f->name() << ": ";
    f->open();
    cout << endl << "Redisplay: ";
    f->redisplay();
    cout << endl;
}

int main()
{
    File* files[4];
    files[0] = new TextMsg("fromFred.txt");
    // Videos have a name and running time
    files[1] = new Video("kitty.mpg", 57);
    files[2] = new Picture("poster.jpg");
    files[3] = new Picture("still.jpg");
    //files[4] = new File("helloworld"); //error! Abstract Data Type cannot be built (to test the build, change the size of the array to 5)
    
    for (int k = 0; k < 4; k++)
        openAndRedisplay(files[k]);
    
    // Clean up the files before exiting
    cout << "Cleaning up" << endl;
    for (int n = 0; n < 4; n++)
        delete files[n];
}

//Output produced:
/*
fromFred.txt: open text message
Redisplay: refresh the screen
kitty.mpg: play 57 second video
Redisplay: replay video
poster.jpg: show picture
Redisplay: refresh the screen
still.jpg: show picture
Redisplay: refresh the screen
Cleaning up
Destroying fromFred.txt, a text message
Destroying kitty.mpg, a video
Destroying the picture poster.jpg
Destroying the picture still.jpg
*/