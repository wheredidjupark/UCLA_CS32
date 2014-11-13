
#include <string>
using namespace std;



/*
 Replace the incorrect implementations of the countIncludes and the order functions below with correct ones that use recursion in a useful way. Except in the code for the takeSides function that we give you below, your solution must not use the keywords while, for, or goto. You must not use global variables or variables declared with the keyword static, and you must not modify the function parameter lists. If you write any auxiliary functions, they must not have any parameters of a reference type, and any parameter of a pointer type must be of type const string*. If any of the parameters n1, n2, or n is negative, act as if it were zero.
 */
 
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

int main()
{
    return 0;
}