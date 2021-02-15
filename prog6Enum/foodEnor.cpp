// Keszitette:  Nagy Ákos
// Email:       nakos1212@protonmail.com
// Datum:       2020.04.01
// Feladat:     12.	Feladat
//              Egy étteremben a pincérek által felvett rendeléseket egy szekvenciális input fájlban tartják nyilván
//              az ételek neve, azon belül a rendelések időpontja szerint rendezett formában.
//              A tárolt adatok: a rendelt étel neve, a rendelés időpontja, rendelt adagok száma, egy adag ára.
//              Melyik étel hozta az étteremnek a legtöbb bevételt (összesített darab*egységár)?

#include "foodEnor.h"
#include <iostream>
#include <sstream>

std::istream& operator>>(std::istream& is, Rendeles &x)
{
    is >> x.foodName >> x.hour >> x.minute >> x.orderCount >> x.unitPrice;
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
        _current.income = _dx.orderCount * _dx.unitPrice;
        read();
        while(_sx == norm && _current.foodName == _dx.foodName)
        {
            _current.income += _dx.orderCount * _dx.unitPrice;
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
