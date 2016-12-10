#include "stdafx.h"
#include "Database.h"
#include <fstream>

Database &Database::getInstance() {
    static Database _instance;
    return _instance;
}

Database::Database()
{
    std::ifstream ifs("../database.txt");

    ifs.close();
}

Data Database::select(requirement *items, size_t n) {

}

Database &Database::operator=(const Database &) {}

void Database::calc_o(size_t n, price_t *price, size_t m, require_t *require, data_t **data, times_t *times) {

}

void Database::calc(size_t n, price_t *price, size_t m, require_t *require, data_t **data, times_t *times) {

}
