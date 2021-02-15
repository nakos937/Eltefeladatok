#ifndef E1_H
#define E1_H

#include <iostream>

struct S1L
{
    int key;
    struct S1L* next;
};

class E1
{
    public:
        E1(){head = NULL; tail = NULL; current = head;};
        virtual ~E1(){head = NULL; tail = head; current = head;};
        S1L* First(){current = head; return current;};
        S1L* Next(){current = current->next; return current;};
        S1L* Current(){return current;};
        void Follow(int a);

    protected:

    private:
        S1L *current, *head, *tail;
};

#endif // E1_H
