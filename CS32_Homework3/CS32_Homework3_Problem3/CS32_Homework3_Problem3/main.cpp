#include <stack>
#include <iostream>
using namespace std;

const char WALL = 'X';
const char DISCOVERED_SPACE = '@';
const char SPACE = '.';
const int ROW_SIZE = 10;
const int COL_SIZE = 10;

//looking at the ith row's 10 columns
bool pathExists(char maze[][COL_SIZE], int r, int c, int r2, int c2);

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
        cout <<"Solvable!\n\n";
    }
    else
        cout <<"Cannot Solve\n\n";
    
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
    return 0;
}

//written with the stack.

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
