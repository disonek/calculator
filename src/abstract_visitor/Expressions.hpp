#pragma once
#include "Visitor.hpp"

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
    virtual ~Add() = default;
    Add(int leftHand, int rightHand)
        : Expression(leftHand, rightHand)
    {
    }

    int accept(std::unique_ptr<Visitor>& visitor) const override
    {
        return visitor->visitAdd(std::make_unique<Add>(*this));
    }

    int evaluate() const override
    {
        return leftHand + rightHand;
    }
};

class Subtraction : public Expression
{
public:
    virtual ~Subtraction() = default;
    Subtraction(int leftHand, int rightHand)
        : Expression(leftHand, rightHand)
    {
    }

    int accept(std::unique_ptr<Visitor>& visitor) const override
    {
        return visitor->visitSub(std::make_unique<Subtraction>(*this));
    }

    int evaluate() const override
    {
        return leftHand - rightHand;
    }
};

class Divide : public Expression
{
public:
    virtual ~Divide() = default;
    Divide(int leftHand, int rightHand)
        : Expression(leftHand, rightHand)
    {
    }

    int accept(std::unique_ptr<Visitor>& visitor) const override
    {
        return visitor->visitDiv(std::make_unique<Divide>(*this));
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
    virtual ~Multiply() = default;
    Multiply(int leftHand, int rightHand)
        : Expression(leftHand, rightHand)
    {
    }
    int accept(std::unique_ptr<Visitor>& visitor) const override
    {
        return visitor->visitMul(std::make_unique<Multiply>(*this));
    }
    int evaluate() const override
    {
        return leftHand * rightHand;
    }
};