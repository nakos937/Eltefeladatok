#pragma once
#include "tourist.hpp"

class Japanese : public Tourist
{
public:
    Japanese (double x) : Tourist(x) {}
    virtual double Visit(int x) override
    {
        double t;
        if (x > 67)
        {
            t=visitors*1.2;
        }
        else if (x > 33)
        {
            t=visitors;
        }
        else
        {
            t=visitors*0;
        }
        return t;
    }
};
