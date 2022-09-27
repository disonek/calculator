#pragma once

#include <fc/static_variant.hpp>

#include "expressions.hpp"

namespace sv {
using operation = fc::static_variant<add, sub, div, mul>;

struct static_visitor
{
    using result_type = int;

    template <typename Expression>
    result_type operator()(const Expression& a) const
    {
        return a.evaluate();
    }
};

} // namespace sv