// Keszitette:  Nagy Ákos
// Email:       nakos1212@protonmail.com
#include <iostream>
#include "contestEnor.h"
#include "anglerEnor.h"

using namespace std;
bool first_search(const string &name, Contest& e)
{
    ContestEnor t(name);
    t.first();
    while(!t.End())
    {
        e = t.Current();
        t.next();
    }
    e = t.Current();
    return (e.catfishLines > 0);
}
bool second_search(const string &name, string &id)
{
    AnglerEnor t(name);
    bool l = false;
    for(t.first(); !l && !t.End(); t.next())
    {
        l = t.Current().skillful;
        id = t.Current().id;
    }
    return l;
}

#define NORMAL_MODE
#ifdef NORMAL_MODE

int main()
{

    string filename;
    cout << "Add meg a fajl nevet: ";
    cin >> filename;
    cout << "Elso feladat (Hany olyan sora van a fajlnak, melyben a fogott halak kozott a harcsa szerepel?):\n";
    try
    {
        Contest e;
        if(first_search(filename, e))
        {
            cout << "A fajlnak " << e.catfishLines << " sora van, melyben a fogott halak kozott harcsa szerepel." << endl;
        }
        else
        {
            cout << "Egyetlen olyan sora sincs a fajlnak, melyben a fogott halak kozott harcsa szerepelt volna.\n";
        }
    }
    catch(ContestEnor::FileError err)
    {
        cerr << "Nem talalhato ilyen bemenet: " << filename << "!" << endl;
    }
    cout << "\nMasodik feladat (Volt-e olyan horgasz, aki mindegyik versenyen fogott harcsat?):\n";
    try
    {
        string id;
        if(second_search(filename, id))
            cout << id << " minden versenyen fogott harcsat.";
        else
            cout << "Nincs ilyen horgasz.";
    }
    catch(ContestEnor::FileError err)
    {
        cerr << "Nem talalhato ilyen bemenet: " << filename << "!" << endl;
    }
    cout << endl;
    return 0;
}

#else
#define CATCH_CONFIG_MAIN
#include "catch.hpp"

TEST_CASE("first task empty file", "t0.txt") {
    Contest e;
    CHECK_FALSE(first_search("t0.txt", e));
}

TEST_CASE("first task 1 angler, true", "t2.txt") {
    Contest e;
    CHECK(first_search("t2.txt", e));
    CHECK(e.angler=="JANIBA");
}

TEST_CASE("first task 1 angler, false", "t13.txt") {
    Contest e;
    CHECK_FALSE(first_search("t13.txt", e));
}

TEST_CASE("first task more anglers", "tt3.txt") {
    Contest e;
    CHECK(first_search("tt3.txt", e));
    CHECK(e.catfishLines==3);
}

TEST_CASE("first task more anglers, no one meets the requirements", "t6.txt") {
    Contest e;
    CHECK_FALSE(first_search("t6.txt", e));
}

TEST_CASE("no catch", "t8.txt") {
    ContestEnor tt("t8.txt");
    tt.first();
    CHECK(tt.Current().counter == 0);
}

TEST_CASE("1 catch", "t3.txt") {
    ContestEnor tt("t3.txt");
    tt.first();
    CHECK(tt.Current().counter == 0);
}

TEST_CASE("more catches", "t2.txt") {
    ContestEnor tt("t2.txt");
    tt.first();
    CHECK(tt.Current().counter == 2);
}

TEST_CASE("first catch is catfish", "t2.txt") {
    ContestEnor tt("t2.txt");
    tt.first();
    CHECK(tt.Current().counter == 2);
}

TEST_CASE("last catch is catfish", "t2.txt") {
    ContestEnor tt("t2.txt");
    tt.first();
    CHECK(tt.Current().counter == 2);
}

TEST_CASE("no catfish", "t13.txt") {
    ContestEnor tt("t13.txt");
    tt.first();
    CHECK(tt.Current().counter == 0);
}

TEST_CASE("1 catfish", "t12.txt") {
    ContestEnor tt("t12.txt");
    tt.first();
    CHECK(tt.Current().counter == 1);
}

TEST_CASE("more catfishes", "t2.txt") {
    ContestEnor tt("t2.txt");
    tt.first();
    CHECK(tt.Current().counter == 2);
}

TEST_CASE("empty file", "t0.txt") {
    string id;
    CHECK_FALSE(second_search("t0.txt", id));
}

TEST_CASE("1 angler", "t2.txt") {
    string id;
    CHECK(second_search("t2.txt", id));
    CHECK(id=="JANIBA");
}

TEST_CASE("more angler more contests", "t4.txt") {
    string id;
    CHECK(second_search("t4.txt", id));
}

TEST_CASE("first angler is skillful", "t4.txt") {
    string id;
    CHECK(second_search("t4.txt", id));
    CHECK(id=="JANIBA");
}

TEST_CASE("last angler is skillful", "t5.txt") {
    string id;
    CHECK(second_search("t5.txt", id));
    CHECK(id=="KARIBA");
}

TEST_CASE("one skillful among more anglers more contests ", "t4.txt") {
    string id;
    CHECK(second_search("t4.txt", id));
}

TEST_CASE("no skillful anglers more contests ", "t6.txt") {
    string id;
    CHECK_FALSE(second_search("t6.txt", id));
}

TEST_CASE("more skillful anglers more contests ", "t14.txt") {
    string id;
    CHECK(second_search("t14.txt", id));
    CHECK(id=="NAGYHOHO");
}

TEST_CASE("no contest", "t1.txt") {
    AnglerEnor t("t1.txt");
    t.first();
    CHECK(t.Current().skillful);
}

TEST_CASE("1 angler 1 contest", "t2.txt") {
    AnglerEnor t("t2.txt");
    t.first();
    CHECK(t.Current().skillful);
}

TEST_CASE("1 angler more contest", "t3.txt") {
    AnglerEnor t("t3.txt");
    t.first();
    CHECK_FALSE(t.Current().skillful);
}

TEST_CASE("1 angler on his first contest did not catch any catfish", "t3.txt") {
    AnglerEnor t("t3.txt");
    t.first();
    CHECK_FALSE(t.Current().skillful);
}

TEST_CASE("1 angler on his last contest did not catch any catfish", "t9.txt") {
    AnglerEnor t("t9.txt");
    t.first();
    CHECK_FALSE(t.Current().skillful);
}

TEST_CASE("there is a skillful angler", "t11.txt") {
    AnglerEnor t("t11.txt");
    t.first();
    CHECK(t.Current().skillful);
}

TEST_CASE("no skillful angler", "t10.txt") {
    AnglerEnor t("t10.txt");
    t.first();
    CHECK_FALSE(t.Current().skillful);
}

TEST_CASE("there are more skillful anglers", "t7.txt") {
    AnglerEnor t("t7.txt");
    t.first();
    CHECK(t.Current().skillful);
}

#endif
