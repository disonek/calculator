#pragma once

namespace abstr {
class Add;
class Subtraction;
class Divide;
class Multiply;

class Visitor
{
public:
    virtual int visitAdd(const Add& expr) const = 0;
    virtual int visitSub(const Subtraction& expr) const = 0;
    virtual int visitDiv(const Divide& expr) const = 0;
    virtual int visitMul(const Multiply& expr) const = 0;
};
} // namespace abstr