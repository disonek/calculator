#pragma once
#include <memory>

class Add;
class Subtraction;
class Divide;
class Multiply;

class Visitor
{
public:
    virtual int visitAdd(std::unique_ptr<Add> expr) const = 0;
    virtual int visitSub(std::unique_ptr<Subtraction> expr) const = 0;
    virtual int visitDiv(std::unique_ptr<Divide> expr) const = 0;
    virtual int visitMul(std::unique_ptr<Multiply> expr) const = 0;
};