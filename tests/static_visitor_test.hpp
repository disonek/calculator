#include <cassert>
#include <vector>

#include "static_visitor/static_visitor.hpp"

void basic_static_visitor_test()
{
    std::vector<sv::operation> operations{sv::add{}, sv::sub{}, sv::mul{}, sv::div{}};
    auto visitor = sv::static_visitor{5, 5};

    int result{};

    for(auto operation : operations)
    {
        result += operation.visit(visitor);
    }

    assert(36 == result);
}