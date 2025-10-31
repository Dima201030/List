#include "list.h"


int List::getValue(ListElement* element)
{
    if(!element)
    {
        return -1;
    }
    return element->_value;
}

void List::setValue(const int &value, ListElement* element)
{
    if(!element)
    {
        return;
    }
    element->_value = value;
}

void List::pushBack(const int &value)
{
    if (!_head)
    {
        _head = new ListElement();
        _head->_value = value;
    }
    else
    {
        ListElement* nowElem = _head;

        while (nowElem->_next)
        {
            nowElem = nowElem->_next;
        }
        nowElem->_next = new ListElement();
        nowElem->_next->_back = nowElem;
        nowElem->_next->_value = value;
    }
}

void List::pushFront(const int &value)
{
    if (!_head)
    {
        _head = new ListElement();
        _head->_value = value;
    }
    else
    {
        ListElement* nowElem = _head;
        nowElem->_back = new ListElement();
        nowElem->_back->_next = nowElem;
        nowElem->_back->_value = value;
        _head = nowElem->_back;
    }
}

bool List::popBack()
{
    if (!_head)
    {
        return false;
    }

    ListElement* nowElem = _head;

    if (!nowElem->_next)
    {
        delete nowElem;
        _head = {nullptr};
    }
    else
    {
        while (nowElem->_next)
        {
            nowElem = nowElem->_next;
        }
        nowElem = nowElem->_back;
        delete nowElem->_next;
        nowElem->_next = {nullptr};
    }
    return true;
}

bool List::popFront()
{
    if (!_head)
    {
        return false;
    }

    ListElement* nowElem = _head;

    if (!nowElem->_next)
    {
        delete nowElem;
        _head = nullptr;
    }
    else
    {
        nowElem = nowElem->_next;
        delete nowElem->_back;
        nowElem->_back = {nullptr};
        _head = nowElem;
    }
    return true;
}

bool List::insert(const int &position, const int &value)
{
    if (!_head && position >= size())
    {
        return false;
    }

    ListElement* nowElem = _head;

    for (int i = 0; i < position; ++i)
    {
        nowElem = nowElem->_next;
    }

    ListElement* newElem = new ListElement();

    if (nowElem->_next)
    {
        nowElem->_next->_back = newElem;
        newElem->_next = nowElem->_next;
    }

    newElem->_back = nowElem;
    nowElem->_next = newElem;
    newElem->_value = value;
    return true;
}

bool List::erase(const int &position)
{
    if (!_head && position >= size())
    {
        return false;
    }

    ListElement* nowElem = _head;
    for(int i = 0; i < position; ++i)
    {
        nowElem = nowElem->_next;
    }
    if (nowElem->_next)
    {
        if (nowElem->_back)
        {
            // Situation in the middle
            nowElem->_back->_next = nowElem->_next;
            nowElem->_next->_back = nowElem->_back;
            delete nowElem;
        }
        else
        {
            // Situation at the beginning
            _head = nowElem->_next;
            nowElem->_next->_back = nullptr;
            delete nowElem;
        }
    }
    else if (nowElem->_back)
    {
        // Situation at the end
        nowElem->_back->_next = nullptr;
        delete nowElem;
    }
    else
    {
        _head = nullptr;
        delete nowElem;
    }

    return true;
}

bool List::empty()
{
    return _head ? false : true;
}

void List::clear()
{
    if (!_head)
    {
        return;
    }

    ListElement* nowElem = _head;

    while (nowElem->_next)
    {
        nowElem = nowElem->_next;
        delete nowElem->_back;
    }
    delete nowElem;
    _head = nullptr;
}

int List::front()
{
    if (!_head)
    {
        return -1;
    }
    return _head->_value;
}

int List::back()
{
    if (!_head)
    {
        return -1;
    }
    ListElement* nowElem = _head;
    while (nowElem->_next)
    {
        nowElem = nowElem->_next;
    }
    return nowElem->_value;
}

int List::size()
{
    if (!_head)
    {
        return 0;
    }

    ListElement* nowElem = _head;
    int size = 1;

    while (nowElem->_next)
    {
        nowElem = nowElem->_next;
        ++size;
    }
    return size;
}

bool List::swap(ListElement* first, ListElement* second)
{
    if (!first || !second || first == second)
    {
        return false;
    }

    if (first->_next == second)
    {
        if (first->_back)
        {
            first->_back->_next = second;
        }
        if (second->_next)
        {
            second->_next->_back = first;
        }

        first->_next = second->_next;
        second->_back = first->_back;

        first->_back = second;
        second->_next = first;
    }
    else if (second->_next == first)
    {
        return swap(second, first);
    }
    else
    {
        ListElement* firstNext = first->_next;
        ListElement* firstBack = first->_back;
        ListElement* secondNext = second->_next;
        ListElement* secondBack = second->_back;

        if (firstNext)
        {
            firstNext->_back = second;
        }
        if (firstBack)
        {
            firstBack->_next = second;
        }
        if (secondNext)
        {
            secondNext->_back = first;
        }
        if (secondBack)
        {
            secondBack->_next = first;
        }

        first->_back = secondBack;
        first->_next = secondNext;
        second->_back = firstBack;
        second->_next = firstNext;

    }
    if (_head == first)
    {
        _head = second;
    }
    else if (_head == second)
    {
        _head = first;
    }
    return true;
}

// bool List::swap(ListElement* first, ListElement* second, const bool& flag)
// {
//     if (first == second)
//     {
//         return true;
//     }
//     if (!_head || !first || !second)
//     {
//         return false;
//     }

//     if (flag)
//     {
//         bool flag1 = false, flag2 = false;
//         ListElement* nowElem = _head;

//         while (nowElem->_next && (!flag1 || !flag2))
//         {
//             if (nowElem == first)
//             {
//                 flag1 = true;
//             }
//             if (nowElem == second)
//             {
//                 flag2 = true;
//             }
//             nowElem = nowElem->_next;
//         }
//         if (!flag1 || !flag2)
//         {
//             return false;
//         }

//     }
//     if (first->_back)
//     {
//         if (first->_next)
//         {
//             if (second->_back)
//             {
//                 if (second->_next)
//                 {
//                     if (
//                         first->_back != second &&
//                         first->_next != second
//                         )
//                     {
//                         // Меняем местами не соседние, но и не крайние элементы
//                         first->_back->_next = second;
//                         second->_back->_next = first;
//                         ListElement* temp = first->_back;
//                         first->_back = second->_back;
//                         second->_back = temp;

//                         first->_next->_back = second;
//                         second->_next->_back = first;
//                         temp = first->_next;
//                         first->_next = second->_next;
//                         second->_next = temp;
//                     }
//                     else
//                     {
//                         // Меняем местами соседние, но не крайние элементы
//                         if (first->_back != second)
//                         {
//                             // first - левый
//                             // second - правый

//                             first->_back->_next = second;
//                             second->_next->_back = first;

//                             second->_back = first->_back;
//                             first->_back = second;

//                             first->_next = second->_next;
//                             second->_next = first;
//                         }
//                         else
//                         {
//                             // first - правый
//                             // second - левый

//                             second->_back->_next = first;
//                             first->_next->_back = second;

//                             first->_back = second->_back;
//                             second->_back = first;

//                             second->_next = first->_next;
//                             first->_next = second;
//                         }
//                     }
//                 }
//                 else
//                 {
//                     // Second - последний элемент списка
//                     if (first->_next != second)
//                     {
//                         // Меняем местами не соседние
//                         first->_next->_back = second;
//                         second->_next = first->_next;
//                         first->_back->_next = second;
//                         second->_back->_next = first;
//                         ListElement* temp = first->_back;
//                         first->_back = second->_back;
//                         second->_back = temp;
//                         first->_next = nullptr;

//                     }
//                     else
//                     {
//                         // Меняем местами соседние элементы
//                         first->_back->_next = second;
//                         second->_next = first;
//                         second->_back = first->_back;
//                         first->_back = second;
//                         first->_next = nullptr;
//                     }
//                 }
//             }
//             else
//             {
//                 // Second - первый
//                 if (second->_next != first)
//                 {
//                     // Не соседние
//                     second->_next->_back = first;
//                     first->_back->_next = second;
//                     first->_next->_back = second;
//                     second->_back = first->_back;
//                     ListElement* temp = first->_next;
//                     first->_next = second->_next;
//                     second->_next = temp;
//                     first->_back = nullptr;
//                 }
//                 else
//                 {
//                     // Соседние
//                     if (first->_next)
//                     {
//                         // В списке более двух элементов
//                         first->_next->_back = second;
//                         second->_back = first;
//                         second->_next = first->_next;
//                         first->_next = second;
//                         first->_back = nullptr;
//                     }
//                     else
//                     {
//                         // В списке всего два элемента
//                         first->_next = second;
//                         second->_back = first;
//                         first->_back = nullptr;
//                         second->_next = nullptr;
//                     }
//                 }
//                 _head = first;
//             }
//         }
//         else
//         {
//             // first - последний
//             if (second->_back)
//             {
//                 // Больше двух элементов
//                 if (second->_next != first)
//                 {
//                     // Не соседи
//                     second->_back->_next = first;
//                     second->_next->_back = first;
//                     first->_back->_next = second;
//                     first->_next = second->_next;
//                     ListElement* temp = first->_back;
//                     first->_back = second->_back;
//                     second->_back = temp;
//                     second->_next = nullptr;
//                 }
//                 else
//                 {
//                     // Соседи
//                     second->_back->_next = first;
//                     first->_next = second;
//                     first->_back = second->_back;
//                     second->_back = first;
//                     second->_next = nullptr;
//                 }
//             }
//             else
//             {
//                 if (second->_next != first)
//                 {
//                     // Больше двух элементов
//                     first->_back->_next = second;
//                     second->_next->_back = first;
//                     first->_next = second->_next;
//                     second->_back = first->_back;
//                     first->_back = nullptr;
//                     second->_next = nullptr;
//                 }
//                 else
//                 {
//                     first->_next = second;
//                     second->_back = first;
//                     second->_next = nullptr;
//                     first->_next = nullptr;
//                 }
//                 _head = first;
//             }
//         }
//     }
//     else
//     {
//         // first - первый элемент
//         if (second->_next)
//         {
//             // Second - не последний
//             if (first->_next != second)
//             {
//                 // Не соседи
//                 second->_next->_back = first;
//                 second->_back->_next = first;
//                 first->_next->_back = second;
//                 ListElement* temp = second->_next;
//                 second->_next = first->_next;
//                 first->_next = temp;
//                 first->_back = second->_back;
//                 second->_back = nullptr;

//             }
//             else
//             {
//                 // Соседи
//                 second->_next->_back = first;
//                 first->_next = second->_next;
//                 first->_back = second;
//                 second->_next = first;
//                 second->_back = nullptr;
//             }
//         }
//         else
//         {
//             // Second - последний
//             if (first->_next != second)
//             {
//                 // В списке больше двух элементов
//                 second->_back->_next = first;
//                 second->_next = first->_next;
//                 second->_next->_back = second;
//                 first->_back = second->_back;
//                 first->_next = nullptr;
//                 second->_back = nullptr;

//             }
//             else
//             {
//                 // В списке всего два элемента
//                 second->_next = first;
//                 first->_back = second;
//                 second->_back = nullptr;
//                 first->_next = nullptr;
//             }
//         }
//         _head = second;

//     }
//     return true;
// }

bool List::swap(const int& firstPosition, const int& secondPosition)
{
    if (
        !_head ||
        firstPosition < 0 ||
        firstPosition >= size() ||
        secondPosition < 0 ||
        secondPosition >= size()
       )
    {
        return false;
    }
    if (firstPosition == secondPosition)
    {
        return true;
    }

    ListElement* nowElem = _head,
               * first   = nullptr,
               * second  = nullptr;

    for (int i = 0; i < size(); ++i)
    {
        if (i == firstPosition)
        {
            first = nowElem;
        }
        if (i == secondPosition)
        {
            second = nowElem;
        }
        if (first && second)
        {
            break;
        }
        nowElem = nowElem->_next;
    }
    return swap(first, second);
}

int List::at(const int &position)
{
    if(!_head || size() <= position || position < 0)
    {
        return -1;
    }

    ListElement* nowElem = _head;

    for (int i = 0; i < position; ++i)
    {
        nowElem = nowElem->_next;
    }
    return nowElem->_value;
}

int List::operator[](const int& position)
{
    return at(position);
}
