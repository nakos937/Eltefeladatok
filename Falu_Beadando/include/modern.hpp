#pragma once
#include "tourist.hpp"

class Modern : public Tourist
{
public:
    Modern (double x) : Tourist(x) {}
    virtual double Visit(int x) override
    {
        double t;
        if (x > 67)
        {
            t=visitors*1.3;
        }
        else if (x > 33)
        {
            t=visitors*1.1;
        }
        else
        {
            t=visitors;
        }
        return t;
    }
};
