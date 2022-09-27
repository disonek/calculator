#pragma once
#include "expressions.hpp"

namespace av {

class visitor_concrete : public visitor
{
public:
    int visit(const add* expr) const override
    {
        return expr->evaluate();
    }

    int visit(const sub* expr) const override
    {
        return expr->evaluate();
    }

    int visit(const div* expr) const override
    {
        return expr->evaluate();
    }

    int visit(const mul* expr) const override
    {
        return expr->evaluate();
    }
};

} // namespace av
