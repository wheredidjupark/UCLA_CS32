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

bool anyEmpty(const string a[], int n)
{
    if(n==0)
        return false;
    
    bool first;
    if(a[0] == "")
        first = true;
    else
    {
        first = anyEmpty(a+1,n-1);
    }
    
    return first;
}

// Return the number of empty strings in the array.
int countEmpties(const string a[], int n)
{
    if(n ==0)
        return 0;
    
    int b =0;
    if(a[0] == "")
    {
        b++;
    }
    return b + countEmpties(a+1, n-1); //b+ previous counts! //we don't have to know what that countEmpties do here! all we know is that it returns the value we want! :D
    
}

/*
 if(n==0) //stopping condition to check initially.
 {
 return -1;
 }
 if(a[0] == "")
 {
 return 0;
 }
 
 int k = firstEmpty(a+1, n-1); //call the recursive function only if you can't find it. (i.e. recursion stops when we find the desired condition -> a[0] == "" or n==0
 
 if(k ==-1) //if k is still -1 (i.e. it hasn't found
 return -1;
 //else...
 return 1 + k; // we are not considering the 1st element. we consider 1~ n-1 position.
 */
// Return the subscript of the first empty string in the array.
// If no element is empty, return -1.
int firstEmpty(const string a[], int n)
{
    /*
     if(anyEmpty(a,n) == false)
     return -1;
     
     if(n==0)
     return -1;
     
     int pos =0;
     if(a[n-1] == "")
     {
     pos = n-1;
     }
     else
     {
     pos = firstEmpty(a, n-1);
     }
     
     return pos;
     */
    
    /*
     if(n ==0)
     return -1;
     if(anyEmpty(a,n) == false)
     {
     return -1;
     }
     
     int check = 0;
     if(a[0] == "")
     {
     check = 1;
     }
     else check =0;
     
     return n - firstEmpty(a+1, n-1) - check;
     */
    
    
    if(n==0)
        return -1;
    if(a[0] == "")
        return 0;
    //else....
    int k = firstEmpty(a+1, n-1); //assume k finds the position of the firstempty
    if(k==-1)
        return -1;
    //else... (i.e. if k does give us location of the first empty in the n-1 size array)
    return 1+k; //then add this first element's location + k-th element.
}

// Return the subscript of the least string in the array (i.e.,
// the smallest subscript m such that there is no k for which
// a[k] < a[m].)  If the array has no elements to examine, return -1.
int indexOfLeast(const string a[], int n)
{
    if(n==0)
        return -1;
    if(n==1) //if there is only one element in the array, then you only need to return this...
        return 0;
    
    int k = indexOfLeast(a+1, n-1); //we first let k find the least string in the n-1 array. we just know it finds it (WITHOUT QUESTION!!!!!)
    if(a[0] > a[1+k]) //we compare the elements together... (1+k because 1 is the current 0th position of the array)
    {
        return 1+k;
    }
    else
    {
        return 0;
    }
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
    if(n2 <= 0)
        return true;
    if(n2 > n1)
        return false;

    if(a1[0] == a2[0])
    {
        return includes(a1+1, n1-1, a2+1,n2-1); //let this check for last 'n1-1' elements of the a1 array
    }
    else
    {
        return includes(a1, n1, a2+1, n2-1); //move to the next element.
    }

    
}

bool pathExists(char maze[][COL_SIZE], int sr, int sc, int er, int ec)
{
    if(maze[sr][sc] == WALL)
        return false;
    
    //If the start location is equal to the ending location, then we've solved the maze, so return true. Mark the start location as visted. For each of the four directions, If the location one step in that direction (from the start location) is unvisited, then call pathExists starting from that location (and ending at the same ending location as in the current call). If that returned true, then return true. Return false.
    
    if(sr == er && sc == ec)
        return true;
    
    maze[sr][sc] = DISCOVERED_SPACE;
    
    
    if(maze[sr-1][sc] == SPACE)
    {
        if(pathExists(maze, sr-1, sc, er, ec))
            return true;
    }
    if(maze[sr][sc+1] == SPACE)
    {
        if(pathExists(maze, sr, sc+1, er, ec))
            return true;
    }
    if(maze[sr+1][sc] == SPACE)
    {
        if(pathExists(maze, sr+1, sc, er, ec))
            return true;
    }
    if(maze[sr][sc-1] == SPACE)
    {
        if(pathExists(maze, sr, sc-1, er, ec))
            return true;
    }
    
    return false;
    
}


int countIncludes(const string a1[], int n1, const string a2[], int n2)
{
    if(n1 <= 0) //empty identifier sequence cannot be compared to the source sequence, a2.
        return 0;
    if(n2 <= 0) //empty source sequence (i.e. n2=0) appears in a sequence of length n1 in 1 way.
        return 1;
    if(n2 > n1)
        return 0;
    int count;
    
    if(a1[0] == a2[0])
    {
        count = countIncludes(a1+1,n1-1 ,a2+1 ,n1+1) + countIncludes(a1+1, n1-1, a2, n2);// the first part calculates for the first combo possibility the second accounts for other possibilities
    }
    else
    {
        count = countIncludes(a1+1, n1-1, a2, n2); //move to the next element of a1
    }
    
    return count;
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
    if(n<= 1)
        return;
    
    order(a,n-1); //organizes all the first n-1 elements for you! (i.e. a[0] <= a[1] <= a[2] <= a[3] <= ... a[n-2]
    int firstNotLess = 0;
    int firstGreater = n;
    takeSides(a, n, a[n-1], firstNotLess, firstGreater);
    
}

/* (Hint: Using the takeSides function, the order function can be written in fewer than eight short lines of code.)
 
 You will not receive full credit if for nonnegative n1 and n2, the countIncludes function causes a string comparison function (e.g. <= or ==) to be called more thanfactorial(n1+1) / (factorial(n2)*factorial(n1+1-n2)) times. The countIncludes function can be implemented in a way that meets the spec without calling any of the functions in problem 2. (If you implement it so that it does call one of those functions, then it will probably not meet the limit stated in the first sentence of this paragraph.)
 
 For this part of the homework, you will turn in one file named tree.cpp that contains the four functions above and nothing more.
 */

void testone(int n)
{
    static char maze1[10][10] = {
        { 'X', 'X', 'X', 'X', 'X', 'X', 'X', 'X', 'X', 'X' },
        { 'X', '.', 'X', '.', '.', 'X', '.', '.', '.', 'X' },
        { 'X', '.', 'X', 'X', '.', 'X', '.', 'X', 'X', 'X' },
        { 'X', '.', '.', '.', '.', 'X', '.', 'X', '.', 'X' },
        { 'X', 'X', '.', 'X', '.', 'X', '.', '.', '.', 'X' },
        { 'X', 'X', 'X', '.', '.', 'X', '.', 'X', '.', 'X' },
        { 'X', '.', '.', '.', 'X', '.', '.', '.', 'X', 'X' },
        { 'X', '.', 'X', 'X', '.', '.', 'X', '.', 'X', 'X' },
        { 'X', '.', '.', '.', '.', 'X', '.', '.', '.', 'X' },
        { 'X', 'X', 'X', 'X', 'X', 'X', 'X', 'X', 'X', 'X' },
    };
    
    static char maze2[10][10] = {
        { 'X', 'X', 'X', 'X', 'X', 'X', 'X', 'X', 'X', 'X' },
        { 'X', '.', 'X', '.', '.', 'X', '.', '.', '.', 'X' },
        { 'X', '.', 'X', 'X', '.', 'X', '.', 'X', 'X', 'X' },
        { 'X', '.', '.', '.', '.', 'X', '.', 'X', '.', 'X' },
        { 'X', 'X', '.', 'X', '.', 'X', '.', '.', '.', 'X' },
        { 'X', 'X', 'X', '.', 'X', 'X', '.', 'X', '.', 'X' },
        { 'X', '.', '.', '.', 'X', '.', '.', '.', 'X', 'X' },
        { 'X', '.', 'X', 'X', '.', '.', 'X', '.', 'X', 'X' },
        { 'X', '.', '.', '.', '.', 'X', '.', '.', '.', 'X' },
        { 'X', 'X', 'X', 'X', 'X', 'X', 'X', 'X', 'X', 'X' },
    };
    
    static char maze3[10][10] = {
        { 'X', 'X', 'X', 'X', 'X', 'X', 'X', 'X', 'X', 'X' },
        { 'X', 'X', '.', '.', '.', '.', '.', 'X', 'X', 'X' },
        { 'X', '.', '.', 'X', 'X', '.', '.', '.', '.', 'X' },
        { 'X', '.', '.', '.', 'X', '.', '.', '.', 'X', 'X' },
        { 'X', '.', 'X', '.', 'X', 'X', 'X', '.', '.', 'X' },
        { 'X', 'X', 'X', 'X', '.', '.', 'X', '.', '.', 'X' },
        { 'X', 'X', '.', '.', '.', '.', 'X', '.', '.', 'X' },
        { 'X', '.', '.', '.', '.', '.', '.', '.', 'X', 'X' },
        { 'X', '.', '.', 'X', 'X', 'X', 'X', 'X', 'X', 'X' },
        { 'X', 'X', 'X', 'X', 'X', 'X', 'X', 'X', 'X', 'X' },
    };
    
    static char maze4[10][10] = {
        { 'X', 'X', 'X', 'X', 'X', 'X', 'X', 'X', 'X', 'X' },
        { 'X', 'X', '.', '.', '.', '.', '.', 'X', 'X', 'X' },
        { 'X', '.', '.', 'X', 'X', '.', '.', '.', '.', 'X' },
        { 'X', '.', '.', '.', 'X', '.', '.', '.', 'X', 'X' },
        { 'X', '.', 'X', '.', 'X', 'X', 'X', '.', '.', 'X' },
        { 'X', 'X', 'X', 'X', '.', '.', 'X', '.', '.', 'X' },
        { 'X', 'X', '.', '.', '.', '.', 'X', '.', '.', 'X' },
        { 'X', '.', '.', '.', '.', '.', 'X', '.', 'X', 'X' },
        { 'X', '.', '.', 'X', 'X', 'X', 'X', 'X', 'X', 'X' },
        { 'X', 'X', 'X', 'X', 'X', 'X', 'X', 'X', 'X', 'X' },
    };
    
    string a[10] = {
        "cow", "pig", "", "rat", "", "cat", "", "", "duck", "owl"
    };
    string x[10] = {
        "cow", "pig", "duck", "rat", "", "cat", "", "", "stag", "owl"
    };
    string y[10] = {
        "eel", "owl", "ant", "frog", "cat", "cow", "", "bat", "pig", "dog"
    };
    string b[4] = { "owl", "ant", "cat", "bat" };
    string c[8] = { "cat", "stag", "rat", "dog", "stag", "rat", "owl" };
    string d[12] = {
        "cat", "dog", "rat", "cat", "rat", "owl",
        "dog", "cat", "rat", "stag", "rat", "owl"
    };
    string e[12] = {
        "cat", "cat", "cat", "dog", "dog", "owl",
        "owl", "rat", "rat", "rat", "rat", "stag"
    };
    
    switch (n)
    {
        default: {
            assert(false);
        } break; case  1: {
            assert(anyEmpty(a, 10));
        } break; case  2: {
            assert(anyEmpty(a, 8));
        } break; case  3: {
            assert(anyEmpty(a+2, 8));
        } break; case  4: {
            assert(!anyEmpty(a+8, 2));
        } break; case  5: {
            assert(anyEmpty(a+6, 2));
        } break; case  6: {
            assert(!anyEmpty(a, 1));
        } break; case  7: {
            assert(anyEmpty(a+2, 1));
        } break; case  8: {
            assert(!anyEmpty(a, 0)  &&  !anyEmpty(a+2, 0));
        } break; case  9: {
            assert(countEmpties(a, 10) == 4);
        } break; case 10: {
            assert(countEmpties(a, 8) == 4);
        } break; case 11: {
            assert(countEmpties(a+2, 8) == 4);
        } break; case 12: {
            assert(countEmpties(a+8, 2) == 0);
        } break; case 13: {
            assert(countEmpties(a+6, 2) == 2);
        } break; case 14: {
            assert(countEmpties(a, 1) == 0);
        } break; case 15: {
            assert(countEmpties(a+2, 1) == 1);
        } break; case 16: {
            assert(countEmpties(a, 0) == 0  &&  countEmpties(a+2, 0) == 0);
        } break; case 17: {
            assert(firstEmpty(a, 10) == 2);
        } break; case 18: {
            assert(firstEmpty(a, 8) == 2);
        } break; case 19: {
            assert(firstEmpty(a+2, 8) == 0);
        } break; case 20: {
            assert(firstEmpty(a+8, 2) == -1);
        } break; case 21: {
            assert(firstEmpty(a+6, 2) == 0);
        } break; case 22: {
            assert(firstEmpty(a, 1) == -1);
        } break; case 23: {
            assert(firstEmpty(a+2, 1) == 0);
        } break; case 24: {
            assert(firstEmpty(a, 0) == -1  &&  firstEmpty(a+2, 0) == -1);
        } break; case 25: {
            assert(indexOfLeast(x, 6) == 4);
        } break; case 26: {
            assert(indexOfLeast(x, 5) == 4);
        } break; case 27: {
            assert(indexOfLeast(x+7, 3) == 0);
        } break; case 28: {
            assert(indexOfLeast(x+8, 2) == 1);
        } break; case 29: {
            assert(indexOfLeast(x+2, 2) == 0);
        } break; case 30: {
            assert(indexOfLeast(x, 1) == 0);
        } break; case 31: {
            assert(indexOfLeast(x+4, 1) == 0);
        } break; case 32: {
            assert(indexOfLeast(x, 10) == 4);
        } break; case 33: {
            assert(indexOfLeast(x, 0) == -1  &&  indexOfLeast(x+2, 0) == -1);
        } break; case 34: {
            assert(includes(y, 10, b, 4));
        } break; case 35: {
            assert(includes(y+1, 9, b, 4));
        } break; case 36: {
            assert(!includes(y+2, 8, b, 4));
        } break; case 37: {
            assert(!includes(y+1, 6, b, 4));
        } break; case 38: {
            assert(includes(y+1, 7, b, 4));
        } break; case 39: {
            assert(includes(y, 10, b+2, 1));
        } break; case 40: {
            assert(includes(y+1, 9, b, 1));
        } break; case 41: {
            assert(!includes(y+2, 8, b, 1));
        } break; case 42: {
            assert(includes(y, 10, b, 0));
        } break; case 43: {
            assert(includes(y, 0, b, 0));
        } break; case 44: {
            assert(includes(y+1, 2, b, 2));
        } break; case 45: {
            assert(!includes(y+2, 2, b+1, 2));
        } break; case 46: {
            assert(!includes(y+2, 2, b+1, 3));
        } break; case 47: {
            assert(!includes(y+1, 1, b, 2));
        } break; case 48: {
            assert(!includes(y+1, 0, b, 1));
            
        } break; case 49: {
            assert(includes(c, 7, d+3, 3));
        } break; case 50: {
            assert(!includes(c, 7, d+6, 3));
        } break; case 51: {
            assert(includes(c, 7, d+9, 3));
        } break; case 52: {
            assert(countIncludes(c, 7, d, 3) == 1);
        } break; case 53: {
            assert(countIncludes(c, 7, d+3, 3) == 2);
        } break; case 54: {
            assert(countIncludes(c, 7, d+6, 3) == 0);
        } break; case 55: {
            assert(countIncludes(c, 7, d+9, 3) == 3);
        } break; case 56: {
            assert(countIncludes(c, 7, d+2, 1) == 2);
        } break; case 57: {
            assert(countIncludes(c, 2, d+2, 1) == 0);
        } break; case 58: {
            assert(countIncludes(c, 7, d, 0) == 1);
        } break; case 59: {
            assert(countIncludes(c, 0, d, 0) == 1);
        } break; case 60: {
            order(d, 12);
            for(int i =0; i < 12; i++)
            {
                cerr << d[i] << " ";
            }
            assert(equal(d, d+12, e));
        } break; case 61: {
            order(d, 1);
            assert(d[0] == "cat");
        } break; case 62: {
            order(d, 0);
            assert(d[0] == "cat");
        } break; case 63: {
            assert(pathExists(maze1, 8, 6, 1, 1));
            break;
        } break; case 64: {
            assert(!pathExists(maze2, 8, 6, 1, 1));
            break;
        } break; case 65: {
            assert(pathExists(maze3, 4, 3, 7, 1));
            break;
        } break; case 66: {
            assert(!pathExists(maze4, 4, 3, 7, 1));
            break;
        }
    }
}

int main()
{
    cout << "Enter test number: ";
    int n;
    cin >> n;
    testone(n);
    cout << "Passed" << endl;
}