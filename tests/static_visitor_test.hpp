#include <cassert>
#include <iostream>
#include <vector>

#include "static_visitor/static_visitor.hpp"

void basic_static_visitor_test()
{
    std::vector<sv::operation> operations{sv::add{5, 5}, sv::sub{5, 5}, sv::mul{5, 5}, sv::div{5, 5}};

    int result{};

    for(auto operation : operations)
    {
        result += operation.visit(sv::static_visitor{});
    }

    assert(36 == result);
}