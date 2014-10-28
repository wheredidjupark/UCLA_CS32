
#include "Set.h"
#include <iostream> //error checking

Set::Set()
{
    //or you can simply use createEmptySet() function.
    m_size = 0;
    m_head = new Node;
    m_head->next = m_head;
    m_head->prev = m_head;
}

Set::Set(const Set& source)
{
    //first, create an empty set.
    m_size =source.m_size;
    m_head = new Node;
    m_head->next = m_head;
    m_head->prev = m_head;
    
    //now copy the source over to the calling object
    ItemType source_value;
    for(int i=0; i <m_size; i++)
    {
        bool got_value = source.get(i,source_value);
        if(got_value == true)
        {
            insert(source_value);
        }
        else
        {
            std::cerr << "Error!";
            break;
        }
    }
}

Set::~Set() //Done
{
    Node *nextup = m_head->prev;
    while(nextup->prev != m_head)
    {
        nextup = nextup->prev;
        delete nextup->next;
    }
    delete m_head; //i.e. delete nextup

}

Set& Set::operator=(const Set& source)
{
    //first delete the current set. maybe using the destructor??
    Node *nextup = m_head->prev;
    while(nextup->prev != m_head)
    {
        nextup = nextup->prev;
        delete nextup->next;
    }
    delete m_head;
    
    //then, create a new one...
    m_head = new Node;
    
    //now copy the source over to the calling object
    ItemType source_value;
    for(int i=0; i <source.m_size; i++)
    {
        source.get(i,source_value);
        (*this).insert(source_value);
    }
    m_size = source.m_size;
    
    return *this;
}


bool Set::empty() const //Done
{
    return size() == 0;
}

int Set::size() const //Done
{
    return m_size;
}

bool Set::insert(const ItemType& value)
{
    if(contains(value))
    {
        return false;
    }
    else //insert at tail
    {
        /*
        Node* last = m_head;
        while(last->next != m_head)
        {
            last = last->next;
        }
        m_size++;
        Node* newest = new Node;
        newest->m_data = value;
        newest->next = m_head;
        newest->prev = last;
        last->next = newest;
        m_head->prev = newest;
        return true;
        */

        m_size++;
        
        Node* newNode = new Node;
        newNode->m_data = value;
        newNode->next = m_head;
        newNode->prev = m_head->prev;

        m_head->prev->next = newNode;
        m_head->prev = newNode;

         return true;
    }
}

bool Set::erase(const ItemType& value)
{
    if(contains(value))
    {
        m_size--;
        
        //look for the Node that stores our target value
        Node* find = finder(value);
        find->prev->next = find->next;
        find->next->prev = find->prev;
        delete find;
       
        return true;
    }
    else //value not contained in the Set
    {
        return false;
    }
}

bool Set::contains(const ItemType& value) const
{
    /*
    if(m_size ==0)
        return false;
    
    Node* find=m_head;
    while(find->m_data != value)
    {
        find = find->next;
        if(find == m_head)
            break;
    }
    return (find != m_head);
    */
    
    
    Node *find=m_head->next;
    for(int i=0; i<m_size; i++)
    {
        if(find->m_data == value)
        {
            return true;
        }
        else
        {
            find = find->next;
        }
    }
    return false;
    
}


bool Set::get(int pos, ItemType& value) const
{
    if(pos < 0 || pos >= size())
        return false;
    Node *find = m_head->next;
    for(int i =0; i < pos; i++)
    {
        find = find->next;
    }

    value = find->m_data;
    return true;
}

void Set::swap(Set& other)
{
    Node* m_head_other = other.m_head; //this is where i need to get better.
    other.m_head = this->m_head;
    m_head = m_head_other;
    
    int size_other = other.m_size;
    other.m_size = m_size;
    m_size = size_other;
}

void unite(const Set& s1, const Set& s2, Set& result)
{
    //Attempt 1:error with testcase 66 and 67... D:
    /*
    Set new_result;
    new_result.swap(result);
    //now result is empty!
    
    
    ItemType copy;
    for(int i=0; i<s1.size(); i++)
    {
        s1.get(i, copy);
        result.insert(copy);
    }
    
    for(int i=0; i<s2.size(); i++)
    {
        s2.get(i,copy);
        result.insert(copy);
    }
     */
    
    Set new_result;
    ItemType copy;
    for(int i=0; i <s1.size(); i++)
    {
        s1.get(i,copy);
        new_result.insert(copy);
    }
    
    for(int i=0; i<s2.size(); i++)
    {
        s2.get(i,copy);
        new_result.insert(copy);
    }
    
    result.swap(new_result);
    
}


void subtract(const Set& s1, const Set& s2, Set& result)
{
    //Attempt 1: error with 71 and 72
    /*
    //uses the following:
    //assignment overloading
    //get(i,value)
    //erase(value)
    result = s1;
    
    for(int i=0; i <s2.size(); i++)
    {
        ItemType copy;
        s2.get(i,copy);
        result.erase(copy);
    }
     */
    //why is it wrong? PROBABLY BECAUSE THERE'S BUG IN FUNCTIONS THAT SUBTRACT USES ABOVE....
    
    Set new_result;
    for(int i=0; i <s1.size(); i++)
    {
        ItemType copy;
        s1.get(i,copy);
        new_result.insert(copy);
    }
    
    for(int i=0; i<s2.size();i++)
    {
        ItemType copy;
        s2.get(i,copy);
        new_result.erase(copy);
    }
    
    result.swap(new_result);
}

void Set::createEmptySet()
{
    m_size = 0;
    m_head = new Node;
    m_head->next = m_head;
    m_head->prev = m_head;
}

Set::Node* Set::finder(const ItemType& value)
{
    Node* find = m_head;
    while(find->m_data != value)
    {
        find = find->next;
        if(find==m_head)
        {
            break;
        }
    }
    return find;
}

