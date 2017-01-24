#pragma once

#include <map>
#include "Target.h"

class Data
{
public:
    Data();
    ~Data();
private:
    size_t price;
    std::map<Target, size_t> set;
};

