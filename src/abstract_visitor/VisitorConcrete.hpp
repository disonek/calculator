#pragma once
#include "Expressions.hpp"
#include "Visitor.hpp"

namespace abstr {
class VisitorConcrete : public Visitor
{
public:
    int visitAdd(const Add& expr) const override
    {
        return expr.evaluate();
    }

    int visitSub(const Subtraction& expr) const override
    {
        return expr.evaluate();
    }

    int visitDiv(const Divide& expr) const override
    {
        return expr.evaluate();
    }

    int visitMul(const Multiply& expr) const override
    {
        return expr.evaluate();
    }
};
} // namespace abstr