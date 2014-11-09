//
//  main.cpp
//  CS32_Homework3_Problem2
//
//  Created by Ju Hyeon Park on 11/7/14.
//  Copyright (c) 2014 Ju Hyeon Park. All rights reserved.
//

#include <string>
#include <iostream>
using std::string;
using namespace std;
/*
 Here are five functions, with descriptions of what they are supposed to do. They are incorrectly implemented. The first four take an array of strings and the number of strings to examine in the array; the last takes two arrays of strings and the number of strings to examine in each. (Note: If s is a string, s.empty() returns true if s is empty, and false otherwise. Also, for two strings s1 and s2, we will consider s1 to be less than s2 if s1 < s2 yields true.)
 */
 
 // Return true if any of the strings in the array is empty, false
 // otherwise.
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
     bool k;
     if(a1[0] == a2[0])
     {
         k = includes(a1+1, n1-1, a2,n2); //let this check for last 'n1-1' elements of the a1 array
     }
     else
     {
         k = includes(a1, n1, a2+1, n2-1);
     }
     return k;
     
     /*
if(n2 == 0)
    return true;
     

     bool k = includes(a1,n1, a2+1, n2-1); //let's say k helps us find whether last n2-1 elements are contained in order
     //so we can focus on a2[0]
     if(n1 == 0)
         return false; //why false? a2 is nonempty but a1 is empty!
     else
     {
         if(a2[0] == a1[0])
             return true;
         else
         {
             return includes(a1+1, n1-1, a2, n2); //this looks
         }
     }
     
     return k;
      */
     
 }

int main()
{
    string a[10] = {"1", "2", "3", "", "5", ""};
    cout << anyEmpty(a, 10) <<endl; //change the number.
    cout << countEmpties(a,10) <<endl;
    cout << firstEmpty(a,10) <<endl;
    cout << indexOfLeast(a, 10);
    return 0;
}

/*
 Replace the incorrect implementations of these functions with correct ones that use recursion in a useful way; your solution must not use the keywords while, for, orgoto. You must not use global variables or variables declared with the keyword static, and you must not modify the function parameter lists. If you write any auxiliary functions, they must not have any parameters of a reference type, and any parameter of a pointer type must be of type const string*.
 
 You may find it helpful to remember that a function parameter x declared T x[] for any type T means exactly the same thing as if it had been declared T* x. If any of the parameters n, n1, or n2 is negative, act as if it were zero.
 
 You will not receive full credit if for nonnegative n, anyEmpty, countEmpties, or firstEmpty performs more than n tests to determine whether strings are empty, or if indexOfLeast or includes causes a string comparison function (e.g. <= or ==) to be called more than n or n1 times, respectively. (For example, in determining how many of the n elements of an array are empty strings, you must not perform more than n tests to see whether a string is empty; you must solve this by causing each of the strings in the array to be tested no more than once.)
 
 Each of these functions can be implemented in a way that meets the spec without calling any of the other four functions. (If you implement a function so that it doescall one of the other functions, then it will probably not meet the limit stated in the previous paragraph.)
 
 For this part of the homework, you will turn in one file named linear.cpp that contains the five functions and nothing more.
 */

