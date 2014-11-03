#include <stack>
#include <queue>
#include <iostream>
using namespace std;

const char WALL = 'X';
const char DISCOVERED_SPACE = ',';
const char SPACE = '.';
const int ROW_SIZE = 10;
const int COL_SIZE = 10;

//looking at the ith row's 10 columns
bool pathExists(char maze[][COL_SIZE], int r, int c, int r2, int c2);
bool insideMaze(char maze[][COL_SIZE], int r, int c);
/*
 Write a C++ function named pathExists that determines whether or not a there's a path from start to finish in a 10x10 maze. Here is the prototype:
 
 
 bool pathExists(char maze[][10], int sr, int sc, int er, int ec);
 // Return true if there is a path from (sr,sc) to (er,ec)
 // through the maze; return false otherwise
 
 The parameters are
 
 A 2-dimensional 10x10 character array of Xs and dots that represents the maze. Each 'X' represents a wall, and each '.' represents a walkway.
 The starting coordinates in the maze: sr, sc; the row number and column number range from 0 to 9.
 The ending coordinates in the maze: er, ec; the row number and column number range from 0 to 9.
 The function must determine if there is a path from maze[sr][sc] to maze[er][ec] that includes only walkways, no walls. The path may turn north, east, south, and west, but not diagonally. You must use a stack data structure.
 
 
 (Our convention is that (0,0) is the northwest (upper left) corner, with south (down) being the increasing r direction and east (right) being the increasing c direction.)
 
 The stack you must use is a stack of Coords. You may either write your own stack class, or use the stack class in the C++ Standard Library (pp. 309-311 in the textbook discuss that class). Here's an example of the relevant functions in the library's stack class:
 
 
 #include <stack>
 using namespace std;
 
 int main()
 {
 stack<Coord> coordStack;     // declare a stack of Coords
 
 Coord a(5,6);
 coordStack.push(a);          // push the coordinate (5,6)
 coordStack.push(Coord(3,4)); // push the coordinate (3,4)
 ...
 Coord b = coordStack.top();  // look at top item in the stack
 coordStack.pop();            // remove the top item from stack
 if (coordStack.empty())      // Is the stack empty?
 cout << "empty!" << endl;
 cout << coordStack.size() << endl;  // num of elements
 }
 
 Here is pseudocode for your function:
 
 
 Push the starting coordinate (sr,sc) onto the coordinate stack and
 update maze[sr][sc] to indicate that the algorithm has encountered
 it (i.e., set maze[sr][sc] to have a value other than '.').
 While the stack is not empty,
 {   Pop the top coordinate off the stack. This gives you the current
 (r,c) location that your algorithm is exploring.
 If the current (r,c) coordinate is equal to the ending coordinate,
 then we've solved the maze so return true!
 Check each place you can move from the current cell:
 If you can move NORTH and haven't encountered that cell yet, qs    w
 then push the coordinate (r-1,c) onto the stack and update
 maze[r-1][c] to indicate the algorithm has encountered it.
 If you can move EAST and haven't encountered that cell yet,
 then push the coordinate (r,c+1) onto the stack and update
 maze[r][c+1] to indicate the algorithm has encountered it.
 If you can move SOUTH and haven't encountered that cell yet,
 then push the coordinate (r+1,c) onto the stack and update
 maze[r+1][c] to indicate the algorithm has encountered it.
 If you can move WEST and haven't encountered that cell yet,
 then push the coordinate (r,c-1) onto the stack and update
 maze[r][c-1] to indicate the algorithm has encountered it.
 }
 There was no solution, so return false
 
 Because the focus of this homework is on practice with the data structures, we won't demand that your function be as robust as we normally would. In particular, your function may make the following simplifying assumptions (i.e., you do not have to check for violations):
 
 the maze has 10 rows;
 the maze contains only Xs and dots when passed in to the function;
 the top and bottom rows of the maze contain only Xs, as do the left and right columns;
 sr, sc, er, and ec are between 0 and 9;
 maze[sr][sc] and maze[er][ec] are '.' (i.e., not walls)
 (Of course, since your function is not checking for violations of these conditions, make sure you don't pass bad values to the function when you test it.)
 
 For this part of the homework, you will turn in one file named mazestack.cpp that contains the Coord class and your stack-based pathExists function. (Do not leave out the Coord class and do not put it in a separate file.) If you use the library's stack type, your file should include the appropriate header.
 */
class Coord
{
public:
    Coord(int rr, int cc) : m_r(rr), m_c(cc){} ;
    int r() const
    {
        return m_r;
    }
    
    int c() const
    {
        return m_c;
    }
private:
    int m_r;
    int m_c;
};


int main()
{
    
    
    char maze[ROW_SIZE][COL_SIZE] = {
        { 'X','X','X','X','X','X','X','X','X','X'},
        { 'X','.','.','.','.','.','.','.','.','X'},
        { 'X','X','.','X','.','X','X','X','X','X'},
        { 'X','.','.','X','.','X','.','.','.','X'},
        { 'X','.','.','X','.','.','.','X','.','X'},
        { 'X','X','X','X','.','X','X','X','.','X'},
        { 'X','.','.','X','.','.','.','X','X','X'},
        { 'X','.','.','X','X','.','X','X','.','X'},
        { 'X','.','.','.','X','.','.','.','.','X'},
        { 'X','X','X','X','X','X','X','X','X','X'}
    };
    
    cerr << "  ";
    for(int x=0; x < ROW_SIZE; x++)
    {
        cerr<<x << " ";
    }
    cerr <<endl;
    for(int i=0; i < ROW_SIZE; i++)
    {
        cerr << i <<" ";
        for(int j=0; j <COL_SIZE; j++)
        {
            cerr <<maze[i][j] << " ";
        }
        cerr <<endl;
    }
    cerr <<endl;
    
    if(pathExists(maze, 6, 4, 1, 1) == true)
    {
        cout <<"Solvable!\n";
    }
    else
        cout <<"Cannot Solve\n";
    
    return 0;
}

//written with the stack.
/*
bool pathExists(char maze[][COL_SIZE], int sr, int sc, int er, int ec)
{
    if(maze[sr][sc] == WALL)
        return false;
    
    stack<Coord> CoordStack;
    Coord a(sr,sc);
    maze[sr][sc] = DISCOVERED_SPACE;
    CoordStack.push(a);
   
    while (CoordStack.empty() == false)
    {
        a = CoordStack.top(); //uses the default operator
        CoordStack.pop();
        
        if(a.r() == er && a.c() == ec)
        {
            return true;
        }
        
        
        //honestly, since the work is repetitive, I can write the insideMaze function to do all of this for me.
        if(insideMaze(maze, a.r()-1 , a.c())) //check north
        {
            CoordStack.push(Coord(a.r()-1, a.c()));
            maze[a.r()-1][a.c()] = DISCOVERED_SPACE;
        }
        if(insideMaze(maze, a.r(), a.c()+1)) //check east
        {
            CoordStack.push(Coord(a.r(), a.c()+1));
            maze[a.r()][a.c()+1] = DISCOVERED_SPACE;
        }
        if(insideMaze(maze, a.r()+1, a.c())) //check south
        {
            CoordStack.push(Coord(a.r()+1, a.c()));
            maze[a.r()+1][a.c()] = DISCOVERED_SPACE;
        }
        if(insideMaze(maze, a.r(), a.c()-1)) //check west
        {
            CoordStack.push(Coord(a.r(), a.c()-1));
            maze[a.r()][a.c()-1] = DISCOVERED_SPACE;
        }
        
    }
    return false;
}
*/


//written with the queue
bool pathExists(char maze[][COL_SIZE], int sr, int sc, int er, int ec)
{
    cerr <<endl;
    if(maze[sr][sc] == WALL)
        return false;
    
    int count = 0;
    queue<Coord> CoordQueue;
    Coord a(sr,sc);
    maze[sr][sc] = DISCOVERED_SPACE;
    CoordQueue.push(a);
    count++;
    while(CoordQueue.empty() == false)
    {
        
        a = CoordQueue.front();
        CoordQueue.pop();
        cerr <<a.r() << " " <<a.c() <<endl;
        
        if(a.r() == er && a.c() == ec)
        {
            cerr<<count <<endl; //number of pushes required to solve the puzzle.
            return true;
        }
        
        if(insideMaze(maze, a.r()-1, a.c()))
        {
            CoordQueue.push(Coord(a.r()-1, a.c()));
            count++;
            maze[a.r()-1][a.c()] = DISCOVERED_SPACE;
            
        }
        if(insideMaze(maze, a.r(), a.c()+1))
        {
            CoordQueue.push(Coord(a.r(), a.c()+1));
            count++;
            maze[a.r()][a.c()+1] = DISCOVERED_SPACE;
        }
        if(insideMaze(maze, a.r()+1, a.c()))
        {
            CoordQueue.push(Coord(a.r()+1, a.c()));
            count++;
            maze[a.r()+1][a.c()] = DISCOVERED_SPACE;
        }
        if(insideMaze(maze,a.r(), a.c()-1))
        {
            CoordQueue.push(Coord(a.r(), a.c()-1));
            count++;
            maze[a.r()][a.c()-1] = DISCOVERED_SPACE;
        }
    }
    
    return false;
    
}

bool insideMaze(char maze[][COL_SIZE], int r, int c)
{
    if((r >= 0) && (r < ROW_SIZE) && (c>= 0) && (c < COL_SIZE) && (maze[r][c] == SPACE))
    {
        return true;
    }
    else
    {
        return false;
    }
}
