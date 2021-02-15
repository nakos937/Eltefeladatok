// Keszitette:  Nagy Ákos
// Email:       nakos1212@protonmail.com
// Datum:       2020.04.01
// Feladat:     12.	Feladat
//              Egy étteremben a pincérek által felvett rendeléseket egy szekvenciális input fájlban tartják nyilván
//              az ételek neve, azon belül a rendelések időpontja szerint rendezett formában.
//              A tárolt adatok: a rendelt étel neve, a rendelés időpontja, rendelt adagok száma, egy adag ára.
//              Melyik étel hozta az étteremnek a legtöbb bevételt (összesített darab*egységár)?

#include <string>
#include <fstream>
#include <iosfwd>

struct Rendeles
{
    std::string foodName;
    int hour;
    int minute;
    int orderCount;
    int unitPrice;
    friend std::istream& operator>>(std::istream& is, Rendeles &x);
};

struct Bevetel
{
    std::string foodName;
    int income;
};

class FoodEnor
{
public:
    enum Status {norm, abnorm};
    enum Exceptions {FILE_ERROR};
    FoodEnor(const std::string &path);
    void first();
    void next();
    Bevetel current() const
    {
        return _current;
    }
    bool end() const
    {
        return _end;
    }
private:
    std::ifstream _f;
    Status _sx;
    Bevetel _current;
    Rendeles _dx;
    bool _end;
    void read();
};
