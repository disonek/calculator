#include <iostream>
#include <vector>

#include "abstract_visitor/VisitorConcrete.hpp"

int main()
{
    std::vector<std::unique_ptr<Expression>> expresions{};
    // expresions.push_back(std::make_unique<Add>(22, 33));
    // expresions.push_back(std::make_unique<Subtraction>(33, 11));
    // expresions.push_back(std::make_unique<Multiply>(22, 33));
    // expresions.push_back(std::make_unique<Divide>(33, 11));

    int addExpresionsResults{};
    std::unique_ptr<Visitor> visitor = std::make_unique<VisitorConcrete>();
    for(auto& expression : expresions)
    {
        addExpresionsResults += expression->accept(visitor);
    }

    std::cout << addExpresionsResults << std::endl;
}