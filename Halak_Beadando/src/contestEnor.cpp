#include "contestEnor.h"

using namespace std;

ContestEnor::ContestEnor(const std::string &str) throw (FileError)
{
    f.open(str);
    if(f.fail())
        throw MissingInputFile;
}

void ContestEnor::next()
{
    string line;
    getline(f, line);
    if( !(end = f.fail()) )
    {
        istringstream is(line);
        is >> current.angler >> current.contest;
        current.counter = 0;
        string fish;
        double size;
        bool l = false;
        for( is >> fish >> size ; !is.fail(); is >> fish >> size )
        {
            if(fish == "Harcsa")
            {
                ++current.counter;
                l = true;
            }
        }
        if(l)
        {
            current.catfishLines++;
        }
    }
}
