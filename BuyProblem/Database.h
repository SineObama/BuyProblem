#pragma once

#include "Data.h"

class Database
{
public:
    typedef std::pair<std::string, size_t> requirement;

    static Database &getInstance();
    Data select(requirement *, size_t n);

private:
    Database();
    Database(const Database &);
    Database &operator=(const Database &);
};

