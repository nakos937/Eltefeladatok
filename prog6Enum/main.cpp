// Keszitette:  Nagy Ákos
// Email:       nakos1212@protonmail.com
// Datum:       2020.04.01
// Feladat:     12.	Feladat
//              Egy étteremben a pincérek által felvett rendeléseket egy szekvenciális input fájlban tartják nyilván
//              az ételek neve, azon belül a rendelések időpontja szerint rendezett formában.
//              A tárolt adatok: a rendelt étel neve, a rendelés időpontja, rendelt adagok száma, egy adag ára.
//              Melyik étel hozta az étteremnek a legtöbb bevételt (összesített darab*egységár)?

#include <iostream>
#include "foodEnor.h"

using namespace std;

int main()
{
    FoodEnor enor("input.txt");
    enor.first();
    if(enor.end())
    {
        cout << "Nem volt rendeles!" << endl;
    }
    else
    {
        Bevetel maxInc = enor.current();
        enor.next();
        while(!enor.end())
        {
            Bevetel dx = enor.current();
            if(dx.income > maxInc.income)
            {
                maxInc = dx;
            }
            enor.next();
        }
        cout << "A legnagyobb bevetelt a(z) " << maxInc.foodName << " hozta: " << maxInc.income << endl;
    }
}
