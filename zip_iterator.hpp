#pragma once
#include <iostream>

#include "node.hpp"

struct node_pair
{
    intnode* m_ptr1;
    intnode* m_ptr2;

    bool operator!=(const node_pair& other) const 
    { 
        return m_ptr1 != other.m_ptr1 || m_ptr2 != other.m_ptr2; 
    }
};

struct zip_iterator
{
    zip_iterator(node_pair pair) : m_pair(pair) {};
    zip_iterator(intnode* n1, intnode* n2) : m_pair{n1, n2} {};
    bool operator!=(const zip_iterator& other) const { return m_pair != other.m_pair; }
    intnode* operator*() 
    { 
        if (m_pair.m_ptr1 && m_pair.m_ptr2)
        {
            if (m_pair.m_ptr1->value > m_pair.m_ptr2->value)
                return m_pair.m_ptr2;
            else
                return m_pair.m_ptr1;
        }
        else if (m_pair.m_ptr1)
        {
            return m_pair.m_ptr1;
        }
        else if (m_pair.m_ptr2)
        {
            return m_pair.m_ptr2;
        }
        else
        {
            std::cout << "unreachable" << '\n';
            return nullptr;
        }
    }

    const zip_iterator& operator++()
    {
        if (m_pair.m_ptr1 && m_pair.m_ptr2)
        {
            if (m_pair.m_ptr1->value > m_pair.m_ptr2->value)
                m_pair.m_ptr2 = m_pair.m_ptr2->next;
            else
                m_pair.m_ptr1 = m_pair.m_ptr1->next;
        }
        else if (m_pair.m_ptr1)
        {
            m_pair.m_ptr1 = m_pair.m_ptr1->next;
        }
        else if (m_pair.m_ptr2)
        {
            m_pair.m_ptr2 = m_pair.m_ptr2->next;
        }
        return *this;
    }

    zip_iterator begin() { return *this; }
    zip_iterator end() { return zip_iterator(nullptr, nullptr); }
    const zip_iterator cbegin() { return *this; }
    const zip_iterator cend() { return zip_iterator(nullptr, nullptr); }

private:
    node_pair m_pair;
};