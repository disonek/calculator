#include <array>
#include <cassert>
#include <numeric>

#include "abstract_visitor/abstract_visitor.hpp"

void basic_abstract_visitor_test()
{
    std::array<std::unique_ptr<av::expression>, 4> expresions{std::make_unique<av::add>(),
                                                              std::make_unique<av::sub>(),
                                                              std::make_unique<av::mul>(),
                                                              std::make_unique<av::div>()};

    std::unique_ptr<av::expression_visitor> visitor = std::make_unique<av::expression_evaluator>(5, 5);

    int result{};
    for(auto& expr : expresions)
    {
        expr->accept(visitor);
        result += visitor->get_result();
    }

    assert(36 == result);
}

void abstract_divide_by_zero()
{
    av::div div{};

    std::unique_ptr<av::expression_visitor> visitor = std::make_unique<av::expression_evaluator>(5, 0);

    try
    {
        div.accept(visitor);
        assert(false);
    }
    catch(const std::exception& err)
    {
    }
}