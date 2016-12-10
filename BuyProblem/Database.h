#pragma once

#include "Data.h"

class Database
{
public:
    typedef unsigned int price_t;
    typedef unsigned int require_t;
    typedef unsigned int data_t;
    typedef unsigned int times_t;
    typedef std::pair<std::string, size_t> requirement;

    static Database &getInstance();
    Data select(requirement *, size_t n);

private:
    Database();
    Database(const Database &);
    Database &operator=(const Database &);

    static void calc_o(size_t n, price_t *, size_t m, require_t *, data_t **, times_t *);
    static void calc(size_t n, price_t *, size_t m, require_t *, data_t **, times_t *);
};

