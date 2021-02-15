// Keszitette:  Nagy Ákos
// Email:       nakos1212@protonmail.com
#include <iostream>
#include "town.hpp"

using namespace std;
#define NORMAL_MODE
#ifdef NORMAL_MODE

int main()
{
    //const string s = "input.txt";
    const string s = "in1.txt";
    Town T (s);
    T.Simulate();
    return 0;
}

#else
#define CATCH_CONFIG_MAIN
#include "catch.hpp"

TEST_CASE("wrong input", "inp.txt")
{
    try
    {
        Town T ("inp.txt");
    }
    catch(Town::Exceptions ex)
    {
        CHECK(ex == Town::MissingInputFile);
    };
}
TEST_CASE("condition average", "in1.txt")
{
    Town T ("in1.txt");
    CHECK(T.GetTourists()[0]->Visitors() == 1000);
    CHECK(T.GetTourists()[0]->Visit(T.GetCondition()) == 1000);
    CHECK(T.GetTourists()[1]->Visitors() == 4000);
    CHECK(T.GetTourists()[1]->Visit(T.GetCondition()) == 4400);
    CHECK(T.GetTourists()[2]->Visitors() == 6000);
    CHECK(T.GetTourists()[2]->Visit(T.GetCondition()) == 6600);
    CHECK(T.GetCondition() < 67);
    CHECK(T.GetCondition() > 33);
}
TEST_CASE("condition good", "in2.txt")
{
    Town T ("in2.txt");
    CHECK(T.GetTourists()[0]->Visitors() == 2000);
    CHECK(T.GetTourists()[0]->Visit(T.GetCondition()) == 2400);
    CHECK(T.GetTourists()[1]->Visitors() == 3000);
    CHECK(T.GetTourists()[1]->Visit(T.GetCondition()) == 3900);
    CHECK(T.GetTourists()[2]->Visitors() == 8000);
    CHECK(T.GetTourists()[2]->Visit(T.GetCondition()) == 8000);
    CHECK(T.GetCondition() > 67);
}
TEST_CASE("condition ghetto", "in3.txt")
{
    Town T ("in3.txt");
    CHECK(T.GetTourists()[0]->Visitors() == 6500);
    CHECK(T.GetTourists()[0]->Visit(T.GetCondition()) == 0);
    CHECK(T.GetTourists()[1]->Visitors() == 5000);
    CHECK(T.GetTourists()[1]->Visit(T.GetCondition()) == 5000);
    CHECK(T.GetTourists()[2]->Visitors() == 3000);
    CHECK(T.GetTourists()[2]->Visit(T.GetCondition()) == 3000);
    CHECK(T.GetCondition() < 33);
}


#endif // NORMAL_MODE
