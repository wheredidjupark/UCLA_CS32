#include <string>
#include <iostream>
using namespace std;


const int DEFAULT_MAX_ITEMS = 200;

class Set
{
public:
    Set();         // Create an empty set.
    
    bool empty() const;  // Return true if the set is empty, otherwise false.
    
    int size() const;    // Return the number of items in the set.
    
    bool insert(const std::string& value);
    // Insert value into the set if it is not already present.  Return
    // true if the value was actually inserted.  Return false if the
    // value was not inserted (perhaps because it is already in the set
    // or because the set has a fixed capacity and is full).
    
    bool erase(const std::string& value);
    // Remove the value from the set if present.  Return true if the
    // value was removed; otherwise, leave the set unchanged and
    // return false.
    
    bool contains(const std::string& value) const;
    // Return true if the value is in the set, otherwise false.
    
    bool get(int i, std::string& value) const;
    // If 0 <= i < size(), copy into value an item in the set and
    // return true.  Otherwise, leave value unchanged and return false.
    // (See below for details about this function.)
    
    void swap(Set& other);
    // Exchange the contents of this set with the other one.
    
private:
    std::string content;
    Set* next;
    //Set* head?
    //Set* tail?
};

Set::Set()
{
    content = ""; //empty data
    next = nullptr; //doesn't point to anything (or there isn't any previous element...)
}


bool Set::empty() const
{
    int i =0;
    Set lastStored = *this;
    while( lastStored.next != nullptr)
    {
        i++;
        lastStored.next = lastStored.next->next;
    }
    
    if(i == 0)
        return true;
    else
        return false;
}

int Set::size() const
{
    int i =0;
    Set lastStored = *this;
    while( lastStored.next != nullptr)
    {
        i++;
        lastStored.next = lastStored.next->next;
    }
        return i;
}

bool Set::insert(const std::string& value)//adding to the end....
{
    Set *check = this;
    //first, we must check for the presence of value in our Set (we look for the newest element first, then go down the list)
    
    while(check->next != nullptr)
    {
        if(check->content == value)
            return false;
        
        check = check->next;
    }
    
    Set *last = this;
    while( last->next != nullptr)
    {
        last = last->next;
    }
    //reached the last Set pointer now.
    
    Set *newest = new Set;
    newest->content = value;
    newest->next = nullptr;
    last->next = newest;
    
    return true;
}

bool Set::erase(const std::string& value)
{
    if(this->contains(value))
    {
        //check for the location
        Set *check = this;
        
        while(check->content != value)
        {
            check = check->next;
        }
        if(check->next == nullptr && check->content == value) //case 2: if the value is at the end
        {
            Set *check2 = this;
            while(check2->next->content != value)
            {
                check2 = check2->next;
            }
            Set *toRemove2 = check2->next->next;
            delete toRemove2;
            check2->next = nullptr;
            return true;
        }
        //case 1:
        Set *toRemove = check;
        check->next = toRemove->next->next;
        delete toRemove;
        
    }
    else
    {
        return false;
    }

    return false;
}

bool Set::contains(const std::string& value) const
{
    string target;
    Set finder = *this;
    target = this->content;
    while(target != value)
    {
        finder.next = finder.next->next;
        target = finder.next->content;
    }
    if(target == value)
        return true;

    return false;
}

bool Set::get(int i, std::string& value) const //not good code..... can't follow yet... messy.
{
    
    
    if( i >= 0 && i < this->size())
    {
        Set last = *this;
        for(int k =0; k < this->size() && k < i && k+1 < this->size(); k++)
        {
            
            last.next = last.next->next; //you are moving to the first element....
        }
        value = last.next->content;
    }
    else
        return false;
        
        return false; //temporary
}

void Set::swap(Set& other)
{
    Set temp = *this;
    *this = other;
    other = temp;
}


int main()
{
    Set ss1;
    cerr << ss1.empty();
    
    ss1.insert("hello");
    cerr << ss1.size();
    ss1.insert("hi");
    cerr <<ss1.size();
    
    return 0;
}

