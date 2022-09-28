#pragma once

#include <fc/static_variant.hpp>
#include <iostream>

#include "expressions.hpp"

namespace sv {
using operation = fc::static_variant<add, sub, div, mul>;

struct expression_values
{
    int leftHand;
    int rightHand;
};

void print_result(int result)
{
    std::cout << "calculated by static visitor: " << result << "\n";
}

struct expression_evaluator
{
    expression_evaluator(int leftHand, int rightHand)
        : values{leftHand, rightHand}
    {
    }

    using result_type = int;

    template <typename Expression>
    result_type operator()(const Expression& a) const
    {
        return a.evaluate(values.leftHand, values.rightHand);
    }

protected:
    expression_values values;
};

struct expression_evaluator_and_printer
{
    expression_evaluator_and_printer(int leftHand, int rightHand)
        : values{leftHand, rightHand}
    {
    }

    using result_type = int;

    template <typename Expression>
    result_type operator()(const Expression& a) const
    {
        result_type result = a.evaluate(values.leftHand, values.rightHand);
        print_result(result);
        return result;
    }

protected:
    expression_values values;
};

struct expression_printer_sign_guarded
{
    expression_printer_sign_guarded(int leftHand, int rightHand, std::string sign)
        : values{leftHand, rightHand}
    {
    }

    using result_type = int;

    template <typename Expression>
    result_type operator()(const Expression& a) const
    {
        std::string supported_signs{"+-/*"};
        if(supported_signs.find(sign) == std::string::npos)
        {
            std::cout << "provided not supported operation"
                      << "\n";
            return 0;
            // I could throw an exception but for sake of simplicity I did just return 0
        }

        result_type result = a.evaluate(values.leftHand, values.rightHand);
        print_result(result);

        return result;
    }

protected:
    expression_values values;
    std::string sign;
};

} // namespace sv