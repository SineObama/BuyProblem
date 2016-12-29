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
    Data a;
    return a;
}

Database &Database::operator=(const Database &) { return *this; }
