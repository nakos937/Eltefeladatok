#include "contestEnor.h"
#include <string>


struct Angler {
    std::string id;
    bool skillful;
};

class AnglerEnor{
    private:
        ContestEnor tt;
        Angler current;
        bool end;
    public:
        AnglerEnor(const std::string &str): tt(str) { };
        void first() {tt.first(); next();}
        void next();
        Angler Current() const { return current;}
        bool End() const { return end;}
};

