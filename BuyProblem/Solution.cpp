#include "stdafx.h"
#include "Solution.h"
#include "Vector.h"

Solution::Solution() {}

void Solution::calc_o(size_t n, price_t *price, size_t m, data_t *require, data_t **data, size_t *times) {
    // TODO
    calc(n, price, m, require, data, times);
}

void Solution::calc(size_t n, price_t *price, size_t m, data_t *require, data_t **data, size_t *times) {
    Block block(n, m, require);

    std::cout << block.len << std::endl;

    for (size_t max = 0; max < n; max++) {
        block.refresh(max, price[max], data[max]);
    }
    memcpy(times, block.state[block.len - 1].times, sizeof(size_t) * n);
}
