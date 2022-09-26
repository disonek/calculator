#pragma once

#include <fc/static_variant.hpp>
#include <iostream>

#include "Expressions.hpp"

namespace stat {
using operation = fc::static_variant<Add, Subtraction, Divide, Multiply>;

struct static_visitor
{
    using result_type = int;

    template <typename Expression>
    result_type operator()(const Expression& a) const
    {
        return a.evaluate();
    }
};

} // namespace stat