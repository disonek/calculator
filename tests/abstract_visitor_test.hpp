#include <cassert>
#include <numeric>
#include <vector>

#include "abstract_visitor/abstract_visitor.hpp"

void basic_abstract_visitor_test()
{
    std::vector<std::unique_ptr<av::expression>> expresions{};
    expresions.push_back(std::make_unique<av::div>(5, 5));
    expresions.push_back(std::make_unique<av::add>(5, 5));
    expresions.push_back(std::make_unique<av::sub>(5, 5));
    expresions.push_back(std::make_unique<av::mul>(5, 5));

    std::unique_ptr<av::visitor> visitor = std::make_unique<av::visitor_concrete>();

    int result{};
    for(auto& expr : expresions)
    {
        result += expr->accept(visitor);
    }

    assert(36 == result);
}