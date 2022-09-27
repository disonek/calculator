#include <cassert>
#include <numeric>
#include <vector>

#include "abstract_visitor/abstract_visitor.hpp"

void basic_abstract_visitor_test()
{
    std::vector<std::unique_ptr<av::expression>> expresions{};
    expresions.push_back(std::make_unique<av::div>());
    expresions.push_back(std::make_unique<av::add>());
    expresions.push_back(std::make_unique<av::sub>());
    expresions.push_back(std::make_unique<av::mul>());

    std::unique_ptr<av::visitor> visitor = std::make_unique<av::visitor_concrete>(5, 5);

    int result{};
    for(auto& expr : expresions)
    {
        result += expr->accept(visitor);
    }

    assert(36 == result);
}