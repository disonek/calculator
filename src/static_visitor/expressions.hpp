#pragma once
#include <stdexcept>

namespace sv {

class add
{
public:
    int evaluate(int leftHand, int rightHand) const
    {
        return leftHand + rightHand;
    }
};

class sub
{
public:
    int evaluate(int leftHand, int rightHand) const
    {
        return leftHand - rightHand;
    }
};

class div
{
public:
    int evaluate(int leftHand, int rightHand) const
    {
        if(rightHand == 0)
        {
            throw std::logic_error("Devide by 0 exception");
        }

        return leftHand / rightHand;
    }
};

class mul
{
public:
    int evaluate(int leftHand, int rightHand) const
    {
        return leftHand * rightHand;
    }
};

} // namespace sv