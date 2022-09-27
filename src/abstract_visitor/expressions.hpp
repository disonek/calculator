#pragma once
#include <memory>

#include "visitor.hpp"

namespace av {
class expression
{
public:
    virtual ~expression() = default;

    expression(int leftHand, int rightHand)
        : leftHand{leftHand}
        , rightHand{rightHand}
    {
    }

    virtual int evaluate() const = 0;
    virtual int accept(std::unique_ptr<visitor>& visitor) const = 0;

protected:
    int leftHand;
    int rightHand;
};

class add : public expression
{
public:
    add(int leftHand, int rightHand)
        : expression(leftHand, rightHand)
    {
    }

    int accept(std::unique_ptr<visitor>& visitor) const override
    {
        return visitor->visit(this);
    }

    int evaluate() const override
    {
        return leftHand + rightHand;
    }
};

class sub : public expression
{
public:
    sub(int leftHand, int rightHand)
        : expression(leftHand, rightHand)
    {
    }

    int accept(std::unique_ptr<visitor>& visitor) const override
    {
        return visitor->visit(this);
    }

    int evaluate() const override
    {
        return leftHand - rightHand;
    }
};

class div : public expression
{
public:
    div(int leftHand, int rightHand)
        : expression(leftHand, rightHand)
    {
    }

    int accept(std::unique_ptr<visitor>& visitor) const override
    {
        return visitor->visit(this);
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

class mul : public expression
{
public:
    mul(int leftHand, int rightHand)
        : expression(leftHand, rightHand)
    {
    }
    int accept(std::unique_ptr<visitor>& visitor) const override
    {
        return visitor->visit(this);
    }
    int evaluate() const override
    {
        return leftHand * rightHand;
    }
};
} // namespace av