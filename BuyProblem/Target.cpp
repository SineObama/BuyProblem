#include "stdafx.h"
#include "Target.h"

Target::Target() {}

Target::Target(size_t price, std::string type, std::string name) : price(price), type(type), name(name) {}

Target::Target(const Target &o) : price(o.price), type(o.type), name(o.name) {}

Target::~Target() {}

bool Target::operator<(const Target &o) {
    if (this == &o)
        return false;
    if (type != o.type)
        return type < o.type;
    return name < o.name;
}

bool Target::operator==(const Target &o) {
    if (this == &o)
        return true;
    return type == o.type && name == o.name;
}
