//
//  LinkedList.h
//  Hospital
//
//  Created by Ian Panzica on 11/30/12.
//  Copyright (c) 2012 Cornell University . All rights reserved.
//

#ifndef Hospital_LinkedList_h
#define Hospital_LinkedList_h

// template <typename T> class LinkedList
template <typename T>
class LinkedList
{
    // class LinkedListException
    class LinkedListException
    {
    };
    //  class Link
    class Link
    {
    public:
        T value;
        Link *prev;
        Link *next;
        
        //constructor 
        Link(const T &value, Link *prev, Link *next)
        {
            //need to find way to keep room number intact.... 
        }
        //overload =
        Link& operator=(const Link& b)
        {
            value = b.value;
            return *this;
        }
        //overload <
        bool operator<(const Link& b) const
        {
             return value < b.value;
        }
    };
    //  Properties
    Link *head_;
    Link *tail_;
    int size_;
    
public:
    //constructor
    LinkedList(){}
    //destructor
    ~LinkedList()
    {
        
    }
    
    //copy a list to another list 
    void copyTo(LinkedList<T> &list, const int &from, const int &count)
    {
        if(from >= 0 && count > 0 && count - from <= size_)
        {
            int i = 0;
            Link *e = head_;
            Link *n;
            for(; i < from; i++)
                e = e->next;
            do
            {
                n = e->next;
                list.push(e->value);
                e = n;
            }
            while(++i < from + count);
        }
    }
    //get a link at a given index
    inline T get(const int &index)
    {
        return get(link(index));
    }
    
    //get a value of a link 
    inline T get(Link *link)
    {
        return link->value;
    }
    //return the head of the list
    inline Link *head(void)
    {
        return head_;
    }
    //return the link at the given index
    Link *link(int index)
    {
        
        if(index < 0 || index >= size_)
            throw LinkedListException();
        //issue with tail pointers
       
        Link *e = head_;
        if(index < (size_ >> 1))
            for(int i = 0; i < index; i++)
                e = e->next;
        else
            for(int i = size_; i > index; i--)
                if(e->prev == NULL)
                    e=e;
                e = e->prev; 
        /*
        Link *e= tail_;
        for (int i= 0; i > index; i ++)
        {
            e= e->next;
        }*/
        
        return e;
    }
    //add an element to the list
    void push(const T &value)
    {
        Link *link = new Link(value, tail_, head_);
        
        if(size_ > 0)
        {
            tail_->next = link;
            head_->prev = link;
        }
        else
        {
            link->prev = link;
            link->next = link;
            
            head_ = link;
        }
        
        tail_ = link;
        size_++;
    }
    //remove a link at an index
    inline void remove(const int &index)
    {
        remove(link(index));
    }
    //remove a link
    void remove(Link *link)
    {
        if(size_ > 0)
        {
            if(size_ > 1)
            {
                link->prev->next = link->next;
                link->next->prev = link->prev;
            }
            else
            {
                delete head_;
                delete tail_;            }
            delete link;
            size_--;
        }
    }
    //return size of the list
    inline int size()
    {
        return size_;
    }
    //return the tail of the list
    inline Link *tail()
    {
        return tail_;
    }
    //overload [] for element access
    inline Link &operator[](const int &index)
    {
         return *link(index);
    }
};





#endif 