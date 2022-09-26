#pragma once
#include <memory>

#include "Visitor.hpp"

namespace abstr {

class Expression
{
public:
    virtual ~Expression() = default;

    Expression(int leftHand, int rightHand)
        : leftHand{leftHand}
        , rightHand{rightHand}
    {
    }

    virtual int evaluate() const = 0;
    virtual int accept(std::unique_ptr<Visitor>& visitor) const = 0;

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

    int accept(std::unique_ptr<Visitor>& visitor) const override
    {
        return visitor->visitAdd(*this);
    }

    int evaluate() const override
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

    int accept(std::unique_ptr<Visitor>& visitor) const override
    {
        return visitor->visitSub(*this);
    }

    int evaluate() const override
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

    int accept(std::unique_ptr<Visitor>& visitor) const override
    {
        return visitor->visitDiv(*this);
    }

    int evaluate() const override
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
    int accept(std::unique_ptr<Visitor>& visitor) const override
    {
        return visitor->visitMul(*this);
    }
    int evaluate() const override
    {
        return leftHand * rightHand;
    }
};
} // namespace abstr