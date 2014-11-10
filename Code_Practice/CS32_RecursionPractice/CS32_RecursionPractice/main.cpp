//
//  main.cpp
//  CS32_RecursionPractice
//
//  Created by Ju Hyeon Park on 11/6/14.
//  Copyright (c) 2014 Ju Hyeon Park. All rights reserved.
//

#include <iostream>
using std::cout;

/*
int mystery(int a)
{
    std::cout <<a;
    if (a==0)
        return 1;
    int b = mystery(a/2);
    std::cout << b;
    return b+1;
}
int main(int argc, const char * argv[]) {
    // insert code here...
    std::cout << mystery(3);
    return 0;
}

*/

/*
int mystery(int a)
{
    if (a==0)
    {
        return a+1;
    }
    std::cout <<a <<" ";
    
    if(a%2 == 0)
        a = mystery(a/3);
    else
    {
        a = mystery(a-1);
    }
    return a+5;
}
int main()
{
    std::cout <<mystery(3);
}
*/

int factorial(int n)
{
    if(n ==0)
        return 1;

    int part1 = n;
    int part2 = factorial(n-1);
    
    return part1 * part2;
}


void printArr(int arr[], int size)
{
    if(size == 0)
        return;
    //to print from last to first
    //cout << arr[size-1];
    //printArr(arr,size-1);
    
    
    //printing from first to last (or your can swap the two lines to make it print last to first)
    cout << arr[0];
    printArr(arr+1, size-1);
}

int count(int a[], int size, int num) //counts how many times num is contained in the array
{
    if(size == 0) //if the size of the array is zero, there is nothing to count.
        return 0;
    //else...
    
    int total = count(a+1,size-1,num); //we are not going to let the total do all the work....
    if(a[0] == num) //and we focus only one our current element.. if we find
        ++total;
    
    return total;
}

int main()
{
    int n=6, result;
    result = factorial(n);
    cout << result;
    
    int arr[] = {1, 2, 3, 4, 5, 6};
    printArr(arr, 6);
    
    cout <<std::endl;
    cout << std::max(1,2) <<std::endl;;
    
    const int size =5;
    int array[size] ={7,9,6,7,7};
    
    cout << count(array,size,7);
    return 0;

    
    
}