#include <string>

class Set
{
public:
    Set();         // Create an empty set.
    
    bool empty();  // Return true if the set is empty, otherwise false.
    
    int size();    // Return the number of items in the set.
    
    bool insert(const std::string& value);
    // Insert value into the set if it is not already present.  Return
    // true if the value was actually inserted.  Return false if the
    // value was not inserted (perhaps because it is already in the set
    // or because the set has a fixed capacity and is full).
    
    bool erase(const std::string& value);
    // Remove the value from the set if present.  Return true if the
    // value was removed; otherwise, leave the set unchanged and
    // return false.
    
    bool contains(const std::string& value);
    // Return true if the value is in the set, otherwise false.
    
    bool get(int i, std::string& value);
    // If 0 <= i < size(), copy into value an item in the set and
    // return true.  Otherwise, leave value unchanged and return false.
    // (See below for details about this function.)
    
    void swap(Set& other);
    // Exchange the contents of this set with the other one.
    
private:
    
};
