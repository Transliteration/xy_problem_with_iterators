#pragma once

#include "node.hpp"

struct iterator
{
    iterator(intnode* ptr) : m_ptr(ptr) {};
    bool operator!=(const iterator& end) const { return (m_ptr != end.m_ptr); }
    intnode* operator*() const { return m_ptr; }
    iterator operator++()
    {
        m_ptr = m_ptr->next;
        return *this;
    }

private:
    intnode* m_ptr;
};