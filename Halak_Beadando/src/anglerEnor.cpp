#include "anglerEnor.h"

using namespace std;

void AnglerEnor::next()
{
    if( !(end = tt.End()) ){
        current.id = tt.Current().angler;
        current.skillful = true;
        for( ; !tt.End() && tt.Current().angler == current.id; tt.next() ){
            current.skillful = current.skillful && (tt.Current().counter >=1);
        }
    }
}
