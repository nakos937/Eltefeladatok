#include "E1.h"

void E1::Follow(int a)
{
    S1L* tmp = new S1L;
    tmp->key = a;
    tmp->next = nullptr;
    if(head==NULL)
    {
        head = tmp;
        tail = tmp;
    }
    else
    {
        tail->next = tmp;
        tail = tail->next;
    }
    return;
}
