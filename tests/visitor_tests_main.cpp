#include <iostream>

#include "abstract_visitor_test.hpp"
#include "static_visitor_test.hpp"

int main()
{
    basic_static_visitor_test();
    basic_abstract_visitor_test();

    abstract_divide_by_zero();
    static_divide_by_zero();
    std::cout << "OK" << std::endl;
}
