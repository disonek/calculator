#pragma once
#include <memory>

#include "visitor.hpp"

namespace av {
class expression
{
public:
    virtual ~expression() = default;

    virtual int evaluate(int leftHand, int rightHand) const = 0;
    virtual int accept(std::unique_ptr<visitor>& visitor) const = 0;
};

class add : public expression
{
public:
    int accept(std::unique_ptr<visitor>& visitor) const override
    {
        return visitor->visit(this);
    }

    int evaluate(int leftHand, int rightHand) const override
    {
        return leftHand + rightHand;
    }
};

class sub : public expression
{
public:
    int accept(std::unique_ptr<visitor>& visitor) const override
    {
        return visitor->visit(this);
    }

    int evaluate(int leftHand, int rightHand) const override
    {
        return leftHand - rightHand;
    }
};

class div : public expression
{
public:
    int accept(std::unique_ptr<visitor>& visitor) const override
    {
        return visitor->visit(this);
    }

    int evaluate(int leftHand, int rightHand) const override
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
    int accept(std::unique_ptr<visitor>& visitor) const override
    {
        return visitor->visit(this);
    }
    int evaluate(int leftHand, int rightHand) const override
    {
        return leftHand * rightHand;
    }
};
} // namespace av