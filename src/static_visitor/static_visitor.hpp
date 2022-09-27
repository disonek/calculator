#pragma once

#include <fc/static_variant.hpp>

#include "expressions.hpp"

namespace sv {
using operation = fc::static_variant<add, sub, div, mul>;

struct static_visitor
{
    static_visitor(int leftHand, int rightHand)
        : leftHand{leftHand}
        , rightHand{rightHand}
    {
    }

    using result_type = int;

    template <typename Expression>
    result_type operator()(const Expression& a) const
    {
        return a.evaluate(leftHand, rightHand);
    }

private:
    int leftHand;
    int rightHand;
};

} // namespace sv