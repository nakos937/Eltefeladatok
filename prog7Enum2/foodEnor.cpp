// Keszitette:  Nagy Ákos
// Email:       nakos1212@protonmail.com
// Feladat:
//              Egy szekvenciális inputfájl ételreceptek hozzávalóit tartalmazza. A fájl egy eleme egy recept nevéből (sztring), és annak
//              egyik hozzávalójának anyagnevéből (sztring), mennyiségéből (természetes szám) és mennyiségi egységéből (sztring) áll. A
//              fájl nem üres, és recept nevek szerint rendezett, így ugyanazon recept hozzávalói közvetlenül egymás után helyezkednek
//              el.  Melyik ételrecepthez kell a legtöbb összetevő?

#include "foodEnor.h"
#include <iostream>
#include <sstream>

std::istream& operator>>(std::istream& is, Recept &x)
{
    is >> x.foodName >> x.ingredientName >> x.ingredientQuantity >> x.ingredientQuantityUnit;
    return is;
}

FoodEnor::FoodEnor(const std::string &path)
{
    _f.open(path.c_str());
    if(_f.fail())
    {
        throw FILE_ERROR;
    }
}

void FoodEnor::first()
{
    read();
    next();
}

void FoodEnor::next()
{
    _end = _sx == abnorm;

    if(_sx == norm)
    {
        _current.foodName = _dx.foodName;
        _current.totalIngredientCount = 1;
        read();
        while(_sx == norm && _current.foodName == _dx.foodName)
        {
            _current.totalIngredientCount ++;
            read();
        }
    }
}

void FoodEnor::read()
{
    if(_f >> _dx)
    {
        _sx = norm;
    }
    else
    {

        _sx = abnorm;
    }
}
