// Keszitette:  Nagy Ákos
// Email:       nakos1212@protonmail.com
#include <iostream>
#include <fstream>
#include <sstream>
#include <vector>
#include "E1.h"

using namespace std;

void show(E1 p);
void Concatenate(int n, vector<E1* > p, E1 &L);
void concatenate(S1L *a, S1L *b);

int main()
{
    string s = "input.txt";
    int n = 0;
    ifstream f;
    f.open(s);
    string line;
    vector <E1* >P;
    int x;
    while(getline(f,line))
    {
        E1* tmp = new E1;
        istringstream is(line);
        for( is >> x ; !is.fail(); is >> x )
        {
            tmp->Follow(x);
        }
        P.push_back(tmp);
        ++n;
    }
    E1 L;
    Concatenate(n, P, L);
    show(L);
    return 0;
}

void show(E1 p)
{
    p.First();
    while(p.Current() != NULL)
    {
        cout << p.Current()->key << " ";
        p.Next();
    }
    return;
}

void Concatenate(int n, vector<E1* > p, E1 &L)
{
    L = *p[0];
    for(int i = 1; i < n; ++i)
    {
        concatenate(L.First(), p[i]->First());
    }
    return;
}

void concatenate(S1L *a, S1L *b)
{
    if(a != NULL && b != NULL)
    {
        if(a->next == NULL)
        {
            a->next = b;
        }
        else
        {
            concatenate(a->next, b);
        }
    }
    return;
}
