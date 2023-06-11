#pragma once
#include <iostream>
#include <iomanip>

#include "node.hpp"
#include "iterator.hpp"
#include "zip_iterator.hpp"

struct intlist
{
    iterator begin() const { return iterator(m_head); }
    iterator end() const { return iterator(nullptr); }

    ~intlist()
    {
        clear();
    }

    void push_back(int x)
    {
        auto *newElem = new intnode(x);

        if (m_tail)
        {
            m_tail->next = newElem;
        }
        else
        {
            m_head = newElem;
        }
        m_tail = newElem;
    }

    void print() const
    {
        for (const auto *i: *this)
        {
            i->print();
        }
    }

    // invalidate only m_head and m_tail
    // elements inbetween will point to garbage))
    void clear()
    {
        intnode* currNode = m_head;
        while(currNode)
        {
            auto *nodeToDelete = currNode;
            currNode = currNode->next;
            delete nodeToDelete;
        }

        m_head = m_tail = nullptr;
    }

private:
    intnode* m_head;
    intnode* m_tail;
};
