// Keszitette:  Nagy Ákos
// Email:       nakos1212@protonmail.com
// Datum:       2020.04.01
// Feladat:
//              Egy szekvenciális inputfájl ételreceptek hozzávalóit tartalmazza. A fájl egy eleme egy recept nevéből (sztring), és annak
//              egyik hozzávalójának anyagnevéből (sztring), mennyiségéből (természetes szám) és mennyiségi egységéből (sztring) áll. A
//              fájl nem üres, és recept nevek szerint rendezett, így ugyanazon recept hozzávalói közvetlenül egymás után helyezkednek
//              el.  Melyik ételrecepthez kell a legtöbb összetevő?

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
        Most maxIngredient = enor.current();
        enor.next();
        while(!enor.end())
        {
            Most dx = enor.current();
            if(dx.totalIngredientCount > maxIngredient.totalIngredientCount)
            {
                maxIngredient = dx;
            }
            enor.next();
        }
        cout << "A legtobb osszetevo a(z) " << maxIngredient.foodName << " etelhez kell: " << maxIngredient.totalIngredientCount << endl;
    }
}
