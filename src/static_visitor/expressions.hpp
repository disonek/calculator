#pragma once
namespace sv {

template <typename T>
class expression
{
public:
    expression(int leftHand, int rightHand)
        : leftHand{leftHand}
        , rightHand{rightHand}
    {
    }

    int evaluate() const
    {
        return T{}.evaluate(leftHand, rightHand);
    }

protected:
    int leftHand;
    int rightHand;
};

class add_opperation
{
public:
    int evaluate(int leftHand, int rightHand) const
    {
        return leftHand + rightHand;
    }
};

class sub_opperation
{
public:
    int evaluate(int leftHand, int rightHand) const
    {
        return leftHand - rightHand;
    }
};

class div_opperation
{
public:
    int evaluate(int leftHand, int rightHand) const
    {
        if(rightHand == 0)
        {
            // throw exception
        }

        return leftHand / rightHand;
    }
};

class mul_opperation
{
public:
    int evaluate(int leftHand, int rightHand) const
    {
        return leftHand * rightHand;
    }
};

using add = expression<add_opperation>;
using sub = expression<sub_opperation>;
using div = expression<div_opperation>;
using mul = expression<mul_opperation>;
} // namespace sv