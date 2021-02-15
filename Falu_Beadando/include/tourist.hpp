#pragma once

using namespace std;

class Tourist
{
    public:
        Tourist(double x) : visitors(x) {}
        double Visitors() { return visitors; }
        virtual double Visit(int x) = 0;

    protected:
        double visitors;
};
