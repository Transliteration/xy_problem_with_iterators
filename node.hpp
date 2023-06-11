#pragma once

struct intnode
{
    intnode(int x)
    : next{nullptr}
    , value{x} {}

    void print() const
    {
        std::cout << std::setw(4) << value << " | " << next << '\n';
    }

    intnode* next;
    int value;
};
