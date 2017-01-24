#pragma once

template<class row, class column, class data>
class Form
{
public:
    Form(size_t rows, size_t columns);
    Form(const Form<row, column, data> &);
    ~Form();

    const size_t rows, columns;
    row *r;
    column *c;
    data **d;
};

template<class row, class column, class data>
Form<row, column, data>::Form(size_t rows, size_t columns) : rows(rows), columns(columns)
{
    r = new row[rows];
    c = new column[columns];
    d = new data*[rows];
    for (size_t i = 0; i < rows; i++)
        d[i] = new data[columns];
}

template<class row, class column, class data>
Form<row, column, data>::Form(const Form<row, column, data> &o) : rows(o.rows), columns(o.columns)
{
    r = new row[rows];
    for (size_t i = 0; i < rows; i++)
        r[i] = o.r[i];
    c = new column[columns];
    for (size_t i = 0; i < columns; i++)
        c[i] = o.c[i];
    d = new data*[rows];
    for (size_t i = 0; i < rows; i++)
        d[i] = new data[columns];
    for (size_t i = 0; i < rows; i++)
        for (size_t j = 0; j < columns; j++)
            d[i][j] = o.d[i][j];
}

template<class row, class column, class data>
Form<row, column, data>::~Form()
{
    for (size_t i = 0; i < rows; i++)
        delete[] d[i];
    delete[] d;
    delete[] c;
    delete[] r;
}
