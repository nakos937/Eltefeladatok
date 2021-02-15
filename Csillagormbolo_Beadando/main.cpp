// Keszitette:  Nagy Ákos
// Email:       nakos1212@protonmail.com
#include <iostream>
#include <sstream>
#include "library/summation.hpp"
#include "library/maxsearch.hpp"
#include "library/stringstreamenumerator.hpp"
#include "library/seqinfileenumerator.hpp"

using namespace std;

struct Ship
{
    string name;
    int affilation;
    int health;
    int armor;
    double shield;
    double score;

    friend istream &operator>>(istream &is, Ship &s)
    {
        is >> s.name >> s.affilation >> s.health >> s.armor >> s.shield;
        s.score = (s.health+s.armor)*s.shield;
        return is;
    }

};

struct Scores
{
    int Affilation;
    double Score;
    Scores() {}
    Scores(int a, double s) : Affilation(a), Score(s) {}
};

class MyRebelSummation : public Summation<Ship, Scores>
{
protected:

    Scores func(const Ship &e) const override
    {
        return Scores(e.affilation,e.score);
    }
    Scores neutral() const override
    {
        return Scores(1,0);
    }
    Scores add(const Scores &a, const Scores &b) const override
    {
        return Scores(1,cond(a)&&cond(b)?a.Score+b.Score:0);
    }
    bool cond(const Scores& e) const
    {
        return e.Affilation == 1;
    }
};

class MyEmpireSummation : public Summation<Ship, Scores>
{
protected:

    Scores func(const Ship &e) const override
    {
        return Scores(e.affilation,e.score);
    }
    Scores neutral() const override
    {
        return Scores(0,0);
    }
    Scores add(const Scores &a, const Scores &b) const override
    {
        return Scores(0,cond(a)&&cond(b)?a.Score+b.Score:0);
    }
    bool  cond(const Scores& e) const
    {
        return e.Affilation == 0;
    }
};

class MyMaxSearch : public MaxSearch<Scores, int, Greater<int>>
{
protected:
    int func(const Scores &e) const override
    {
        return e.Score;
    };
};

istream &operator>>(istream &is, Scores &b)
{
    string line;
    getline(is, line);
    stringstream ss(line);
    MyRebelSummation pr1;
    MyEmpireSummation pr2;
    StringStreamEnumerator<Ship> enor1(ss);
    StringStreamEnumerator<Ship> enor2(ss);
    pr1.addEnumerator(&enor1);
    pr1.run();
    pr2.addEnumerator(&enor2);
    pr2.run();

    //cout << pr1.result().Score << " " << pr1.result().Affilation << endl;
    //cout << pr2.result().Score << " " << pr2.result().Affilation << endl;

    pr1.result().Score > pr2.result().Score? b.Affilation = 1 : b.Affilation = 0;
    pr1.result().Score > pr2.result().Score? b.Score = pr1.result().Score : b.Score = pr2.result().Score;

    return is;
}

int main(int argc, char *argv[])
{
    string inputfile_name = (argc==1)? "test4.txt" : argv[1];
    try
    {
        MyMaxSearch pr;
        SeqInFileEnumerator<Scores> enor(inputfile_name);

        pr.addEnumerator(&enor);

        pr.run();

        if (pr.found())
        {
            pr.optElem().Affilation == 0? cout << 'E' : cout << 'R';
        }
        else
        {
            cout<<"D";
        }
    }
    catch(const SeqInFileEnumerator<Scores>::Exceptions& e)
    {
        std::cerr << "Nem létezik a fájl" << '\n';
    }



    return 0;

}
