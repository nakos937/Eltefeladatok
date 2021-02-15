#ifndef TOWN_H
#define TOWN_H

#include <iostream>
#include <vector>
#include <fstream>
#include "tourist.hpp"
#include "japanese.hpp"
#include "modern.hpp"
#include "other.hpp"



using namespace std;

class Town
{
public:
    enum Exceptions{MissingInputFile};
    vector < Tourist* > GetTourists() {return tourists;}
    int GetCondition() {return condition;}
    Town(const string& fileName) throw (Exceptions)
    {
        ifstream file(fileName.c_str());
        if (!file.fail())
        {
            file >> condition;
            file >> years;
            int x;
            while (!file.fail())
            {
                file >> x;
                tourists.push_back(new Japanese(x));
                file >> x;
                tourists.push_back(new Modern(x));
                file >> x;
                tourists.push_back(new Other(x));
            }
        }
        else
        {
            throw MissingInputFile;
        }
    }

    void Simulate()
    {
        for(int i = 0; i < years; i++)
        {
            income = 0;
            Visit(i);
        }
        string s;
        if (condition > 67)
        {
            s = "jo";
        }
        else if (condition > 33)
        {
            s = "atlagos";
        }
        else
        {
            s = "lepusztult";
        }
        cout << "A varos allapota " << s << " volt a(z) " << years << ". ev utan. (" << condition << ")" << endl;
    }

protected:

private:
    long double income;
    int condition;
    int years;
    vector<Tourist* > tourists;

    void Visit (int i)
    {
        double t;
        double tempcond = 0;
        t = tourists[i*3]->Visit(condition);
        cout << i+1 << ". evben " << tourists[i*3]->Visitors() << " japan latogatot terveztek es " << t << " jott a varos allapota miatt." << endl;
        tempcond += t*0;
        income += t*100000;
        t = tourists[i*3+1]->Visit(condition);
        cout << i+1 << ". evben " << tourists[i*3+1]->Visitors() << " modern latogatot terveztek es " << t << " jott a varos allapota miatt." << endl;
        tempcond += t/100;
        income += t*100000;
        t = tourists[i*3+2]->Visit(condition);
        cout << i+1 << ". evben " << tourists[i*3+2]->Visitors() << " harmadik vilagi latogatot terveztek es " << t << " jott a varos allapota miatt." << endl;
        tempcond += t/50;
        income += t*100000;
        condition -= tempcond;
        condition < 1 ? condition = 1 : true;
        string s;
        if (condition > 67)
        {
            s = "jo";
        }
        else if (condition > 33)
        {
            s = "atlagos";
        }
        else
        {
            s = "lepusztult";
        }
        cout << "A varos allapota " << s << " volt a felujitas elott. (" << condition << ")" << endl;
        cout << "A varos eves bevetele " << income*1000 << "ft volt." << endl << endl;
        Refurbish();
    }

    void Refurbish ()
    {
        int x = income - 1000000000;
        if (x > 0)
        {
            for (unsigned int i = 0; i < (unsigned)x; i+= 20000000)
            {
                condition < 100 ? condition++ : true;
            }
        }
    }

};

#endif // TOWN_H
