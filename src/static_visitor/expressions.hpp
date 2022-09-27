#pragma once
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
            // throw exception
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