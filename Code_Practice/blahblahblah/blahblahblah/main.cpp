
#include <iostream>
#include <streambuf>
#include <string>
#include <algorithm>
#include <cstdlib>
#include <cassert>

using namespace std;

const char WALL = 'X';
const char DISCOVERED_SPACE = '@';
const char SPACE = '.';
const int ROW_SIZE = 10;
const int COL_SIZE = 10;

class File
{
public:
    File(string nm);
    string name() const;
    virtual void open() const = 0;
    virtual void redisplay() const;
    virtual ~File() {}
private:
    string m_name;
};

File::File(string nm)
: m_name(nm)
{}

string File::name() const
{
    return m_name;
}

void File::redisplay() const
{
    cout << "refresh the screen";
}

// ======================================= TextMsg
class TextMsg : public File
{
public:
    TextMsg(string nm);
    virtual void open() const;
    virtual ~TextMsg();
};

TextMsg::TextMsg(string nm)
: File(nm)
{}

void TextMsg::open() const
{
    cout << "open text message";
}

TextMsg::~TextMsg()
{
    cout << "Destroying " << name() << ", a text message" << endl;
}

// ======================================= Video
class Video : public File
{
public:
    Video(string nm, int playtime);
    virtual void open() const;
    virtual void redisplay() const;
    virtual ~Video();
private:
    int m_playingTime;
};

Video::Video(string nm, int playtime)
: File(nm), m_playingTime(playtime)
{}

void Video::open() const
{
    cout << "play " << m_playingTime << " second video";
}

void Video::redisplay() const
{
    cout << "replay video";
}

Video::~Video()
{
    cout << "Destroying " << name() << ", a video" << endl;
}

// ======================================= Picture
class Picture : public File
{
public:
    Picture(string nm);
    virtual void open() const;
    virtual ~Picture();
};

Picture::Picture(string nm)
: File(nm)
{}

void Picture::open() const
{
    cout << "show picture";
}

Picture::~Picture()
{
    cout << "Destroying the picture " << name() << endl;
}



// Return true if any of the strings in the array is empty, false
// otherwise.
bool anyEmpty(const string a[], int n)
{
    if (n <= 0)
        return false;
    if (a[0].empty())
        return true;
    return anyEmpty(a+1, n-1);
}

// Return the number of empty strings in the array.
int countEmpties(const string a[], int n)
{
    if (n <= 0)
        return 0;
    int t = a[0].empty();  // 1 if true, 0 if false
    return t + countEmpties(a+1, n-1);
}

// Return the subscript of the first empty string in the array.
// If no element is empty, return -1.
int firstEmpty(const string a[], int n)
{
    if (n <= 0)
        return -1;
    if (a[0].empty())
        return 0;
    int k = firstEmpty(a+1, n-1);
    if (k == -1)
        return -1;
    return 1 + k;  // element k of "the rest of a" is element 1+k of a
}

// Return the subscript of the least string in the array (i.e.,
// the smallest subscript m such that there is no k for which
// a[k] < a[m].  If the array has no elements to examine, return -1.
int indexOfLeast(const string a[], int n)
{
    if (n <= 0)
        return -1;
    if (n == 1)
        return 0;
    int k = 1 + indexOfLeast(a+1, n-1);  // indexOfLeast can't return -1 here
    return a[0] <= a[k] ? 0 : k;
}

// If all n2 elements of a2 appear in the n1 element array a1, in
// the same order (though not necessarily consecutively), then
// return true; otherwise (i.e., if the array a1 does not include
// a2 as a not-necessarily-contiguous subsequence), return false.
// (Of course, if a2 is empty (i.e., n2 is 0), return true.)
// For example, if a1 is the 7 element array
//    "stan" "kyle" "cartman" "kenny" "kyle" "cartman" "butters"
// then the function should return true if a2 is
//    "kyle" "kenny" "butters"
// or
//    "kyle" "cartman" "cartman"
// and it should return false if a2 is
//    "kyle" "butters" "kenny"
// or
//    "stan" "kenny" "kenny"
bool includes(const string a1[], int n1, const string a2[], int n2)
{
    if (n2 <= 0)
        return true;
    if (n1 < n2)
        return false;
    
    // If we get here, a1 and a2 are nonempty
    if (a1[0] == a2[0])
        return includes(a1+1, n1-1, a2+1, n2-1);  // rest of a1, rest of a2
    else
        return includes(a1+1, n1-1, a2, n2);  // rest of a1, all of a2
}


bool pathExists(char maze[][10], int sr, int sc, int er, int ec)
{
    if (maze[sr][sc] != '.')
        return false;
    
    if (sr == er  &&  sc == ec)
        return true;
    
    maze[sr][sc] = '@';  // anything non-'.' will do
    
    if (pathExists(maze, sr-1, sc, er, ec))
        return true;
    if (pathExists(maze, sr+1, sc, er, ec))
        return true;
    if (pathExists(maze, sr, sc-1, er, ec))
        return true;
    if (pathExists(maze, sr, sc+1, er, ec))
        return true;
    
    return false;
}



// Return the number of ways that all n2 elements of a2 appear
// in the n1 element array a1 in the same order (though not
// necessarily consecutively).  The empty sequence appears in a
// sequence of length n1 in 1 way, even if n1 is 0.
// For example, if a1 is the 7 element array
//    "stan" "kyle" "cartman" "kenny" "kyle" "cartman" "butters"
// then for this value of a2            the function must return
//    "stan" "kenny" "cartman"                      1
//    "stan" "cartman" "butters"                    2
//    "kenny" "stan" "cartman"                      0
//    "kyle" "cartman" "butters"                    3
int countIncludes(const string a1[], int n1, const string a2[], int n2)
{
    if (n2 <= 0)
        return 1;
    if (n1 < n2)
        return 0;
    
    // If we get here, a1 and a2 are nonempty
    int t = countIncludes(a1+1, n1-1, a2, n2);  // rest of a1, all of a2
    if (a1[0] == a2[0])
        return t + countIncludes(a1+1, n1-1, a2+1, n2-1);  // rest of a1, rest of a2
    else
        return t;
}

// Exchange two strings
void exchange(string& x, string& y)
{
    string t = x;
    x = y;
    y = t;
}

// Rearrange the elements of the array so that all the elements
// whose value is < barrier come before all the other elements,
// and all the elements whose value is > barrier come after all
// the other elements.  Upon return, firstNotLess is set to the index
// of the first element in the rearranged array that is >= barrier,
// or n if there is no such element, and firstGreater is set to
// the index of the first element that is > barrier, or n if
// there is no such element.
// In other words, upon return from the function, the array is a
// permutation of its original value such that
//   * for 0 <= i < firstNotLess, a[i] < barrier
//   * for firstNotLess <= i < firstGreater, a[i] == barrier
//   * for firstGreater <= i < n, a[i] > barrier
// All the elements < barrier end up in no particular order.
// All the elements > barrier end up in no particular order.
void takeSides(string a[], int n, string barrier, int& firstNotLess, int& firstGreater)
{
    if (n < 0)
        n = 0;
    
    // It will always be the case that just before evaluating the loop
    // condition:
    //  firstNotLess <= firstUnknown and firstUnknown <= firstGreater
    //  Every element earlier than position firstNotLess is < barrier
    //  Every element from position firstNotLess to firstUnknown-1 is
    //    == barrier
    //  Every element from firstUnknown to firstGreater-1 is not
    //     known yet
    //  Every element at position firstGreater or later is > barrier
    
    firstNotLess = 0;
    firstGreater = n;
    int firstUnknown = 0;
    while (firstUnknown < firstGreater)
    {
        if (a[firstUnknown] > barrier)
        {
            firstGreater--;
            exchange(a[firstUnknown], a[firstGreater]);
        }
        else
        {
            if (a[firstUnknown] < barrier)
            {
                exchange(a[firstNotLess], a[firstUnknown]);
                firstNotLess++;
            }
            firstUnknown++;
        }
    }
}

// Rearrange the elements of the array so that
// a[0] <= a[1] <= a[2] <= ... <= a[n-2] <= a[n-1]
// If n <= 1, do nothing.

void order(string a[], int n)
{
    if (n <= 1)
        return;
    
    // Split using a[0] as the barrier (any element would do).
    int firstNotLess;
    int firstGreater;
    takeSides(a, n, a[0], firstNotLess, firstGreater);
    
    // sort the elements < barrier
    order(a, firstNotLess);
    
    //  sort the elements > barrier
    order(a+firstGreater, n-firstGreater);
}