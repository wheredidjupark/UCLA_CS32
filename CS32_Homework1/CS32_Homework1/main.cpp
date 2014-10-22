
/* for unsign long
#include "Set.h"
#include <iostream>
#include <cassert>
using namespace std;

int main()
{
    Set s;
    assert(s.empty());
    unsigned long x = 9876543;
    assert( !s.get(42,x)  &&  x == 9876543); // x unchanged by get failure
    s.insert(123456789);
    assert(s.size() == 1);
    assert(s.get(0,x)  &&  x == 123456789);
    cout << "Passed all tests" << endl;
}
*/


/*
#include "Set.h"
#include <string>
#include <iostream>
#include <cassert>
using namespace std;

void test()
{
    Set ss;
    assert(ss.insert("roti"));
    assert(ss.insert("pita"));
    assert(ss.size() == 2);
    assert(ss.contains("pita"));
    ItemType x = "bing";
    assert(ss.get(0, x)  &&  (x == "roti"  ||  x == "pita"));
}

int main()
{
    test();
    cout << "Passed all tests" << endl;
}
*/




// tester.cpp
// To test HW 1 Problem 1, uncomment the following line:
 #define TESTNEW

#ifdef TESTNEW
#include "newSet.h"
#else
#include "Set.h"
#endif

#include <iostream>
#include <cstdlib>
#include <cassert>
#include <string>
#include <type_traits>

using namespace std;

static ItemType DUMMY = 123;
static ItemType DEFAULT = 0;
static ItemType ARRAY[6] = { 10, 20, 30, 40, 50, 60 };

bool isPermutation(ItemType a[], const ItemType b[], int n)
{
    for (size_t k = 0; k < n; k++)
    {
        size_t j;
        for (j = k; j < n; j++)
        {
            if (b[k] == a[j])
            {
                ItemType t = a[k];
                a[k] = a[j];
                a[j] = t;
                break;
            }
        }
        if (j == n)
            return false;
    }
    return true;
}

const int SPEC_MAX = 200;

void testone(int n)
{
    Set s;
    switch (n)
    {
        default: {
            cout << "Bad argument" << endl;
        } break; case  1: {
            assert((is_same<decltype(&Set::empty), bool (Set::*)() const>::value));
        } break; case  2: {
            assert((is_same<decltype(&Set::size), int (Set::*)() const>::value));
        } break; case  3: {
            assert((is_same<decltype(&Set::contains),
                    bool (Set::*)(const ItemType&) const>::value));
        } break; case  4: {
            assert((is_same<decltype(&Set::get),
                    bool (Set::*)(int, ItemType&) const>::value));
        } break; case  5: {
            assert(s.empty());
        } break; case  6: {
            assert(s.size() == 0);
        } break; case  7: {
            assert(!s.erase(DEFAULT)  &&  s.size() == 0);
        } break; case  8: {
            assert(!s.contains(DEFAULT));
        } break; case  9: {
            ItemType x = DUMMY;
            assert(!s.get(0, x));
        } break; case 10: {
            ItemType x = DUMMY;
            s.get(0, x);
            assert(x == DUMMY);
        } break; case 11: {
            assert(s.insert(DUMMY));
        } break; case 12: {
            s.insert(DUMMY);
            assert(!s.empty());
        } break; case 13: {
            s.insert(DUMMY);
            assert(s.size() == 1);
        } break; case 14: {
            s.insert(DUMMY);
            assert(s.contains(DUMMY));
        } break; case 15: {
            s.insert(DUMMY);
            ItemType x = DEFAULT;
            assert(s.get(0, x));
        } break; case 16: {
            s.insert(DUMMY);
            ItemType x = DEFAULT;
            s.get(0, x);
            assert(x == DUMMY);
        } break; case 17: {
            assert(s.insert(DUMMY)  &&  !s.insert(DUMMY));
        } break; case 18: {
            s.insert(DUMMY);
            s.insert(DUMMY);
            assert(s.size() == 1);
        } break; case 19: {
            s.insert(ARRAY[0]);
            s.insert(ARRAY[1]);
            assert(!s.empty()   &&  s.size() == 2);
        } break; case 20: {
            s.insert(ARRAY[0]);
            s.insert(ARRAY[1]);
            ItemType x = DUMMY;
            s.get(0,x);
            assert(x == ARRAY[0]  ||  x == ARRAY[1]);
        } break; case 21: {
            s.insert(ARRAY[0]);
            s.insert(ARRAY[1]);
            ItemType x = DUMMY;
            s.get(0,x);
            ItemType y = DUMMY;
            s.get(0,y);
            assert(x == y);
        } break; case 22: {
            s.insert(ARRAY[0]);
            s.insert(ARRAY[1]);
            ItemType x = DUMMY;
            s.get(0,x);
            ItemType y = DUMMY;
            s.get(1,y);
            assert((x == ARRAY[0]  &&  y == ARRAY[1])  ||
                   (x == ARRAY[1]  &&  y == ARRAY[0]));
        } break; case 23: {
            s.insert(ARRAY[3]);
            s.insert(ARRAY[1]);
            s.insert(ARRAY[0]);
            s.insert(ARRAY[4]);
            s.insert(ARRAY[2]);
            assert(s.size() == 5);
        } break; case 24: {
            s.insert(ARRAY[3]);
            s.insert(ARRAY[1]);
            s.insert(ARRAY[0]);
            s.insert(ARRAY[4]);
            s.insert(ARRAY[2]);
            ItemType a[5] = { DUMMY, DUMMY, DUMMY, DUMMY, DUMMY };
            for (size_t k = 0; k < 5; k++)
                s.get(k, a[k]);
            assert(isPermutation(a, ARRAY, 5));
        } break; case 25: {
            s.insert(ARRAY[1]);
            s.insert(ARRAY[0]);
            s.insert(ARRAY[1]);
            s.insert(ARRAY[1]);
            s.insert(ARRAY[0]);
            assert(s.size() == 2);
        } break; case 26: {
            s.insert(ARRAY[1]);
            s.insert(ARRAY[0]);
            s.insert(ARRAY[1]);
            s.insert(ARRAY[1]);
            s.insert(ARRAY[0]);
            ItemType a[2] = { DUMMY, DUMMY };
            for (size_t k = 0; k < 2; k++)
                s.get(k, a[k]);
            assert(isPermutation(a, ARRAY, 2));
        } break; case 27: {
            s.insert(ARRAY[0]);
            s.insert(ARRAY[1]);
            s.insert(ARRAY[2]);
            s.insert(ARRAY[3]);
            s.insert(ARRAY[4]);
            assert(s.erase(ARRAY[3]));
        } break; case 28: {
            s.insert(ARRAY[0]);
            s.insert(ARRAY[1]);
            s.insert(ARRAY[2]);
            s.insert(ARRAY[3]);
            s.insert(ARRAY[4]);
            s.erase(ARRAY[3]);
            assert(s.size() == 4);
        } break; case 29: {
            s.insert(ARRAY[0]);
            s.insert(ARRAY[1]);
            s.insert(ARRAY[2]);
            s.insert(ARRAY[3]);
            s.insert(ARRAY[4]);
            assert(s.erase(ARRAY[0])  &&  s.size() == 4);
        } break; case 30: {
            s.insert(ARRAY[0]);
            s.insert(ARRAY[1]);
            s.insert(ARRAY[2]);
            s.insert(ARRAY[3]);
            s.insert(ARRAY[4]);
            assert(s.erase(ARRAY[4])  &&  s.size() == 4);
        } break; case 31: {
            s.insert(ARRAY[0]);
            s.insert(ARRAY[1]);
            s.insert(ARRAY[0]);
            s.insert(ARRAY[2]);
            s.insert(ARRAY[1]);
            assert(s.erase(ARRAY[1])  &&  s.size() == 2);
        } break; case 32: {
            s.insert(ARRAY[0]);
            s.insert(ARRAY[1]);
            s.insert(ARRAY[2]);
            s.insert(ARRAY[3]);
            s.insert(ARRAY[1]);
            s.erase(ARRAY[3]);
            ItemType a[3] = { DUMMY, DUMMY, DUMMY };
            for (size_t k = 0; k < 3; k++)
                s.get(k, a[k]);
            assert(s.size() == 3  &&  isPermutation(a, ARRAY, 3));
        } break; case 33: {
            s.insert(ARRAY[0]);
            s.insert(ARRAY[3]);
            s.insert(ARRAY[2]);
            s.insert(ARRAY[1]);
            s.insert(ARRAY[3]);
            s.erase(ARRAY[3]);
            ItemType a[3] = { DUMMY, DUMMY, DUMMY };
            for (size_t k = 0; k < 3; k++)
                s.get(k, a[k]);
            assert(s.size() == 3  &&  isPermutation(a, ARRAY, 3));
        } break; case 34: {
            s.insert(ARRAY[0]);
            s.insert(ARRAY[1]);
            s.insert(ARRAY[2]);
            s.insert(ARRAY[3]);
            assert(!s.erase(ARRAY[4]));
        } break; case 35: {
            s.insert(ARRAY[0]);
            s.insert(ARRAY[1]);
            s.insert(ARRAY[2]);
            s.insert(ARRAY[3]);
            s.erase(ARRAY[4]);
            assert(s.size() == 4);
        } break; case 36: {
            s.insert(DUMMY);
            s.erase(DUMMY);
            assert(s.size() == 0);
        } break; case 37: {
            s.insert(ARRAY[0]);
            s.insert(ARRAY[1]);
            s.insert(ARRAY[2]);
            ItemType x;
            assert(!s.get(-1, x));
        } break; case 38: {
            s.insert(ARRAY[0]);
            s.insert(ARRAY[1]);
            s.insert(ARRAY[2]);
            ItemType x = DUMMY;
            s.get(-1, x);
            assert(x == DUMMY);
        } break; case 39: {
            s.insert(ARRAY[0]);
            s.insert(ARRAY[1]);
            s.insert(ARRAY[2]);
            ItemType x;
            assert(! s.get(3, x));
        } break; case 40: {
            s.insert(ARRAY[0]);
            s.insert(ARRAY[1]);
            s.insert(ARRAY[2]);
            ItemType x = DUMMY;
            s.get(3, x);
            assert(x == DUMMY);
        } break; case 41: {
            s.insert(ARRAY[0]);
            s.insert(ARRAY[1]);
            s.insert(ARRAY[2]);
            s.erase(ARRAY[1]);
            assert(!s.contains(DEFAULT));
        } break; case 42: {
            s.insert(ARRAY[0]);
            s.insert(ARRAY[1]);
            s.insert(ARRAY[2]);
            s.erase(ARRAY[1]);
            assert(s.contains(ARRAY[2]));
        } break; case 43: {
            s.insert(ARRAY[0]);
            s.insert(ARRAY[1]);
            s.insert(ARRAY[2]);
            s.erase(ARRAY[2]);
            assert(s.size() == 2  &&  !s.contains(ARRAY[2]));
        } break; case 44: {
            s.insert(ARRAY[0]);
            s.insert(ARRAY[1]);
            s.insert(ARRAY[2]);
            s.erase(ARRAY[1]);
            s.insert(ARRAY[2]);
            s.insert(ARRAY[3]);
            assert(s.size() == 3  &&  s.contains(ARRAY[2])  &&
                   s.contains(ARRAY[3]));
        } break; case 45: {
            s.insert(ARRAY[0]);
            s.insert(ARRAY[1]);
            s.insert(ARRAY[2]);
            {
                Set s2;
                s2.insert(ARRAY[3]);
                s2.insert(ARRAY[4]);
                s.swap(s2);
                assert(s.size() == 2  &&  s2.size() == 3);
            }
        } break; case 46: {
            s.insert(ARRAY[0]);
            s.insert(ARRAY[1]);
            s.insert(ARRAY[2]);
            {
                Set s2;
                s2.insert(ARRAY[3]);
                s2.insert(ARRAY[4]);
                s.swap(s2);
                assert(s.contains(ARRAY[3])  &&  s.contains(ARRAY[4]));
                assert(!s2.contains(ARRAY[3])  &&  !s2.contains(ARRAY[4]));
                for (size_t k = 0; k < 3; k++)
                {
                    assert(!s.contains(ARRAY[k]));
                    assert(s2.contains(ARRAY[k]));
                }
            }
        } break; case 47: {
            for (size_t k = 0; k < SPEC_MAX; k++)
                assert(s.insert(k));
            assert(s.size() == SPEC_MAX);
        } break; case 48: {
            for (size_t k = 0; k < SPEC_MAX; k++)
                assert(s.insert(k));
            ItemType x = SPEC_MAX;
            assert(!s.insert(x)  &&  s.size() == SPEC_MAX  &&  !s.contains(x));
        } break; case 49: {
            assert(s.insert(DUMMY));
            for (size_t k = 0; k < 10*SPEC_MAX; k++)
                assert(!s.insert(DUMMY));
        } break;
        case 50:
        {
            for (size_t k = 0; k < SPEC_MAX; k++)
                assert(s.insert(k));
            assert(!s.insert(SPEC_MAX));
            s.erase(0);
            assert(s.insert(SPEC_MAX+1));
            assert(!s.insert(SPEC_MAX+2));
        } break;
//#if TESTNEW
        case 51:{
            const size_t CAPACITY = 2;
            Set s2(CAPACITY);
            for (size_t k = 0; k < CAPACITY; k++)
                assert(s2.insert(k));
            assert(! s2.insert(CAPACITY));
        } break; case 52: {
            const size_t CAPACITY = SPEC_MAX*2;
            Set s2(CAPACITY);
            for (size_t k = 0; k < CAPACITY; k++)
                assert(s2.insert(k));
            assert(! s2.insert(CAPACITY));
        } break; case 53: {
            // This test checked that the destructor deletes the array of items.
        } break; case 54: {
            s.insert(ARRAY[0]);
            s.insert(ARRAY[1]);
            s.insert(ARRAY[2]);
            {
                Set s2(s);
                s2.insert(ARRAY[3]);
                assert(s2.size() == s.size()+1);
            }
        } break; case 55: {
            s.insert(ARRAY[0]);
            s.insert(ARRAY[1]);
            s.insert(ARRAY[2]);
            {
                Set s2(s);
                s2.insert(ARRAY[3]);
                ItemType a[4] = { DUMMY, DUMMY, DUMMY, DUMMY };
                for (size_t k = 0; k < 4; k++)
                    s2.get(k, a[k]);
                assert(s2.size() == 4  &&  isPermutation(a, ARRAY, 4));
            }
        } break; case 56: {
            s.insert(ARRAY[0]);
            s.insert(ARRAY[1]);
            s.insert(ARRAY[2]);
            {
                Set s2(s);
                s2.insert(ARRAY[3]);
                ItemType a[3] = { DUMMY, DUMMY, DUMMY };
                for (size_t k = 0; k < 3; k++)
                    s.get(k, a[k]);
                assert(s.size() == 3  &&  isPermutation(a, ARRAY, 3));
            }
        } break; case 57: {
            {
                Set s2(2);
                s2.insert(ARRAY[0]);
                s2.insert(ARRAY[1]);
                Set s3(s2);
                assert(! s3.insert(ARRAY[2]));
            }
        } break; case 58: {
            // This test checked that the assignment operator doesn't just
            // copy a pointer.
        } break; case 59: {
            s.insert(ARRAY[0]);
            s.insert(ARRAY[1]);
            {
                Set s2;
                s2.insert(ARRAY[2]);
                s2.insert(ARRAY[3]);
                s2.insert(ARRAY[4]);
                s2 = s;
                s2.insert(ARRAY[5]);
                assert(s2.size() == s.size()+1);
            }
        } break; case 60: {
            s.insert(ARRAY[0]);
            s.insert(ARRAY[1]);
            {
                Set s2;
                s2.insert(ARRAY[3]);
                s2.insert(ARRAY[4]);
                s2.insert(ARRAY[5]);
                s2 = s;
                s2.insert(ARRAY[2]);
                ItemType a[3] = { DUMMY, DUMMY, DUMMY };
                for (size_t k = 0; k < 3; k++)
                    s2.get(k, a[k]);
                assert(s2.size() == 3  &&  isPermutation(a, ARRAY, 3));
            }
        } break; case 61: {
            s.insert(ARRAY[0]);
            s.insert(ARRAY[1]);
            {
                Set s2;
                s2.insert(ARRAY[3]);
                s2.insert(ARRAY[4]);
                s2.insert(ARRAY[5]);
                s2 = s;
                s2.insert(ARRAY[2]);
                ItemType a[2] = { DUMMY, DUMMY };
                for (size_t k = 0; k < 2; k++)
                    s.get(k, a[k]);
                assert(s.size() == 2  &&  isPermutation(a, ARRAY, 2));
            }
        } break; case 62: {
            // This test checked that swap doesn't take a length of time
            // proportional to the number of items in the Sets.
//#endif
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
