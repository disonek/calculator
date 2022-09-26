#pragma once
namespace stat {

class Expression
{
public:
    virtual ~Expression() = default;

    Expression(int leftHand, int rightHand)
        : leftHand{leftHand}
        , rightHand{rightHand}
    {
    }

protected:
    int leftHand;
    int rightHand;
};

class Add : public Expression
{
public:
    Add(int leftHand, int rightHand)
        : Expression(leftHand, rightHand)
    {
    }

    int evaluate() const
    {
        return leftHand + rightHand;
    }
};

class Subtraction : public Expression
{
public:
    Subtraction(int leftHand, int rightHand)
        : Expression(leftHand, rightHand)
    {
    }

    int evaluate() const
    {
        return leftHand - rightHand;
    }
};

class Divide : public Expression
{
public:
    Divide(int leftHand, int rightHand)
        : Expression(leftHand, rightHand)
    {
    }

    int evaluate() const
    {
        if(rightHand == 0)
        {
            // throw exception
        }

        return leftHand / rightHand;
    }
};

class Multiply : public Expression
{
public:
    Multiply(int leftHand, int rightHand)
        : Expression(leftHand, rightHand)
    {
    }

    int evaluate() const
    {
        return leftHand * rightHand;
    }
};
} // namespace stat