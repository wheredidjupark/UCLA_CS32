
#include "Set.h"

Set::Set()
{
    m_size = 0;
    m_head = new Node;
    m_head->next = m_head;
    m_head->prev = m_head;
}

Set::Set(const Set& source)
{
    //first, create an empty set.
    m_size = source.m_size;
    m_head = new Node;
    m_head->next = m_head;
    m_head->prev = m_head;
    
    //now copy the source over to the calling object
    ItemType source_value;
    for(int i=0; i <m_size; i++)
    {
        source.get(i,source_value);
        insert(source_value);
    }
}

Set::~Set()
{
    Node *nextup = m_head->prev;
    while(nextup->prev != m_head)
    {
        nextup = nextup->prev;
        delete nextup->next;
    }
    delete nextup;

}

Set& Set::operator=(const Set& source)
{
    //first delete the current set. maybe using the destructor??
    Set temp;
    temp.swap(*this);
    /*
    Node *nextup = m_head->prev;
    while(nextup->prev != m_head)
    {
        nextup = nextup->prev;
        delete nextup->next;
    }
    delete nextup;
     */
    
    //now copy the source over to the calling object
    m_size = source.m_size;
    ItemType source_value;
    for(int i=0; i <m_size; i++)
    {
        source.get(i,source_value);
        insert(source_value);
    }
    
    return *this;
}


bool Set::empty() const
{
    return size() == 0;
}

int Set::size() const
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
        
        //cleaner version below.
         m_size++;
         Node* last = m_head->prev;
         Node* newest = new Node;
         newest->m_data = value;
         newest->next = m_head;
         newest->prev = last;
         last->next = newest;
         m_head->prev = newest;
         last = newest;
         return true;
    }
}

bool Set::erase(const ItemType& value)
{
    if(contains(value))
    {
        m_size--;
        Node* find = m_head;
        
        
        //look for the Node that stores our target value
        while(find->m_data != value)
        {
            find = find->next;
        }
        
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
    Node* find=m_head;
    while(find->m_data != value)
    {
        find = find->next;
        if(find == m_head)
            break;
    }
    
    return (find != m_head);
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
    
}


void subtract(const Set& s1, const Set& s2, Set& result)
{
  
    result = s1; 
    ItemType copy;
    
    for(int i=0; i <s2.size(); i++)
    {
        s2.get(i,copy);
        result.erase(copy);
    }
    
}

*/
