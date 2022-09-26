#include <fc/static_variant.hpp>
#include <iostream>

int main()
{
    fc::variant_creator_functor<int> test{};
    std::cout << "ala" << std::endl;
}