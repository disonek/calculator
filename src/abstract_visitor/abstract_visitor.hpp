#pragma once
#include <iostream>
#include <string>

#include "expressions.hpp"

namespace av {

class expression_evaluator : public expression_visitor
{
public:
    expression_evaluator(int leftHand, int rightHand)
        : leftHand{leftHand}
        , rightHand{rightHand}
        , result{}
    {
    }

    void visitAdd(const add* expr) override
    {
        result = expr->evaluate(leftHand, rightHand);
    }

    void visitSub(const sub* expr) override
    {
        result = expr->evaluate(leftHand, rightHand);
    }

    void visitDiv(const div* expr) override
    {
        result = expr->evaluate(leftHand, rightHand);
    }

    void visitMul(const mul* expr) override
    {
        result = expr->evaluate(leftHand, rightHand);
    }

    int get_result() override
    {
        return result;
    }

private:
    int leftHand;
    int rightHand;
    int result;
};

class expression_evaluate_and_print : public expression_evaluator
{
public:
    expression_evaluate_and_print(int leftHand, int rightHand)
        : expression_evaluator(leftHand, rightHand)
    {
    }

    void visitAdd(const add* expr) override
    {
        expression_evaluator::visitAdd(expr);
        print(get_result());
    }

    void visitSub(const sub* expr) override
    {
        expression_evaluator::visitSub(expr);
        print(get_result());
    }

    void visitDiv(const div* expr) override
    {
        expression_evaluator::visitDiv(expr);
        print(get_result());
    }

    void visitMul(const mul* expr) override
    {
        expression_evaluator::visitMul(expr);
        print(get_result());
    }

private:
    void print(int result)
    {
        std::cout << "calculated by abstract visitor: " << result << "\n";
    }
};

class expresion_allowed_sign_aware_printer : public expression_evaluate_and_print
{
public:
    expresion_allowed_sign_aware_printer(int leftHand, int rightHand, std::string sign)
        : expression_evaluate_and_print(leftHand, rightHand)
        , sign{sign}
    {
    }

    void visitAdd(const add* expr) override
    {
        if(!is_sign_supported() || sign != "+")
        {
            return;
        }
        expression_evaluate_and_print::visitAdd(expr);
    }

    void visitSub(const sub* expr) override
    {
        if(!is_sign_supported() || sign != "-")
        {
            return;
        }
        expression_evaluate_and_print::visitSub(expr);
    }

    void visitDiv(const div* expr) override
    {
        if(!is_sign_supported() || sign != "/")
        {
            return;
        }
        expression_evaluate_and_print::visitDiv(expr);
    }

    void visitMul(const mul* expr) override
    {
        if(!is_sign_supported() || sign != "*")
        {
            return;
        }
        expression_evaluate_and_print::visitMul(expr);
    }

private:
    bool is_sign_supported()
    {
        std::string supported_signs{"+-/*"};
        bool result = supported_signs.find(sign) != std::string::npos;
        if(!result)
        {
            std::cout << "provided not supported operation"
                      << "\n";
        }

        return result;
    }

    std::string sign;
};

} // namespace av
