#include <iostream>
#include "list.h"

int main()
{
    List lst;

    lst.pushBack(1);
    lst.pushBack(2);
    lst.pushBack(3);
    lst.pushBack(2);
    lst.pushFront(10);

    for (int i = 0; i < lst.size(); ++i)
    {
        std::cout << lst.at(i) << std::endl;
    }

    std::cout << "-======================-" << std::endl;

    lst.popFront();
    lst.popBack();
    lst.insert(1, 30);

    for (int i = 0; i < lst.size(); ++i)
    {
        std::cout << lst.at(i) << std::endl;
    }

    std::cout << "-======================-" << std::endl;

    lst.popFront();
    lst.popBack();
    lst.insert(1, 30);

    for (int i = 0; i < lst.size(); ++i)
    {
        std::cout << lst.at(i) << std::endl;
    }

    std::cout << "-======================-" << std::endl;

    lst.pushBack(10);
    lst.pushBack(40);
    lst.pushBack(50);

    for (int i = 0; i < lst.size(); ++i)
    {
        std::cout << lst.at(i) << std::endl;
    }

    std::cout << "-======================-" << std::endl;
    lst.swap(2, 3);

    for (int i = 0; i < lst.size(); ++i)
    {
        std::cout << lst.at(i) << std::endl;
    }

    std::cout << "-======================-" << std::endl;
    lst.swap(3, 0);

    for (int i = 0; i < lst.size(); ++i)
    {
        std::cout << lst.at(i) << std::endl;
    }

    std::cout << lst[2] << std::endl;
    return 0;
}
