// #include <iostream>
#include <vector>

// #include "abstract_visitor/VisitorConcrete.hpp"
#include <fc/static_variant.hpp>

// #include "static_visitor/Expressions.hpp"
#include "static_visitor/static_visitor.hpp"

int main()
{
    std::vector<stat::operation> operations{
        stat::Add{123, 123}, stat::Subtraction{123, 123}, stat::Multiply{123, 123}, stat::Divide{123, 123}};

    for(auto operation : operations)
    {
        std::cout << operation.visit(stat::static_visitor{}) << std::endl;
    }
}

// int abstract_visitor()
// {
//     std::vector<std::unique_ptr<Expression>> expresions{};
//     expresions.push_back(std::make_unique<Add>(22, 33));
//     expresions.push_back(std::make_unique<Subtraction>(33, 11));
//     expresions.push_back(std::make_unique<Multiply>(22, 33));
//     expresions.push_back(std::make_unique<Divide>(33, 11));

//     int addExpresionsResults{};
//     std::unique_ptr<Visitor> visitor = std::make_unique<VisitorConcrete>();
//     for(auto& expression : expresions)
//     {
//         addExpresionsResults += expression->accept(visitor);
//     }

//     std::cout << addExpresionsResults << std::endl;
// }