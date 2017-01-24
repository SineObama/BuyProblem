#include "stdafx.h"
#include "Database.h"
#include <fstream>
#include <map>
#include <set>

Database &Database::getInstance() {
    static Database _instance;
    return _instance;
}

Database::Database()
{
    std::ifstream ifs("../database.txt");

    std::map<Target, size_t> targets;
    std::map<std::string, size_t> items;
    form = new Form(targets.size(), items.size());

    ifs.close();
}

Database::Form Database::select(size_t n, const std::string *requirements) {
    size_t *ci = new size_t[n];
    for (size_t i = 0; i < n; i++) {
        size_t j = 0;
        for (; j < form->columns; j++)
            if (form->c[j] == requirements[i])
                break;
        if (j >= form->columns)
            throw; // TODO ÕÒ²»µ½
        ci[i] = j;
    }
    size_t *ri = new size_t[form->rows];
    size_t rows = 0;
    for (size_t i = 0; i < form->rows; i++) {
        bool empty = true;
        for (size_t j = 0; j < n; j++) {
            if (form->d[i][ci[j]] > 0) {
                empty = false;
                break;
            }
        }
        if (!empty)
            ri[rows++]= i;
    }
    Form rtn(rows, n);
    for (size_t j = 0; j < n; j++)
        rtn.c[j] = requirements[j];
    for (size_t i = 0; i < rows; i++) {
        rtn.r[i] = form->r[ri[i]];
        for (size_t j = 0; j < n; j++)
            rtn.d[i][j] = form->d[ri[i]][ci[j]];
    }

    delete[] ci;
    delete[] ri;
    return rtn;
}

Database &Database::operator=(const Database &) { return *this; }
