#pragma once

#include "Form.h"
#include "Target.h"

class Database
{
public:
    typedef Form<Target, std::string, size_t> Form;

    static Database &getInstance();
    Form select(size_t n, const std::string *requirements);  // 返回含有需求的套餐的表格

private:
    Database();
    Database(const Database &);
    Database &operator=(const Database &);

    Form *form;
};

