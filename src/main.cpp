// #include <iostream>
#include <vector>

#include "abstract_visitor/abstract_visitor.hpp"
// #include <fc/static_variant.hpp>

// #include "static_visitor/expressions.hpp"
// #include "static_visitor/static_visitor.hpp"

// int main()
// {
//     std::vector<stat::operation> operations{
//         stat::add{123, 123}, stat::sub{123, 123}, stat::mul{123, 123}, stat::div{123, 123}};

//     for(auto operation : operations)
//     {
//         std::cout << operation.visit(stat::static_visitor{}) << std::endl;
//     }
// }

// int abstract_visitor()
// {
//     std::vector<std::unique_ptr<expression>> expresions{};
//     expresions.push_back(std::make_unique<add>(22, 33));
//     expresions.push_back(std::make_unique<sub>(33, 11));
//     expresions.push_back(std::make_unique<mul>(22, 33));
//     expresions.push_back(std::make_unique<div>(33, 11));

//     int addExpresionsResults{};
//     std::unique_ptr<Visitor> visitor = std::make_unique<VisitorConcrete>();
//     for(auto& expression : expresions)
//     {
//         addExpresionsResults += expression->accept(visitor);
//     }

//     std::cout << addExpresionsResults << std::endl;
// }