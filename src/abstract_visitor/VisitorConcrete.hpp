#pragma once
#include "Expressions.hpp"
#include "Visitor.hpp"

class VisitorConcrete : public Visitor
{
public:
    int visitAdd(std::unique_ptr<Add> expr) const override
    {
        return expr->evaluate();
    }

    int visitSub(std::unique_ptr<Subtraction> expr) const override
    {
        return expr->evaluate();
    }

    int visitDiv(std::unique_ptr<Divide> expr) const override
    {
        return expr->evaluate();
    }

    int visitMul(std::unique_ptr<Multiply> expr) const override
    {
        return expr->evaluate();
    }
};