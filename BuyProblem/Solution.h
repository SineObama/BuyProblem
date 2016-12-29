#pragma once

#include "Vector.h"

class Solution
{
public:
    typedef unsigned int price_t;
    typedef unsigned int data_t;

    static void calc_o(size_t n, price_t *price, size_t m, data_t *require, data_t **data, size_t *times);
    // 套餐个数n，套餐价格[n]；需求种类个数m，每个种类需求量[m]；套餐数据[n][m]；结果[n]
    static void calc(size_t n, price_t *price, size_t m, data_t *require, data_t **data, size_t *times);

private:
    Solution();


    class State {
    public:
        price_t price;
        size_t *times;
        State() {
            price = 0;
            times = NULL;
        }
        ~State() {
            delete[] times;
        }
        //State(size_t n) {
        //    price = 0;
        //    times = new ti
        //}
    };

    template<class T>
    class Index {
    public:
        Index(size_t dimension, const T *require) {
            this->dimension = dimension;

            base = new T[dimension];
            base[dimension - 1] = 1;
            for (size_t i = dimension - 1; i > 0; i--) {
                base[i - 1] = base[i] * (require[i] + 1);
            }

            max = new T[dimension];
            for (size_t i = 0; i < dimension; i++)
                max[i] = require[i] + 1;

            this->p = new T[dimension];
            memset(this->p, 0, sizeof(T) * dimension);
        }
        T get() {
            T sum = 0;
            for (size_t i = 0; i < dimension; i++) {
                sum += p[i] * base[i];
            }
            return sum;
        }
        Index &operator++(int) {
            int i = dimension - 1;
            p[i]++;
            while (i > 0) {
                if (p[i] < max[i])
                    break;
                p[i - 1] += p[i] / max[i];
                p[i] %= max[i];
                i--;
            }
            return *this;
        }
        ~Index() {
            delete[] base;
            delete[] max;
            delete[] p;
        }
        size_t dimension;
        T *base;
        T *max;
        T *p;
    };

    class Block {
    public:
        Block(size_t n, size_t m, data_t *require) {
            this->n = n;
            this->dimension = m;

            len = require[m - 1] + 1;
            for (int i = m - 1; i > 0; i--) {
                len *= require[i - 1] + 1;
            }

            this->require = new data_t[m];
            memcpy(this->require, require, sizeof(data_t) * m);

            state = new State[len];
            state[0].times = new size_t[n];
            memset(state[0].times, 0, sizeof(size_t) * n);
        }
        ~Block() {
            //delete[] base;
            delete[] state;
        }
        void refresh(size_t index, price_t price, data_t *provide) {
            const Vector<data_t> package(dimension, provide);// 套餐
            Index<data_t> cur(dimension, require);
            Index<data_t> I2(dimension, require);
            for (size_t i = 0; i < len; i++, cur++) {
                //std::cout << i << " " << cur.get() << "\n";
                Vector<data_t> curV(dimension, cur.p);
                Vector<data_t> V = curV - package;
                if (curV == V)
                    continue;
                memcpy(I2.p, V.p, sizeof(data_t) * dimension);
                size_t i2 = I2.get();
                if (state[i2].times != NULL)
                if (state[i].times == NULL || state[i].price > state[i2].price + price) {
                    delete[] state[i].times;
                    state[i].times = new size_t[n];
                    memcpy(state[i].times, state[i2].times, sizeof(size_t) * n);
                    state[i].times[index]++;
                    state[i].price = state[i2].price + price;
                }
            }
        }
    //private:
        size_t n;
        size_t len;
        size_t dimension;
        //require_t *base;
        data_t *require;
        State *state;
    };
};

