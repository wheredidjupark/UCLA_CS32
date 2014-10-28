//
//  Set.h
//  CS32_Project2
//
//  Created by Ju Hyeon Park on 10/22/14.
//  Copyright (c) 2014 Ju Hyeon Park. All rights reserved.
//

#ifndef Set_h
#define Set_h

typedef int ItemType;

class Set
{
public:
    Set();
    Set(const Set& source);
    ~Set();
    Set& operator=(const Set& source);
    bool empty() const;
    int size() const;
    bool insert(const ItemType& value);
    bool erase(const ItemType& value);
    bool contains(const ItemType& value) const;
    bool get(int pos, ItemType& value) const;
    void swap(Set& other);
private:
    struct Node
    {
        ItemType m_data;
        Node* next;
        Node* prev;
    };
    
    Node* m_head;
    int m_size;
    
    void createEmptySet();
    Node *finder(const ItemType& value);
};

void unite(const Set& s1, const Set& s2, Set& result);
void subtract(const Set& s1, const Set& s2, Set& result);


#endif