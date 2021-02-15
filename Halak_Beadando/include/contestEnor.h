#include <fstream>
#include <sstream>
#include <string>
#ifndef CONTESTENOR_H
#define CONTESTENOR_H

struct Contest {
    std::string angler;
    std::string contest;
    int counter;
    int catfishLines;
};

class ContestEnor{
    private:
        std::ifstream f;
        Contest current;
        bool end;
    public:
        enum FileError{MissingInputFile};
        ContestEnor(const std::string &str) throw (FileError);
        void first() {current.catfishLines = 0; next();}
        void next();
        Contest Current() const { return current;}
        bool End() const { return end;}
};
#endif
