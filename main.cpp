#include <iostream>
#include <iomanip>
#include <vector>
#include <algorithm>

#include "node.hpp"
#include "list.hpp"
#include "zip_iterator.hpp"

int main(int argc, char const *argv[])
{
    intlist list{};
    intlist list2{};

    list.push_back(10);
    list.push_back(11);
    list.push_back(12);

    list2.push_back(5);
    list2.push_back(15);
    list2.push_back(30);

    auto it = zip_iterator(*list.begin(), *list2.begin());

    // Each of this works
    // for (auto i : it)
    // for (const auto i : it)
    // for (const auto &i : it)
    // for (auto *i : it)
    // for (auto &&i : it)
    // {
    //     std::cout << i->value << '\n';
    // }

    std::cout << "------------List 1 content" << '\n';
    list.print();
    std::cout << "------------List 2 content" << '\n';
    list2.print();

    intlist mergedList{};
    std::for_each(it.begin(), it.end(), [&mergedList](intnode* x)
    {
        mergedList.push_back(x->value);
    });
    std::cout << "------------Merged list filled\n" << '\n';
    mergedList.print();
    
    list.clear();
    std::cout << "------------List 1 cleared" << '\n';
    list2.clear();
    std::cout << "------------List 2 cleared" << '\n';

    std::cout << "------------List 1 content" << '\n';
    list.print();
    std::cout << "------------List 2 content" << '\n';
    list2.print();

    std::cout << "------------Merged list content after other lists was emptied" << '\n';
    mergedList.print();
    
    return 0;
}
