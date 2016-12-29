#pragma once

template<class T>
class Vector {
public:
    Vector() {
        size = 0;
        p = NULL;
    }
    Vector(size_t size) {
        this->size = size;
        this->p = new T[size];
        memset(this->p, 0, sizeof(T) * size);
    }
    Vector(size_t size, const T *p) {
        this->size = size;
        this->p = new T[size];
        for (size_t i = 0; i < size; i++)
            this->p[i] = p[i];
    }
    Vector(const Vector &o) {
        p = NULL;
        *this = o;
    }
    ~Vector() {
        delete[] this->p;
    }

    bool operator==(const Vector &o) {
        if (this != &o) {
            if (this->size != o.size)
                throw;  // TODO
            for (size_t i = 0; i < this->size; i++)
                if (this->p[i] != o.p[i])
                    return false;
        }
        return true;
    }
    Vector &operator=(const Vector &o) {
        if (this != &o) {
            this->size = o.size;
            delete[] this->p;
            this->p = new T[this->size];
            for (size_t i = 0; i < this->size; i++)
                this->p[i] = o.p[i];
        }
        return *this;
    }
    Vector operator+(const Vector &o) {
        if (this->size != o.size)
            throw;  // TODO
        Vector rtn;
        rtn.size = this->size;
        rtn.p = new T[this->size];
        for (size_t i = 0; i < this->size; i++)
            rtn.p[i] = this->p[i] + o.p[i];
        return rtn;
    }
    Vector operator-(const Vector &o) {
        if (this->size != o.size)
            throw;  // TODO
        Vector rtn;
        rtn.size = this->size;
        rtn.p = new T[this->size];
        for (size_t i = 0; i < this->size; i++) {
            if (this->p[i] > o.p[i])
                rtn.p[i] = this->p[i] - o.p[i];
            else
                rtn.p[i] = 0;
        }
        return rtn;
    }
//protected:
    size_t size;
    T *p;
};
