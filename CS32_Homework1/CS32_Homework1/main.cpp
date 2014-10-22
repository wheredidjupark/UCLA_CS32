#include <string>

typedef int ItemType;  // define Number as a synonym for int

const int DEFAULT_MAX_ITEMS = 200;

class Set
{
public:
    Set();         // Create an empty set.
    
    bool empty() const;  // Return true if the set is empty, otherwise false.
    
    int size() const;    // Return the number of items in the set.
    
    bool insert(const ItemType& value);
    // Insert value into the set if it is not already present.  Return
    // true if the value was actually inserted.  Return false if the
    // value was not inserted (perhaps because it is already in the set
    // or because the set has a fixed capacity and is full).
    
    bool erase(const ItemType& value);
    // Remove the value from the set if present.  Return true if the
    // value was removed; otherwise, leave the set unchanged and
    // return false.
    
    bool contains(const ItemType& value) const;
    // Return true if the value is in the set, otherwise false.
    
    bool get(int i, ItemType& value) const;
    // If 0 <= i < size(), copy into value an item in the set and
    // return true.  Otherwise, leave value unchanged and return false.
    // (See below for details about this function.)
    
    void swap(Set& other);
    // Exchange the contents of this set with the other one.
    
private:

    ItemType set[DEFAULT_MAX_ITEMS];
    int m_size;
};


Set::Set()
{
    m_size = 0;
}

bool Set::empty() const
{
    if(m_size == 0)
        return true;
    
    return false;
}

bool Set::insert(const ItemType& value)
{
    int i =0;
    for(; i <m_size; i++) //check 0th~m_size item (theoretically up to 199th element)
    {
        if(set[i] == value)
            return false;
    }
    if(m_size >= DEFAULT_MAX_ITEMS)
    {
        return false;
    }
    else
    {
        set[m_size] = value;
        m_size++;
        return true;
    }
    return false;
}

bool Set::erase(const ItemType& value)
{
    if(this->contains(value))
    {
        int pos = 0;
        for(int i =0; i < m_size; i++) //find the position
        {
            if(set[i] == value)
            {
                pos = i;
            }
        }
        
        for(;pos+1 < m_size; pos++)
        {
            set[pos] = set[pos+1];
        }
        set[m_size-1] = NULL;
        m_size--;
        return true;
    }
    else
    {
        return false;
    }
}

bool Set::contains(const ItemType& value) const
{
    for(int i =0; i < m_size; i++)
    {
        if(set[i] == value)
            return true;
    }
    return false;
}

bool Set::get(int i, ItemType &value) const
{
    if(i >= 0 && i < m_size)
    {
        value = set[i];
        return true;
    }
    else
        return false;
}

int main()
{
    return 0;
}