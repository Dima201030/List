#pragma once

struct List
{

    struct ListElement
    {
        int _value = {0};
        ListElement* _back = {nullptr};
        ListElement* _next = {nullptr};
    };

    int  getValue(ListElement* element                  );
    void setValue(const int &value, ListElement* element);

    void pushBack (const int& value);
    void pushFront(const int& value);

    bool popBack ();
    bool popFront();

    bool insert(const int& position, const int& value);
    bool erase (const int& position                  );

    bool empty();
    void clear();

    int front();
    int back ();

    int  size();
    bool swap(ListElement* first, ListElement* second);
    bool swap(const int& firstPosition, const int& secondPosition);

    int at(const int& position);
    int operator[](const int& position);


private:
    ListElement* _head = {nullptr};
};
