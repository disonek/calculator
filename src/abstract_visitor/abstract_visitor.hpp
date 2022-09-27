#pragma once
#include "expressions.hpp"

namespace av {

class visitor_concrete : public visitor
{
public:
    visitor_concrete(int leftHand, int rightHand)
        : leftHand{leftHand}
        , rightHand{rightHand}
    {
    }

    int visit(const add* expr) const override
    {
        return expr->evaluate(leftHand, rightHand);
    }

    int visit(const sub* expr) const override
    {
        return expr->evaluate(leftHand, rightHand);
    }

    int visit(const div* expr) const override
    {
        return expr->evaluate(leftHand, rightHand);
    }

    int visit(const mul* expr) const override
    {
        return expr->evaluate(leftHand, rightHand);
    }

protected:
    int leftHand;
    int rightHand;
};

} // namespace av
