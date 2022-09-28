#pragma once

namespace av {
class add;
class sub;
class div;
class mul;

class expression_visitor
{
public:
    virtual ~expression_visitor() = default;
    virtual void visitAdd(const add* expr) = 0;
    virtual void visitSub(const sub* expr) = 0;
    virtual void visitDiv(const div* expr) = 0;
    virtual void visitMul(const mul* expr) = 0;
    virtual int get_result() = 0;
};
} // namespace av