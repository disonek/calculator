#pragma once

namespace av {
class add;
class sub;
class div;
class mul;

class visitor
{
public:
    virtual ~visitor() = default;
    virtual int visit(const add* expr) const = 0;
    virtual int visit(const sub* expr) const = 0;
    virtual int visit(const div* expr) const = 0;
    virtual int visit(const mul* expr) const = 0;
};
} // namespace av