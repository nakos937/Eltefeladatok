// Keszitette:  Nagy Ákos
// Email:       nakos1212@protonmail.com
// Datum:       2020.04.01
// Feladat:
//              Egy szekvenciális inputfájl ételreceptek hozzávalóit tartalmazza. A fájl egy eleme egy recept nevéből (sztring), és annak
//              egyik hozzávalójának anyagnevéből (sztring), mennyiségéből (természetes szám) és mennyiségi egységéből (sztring) áll. A
//              fájl nem üres, és recept nevek szerint rendezett, így ugyanazon recept hozzávalói közvetlenül egymás után helyezkednek
//              el.  Melyik ételrecepthez kell a legtöbb összetevő?

#include <string>
#include <fstream>
#include <iosfwd>

struct Recept
{
    std::string foodName;
    std::string ingredientName;
    int ingredientQuantity;
    std::string ingredientQuantityUnit;
    friend std::istream& operator>>(std::istream& is, Recept &x);
};

struct Most
{
    std::string foodName;
    int totalIngredientCount;
};

class FoodEnor
{
public:
    enum Status {norm, abnorm};
    enum Exceptions {FILE_ERROR};
    FoodEnor(const std::string &path);
    void first();
    void next();
    Most current() const
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
    Most _current;
    Recept _dx;
    bool _end;
    void read();
};
