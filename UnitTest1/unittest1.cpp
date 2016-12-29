#include "stdafx.h"
#include "CppUnitTest.h"
#include "Solution.h"

#include <tchar.h>
#include <windows.h>

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

typedef unsigned int data;

namespace UnitTest1
{
TEST_CLASS(SolutionTest)
{
public:

    TEST_METHOD(SolutionTest1)
    {
        const size_t p_n = 2;
        const size_t r_n = 1;
        data price[p_n] = { 1, 1 };
        data require[r_n] = { 2 };
        data da[p_n][r_n] = { { 1 },{ 2 } };
        data expected[p_n] = { 0, 1 };
        common<p_n, r_n>(price, require, da, expected);
    }

    TEST_METHOD(SolutionTest2)
    {
        const size_t p_n = 2;
        const size_t r_n = 1;
        data price[p_n] = { 1, 3 };
        data require[r_n] = { 4 };
        data da[p_n][r_n] = { { 2 },{ 3 } };
        data expected[p_n] = { 2, 0 };
        data result[p_n] = {};
        common<p_n, r_n>(price, require, da, expected);
    }

    TEST_METHOD(SolutionTest3)
    {
        const size_t p_n = 3;
        const size_t r_n = 1;
        data price[p_n] = { 2, 2, 3 };
        data require[r_n] = { 6 };
        data da[p_n][r_n] = { { 1 },{ 2 }, {5} };
        data expected[p_n] = { 1, 0, 1 };
        common<p_n, r_n>(price, require, da, expected);
    }

    TEST_METHOD(SolutionTest4)
    {
        const size_t p_n = 5;
        const size_t r_n = 1;
        data price[p_n] = { 6, 3, 2, 15, 3 };
        data require[r_n] = { 13 };
        data da[p_n][r_n] = { { 5 },{ 3 },{ 2 },{ 13 },{ 0 } };
        data expected[p_n] = { 0, 3, 2, 0, 0 };
        common<p_n, r_n>(price, require, da, expected);
    }
    TEST_METHOD(SolutionTest4_2)
    {
        const size_t p_n = 3;
        const size_t r_n = 1;
        data price[p_n] = { 4, 3, 2 };
        data require[r_n] = { 13 };
        data da[p_n][r_n] = { { 4 },{ 3 },{ 2 } };
        data expected[p_n] = { 1, 3, 0 };
        common<p_n, r_n>(price, require, da, expected);
    }
    TEST_METHOD(SolutionTest4_3)
    {
        const size_t p_n = 3;
        const size_t r_n = 1;
        data price[p_n] = { 4, 3, 2 };
        data require[r_n] = { 5 };
        data da[p_n][r_n] = { { 4 },{ 3 },{ 2 } };
        data expected[p_n] = { 0, 1, 1 };
        common<p_n, r_n>(price, require, da, expected);
    }
    TEST_METHOD(SolutionTest4_4)
    {
        const size_t p_n = 3;
        const size_t r_n = 1;
        data price[p_n] = { 5, 3, 1 };
        data require[r_n] = { 4 };
        data da[p_n][r_n] = { { 5 },{ 3 },{ 1 } };
        data expected[p_n] = { 0, 1, 1 };
        common<p_n, r_n>(price, require, da, expected);
    }
    TEST_METHOD(SolutionTest5)
    {
        const size_t p_n = 3;
        const size_t r_n = 2;
        data price[p_n] = { 5, 6, 5 };
        data require[r_n] = { 5, 5 };
        data da[p_n][r_n] = { { 1, 4 },{ 3, 3 },{ 4, 1 } };
        data expected[p_n] = { 1, 0, 1 };
        common<p_n, r_n>(price, require, da, expected);
    }

private:

    template<int p_n, int r_n>
    static void common(data *price, data *require, data da[][r_n], data *expected) {

        data result[p_n] = {};

        data *d[p_n] = {};
        for (int i = 0; i < p_n; i++)
            d[i] = da[i];
        Solution::calc(p_n, price, r_n, require, d, result);

        wchar_t *p = new wchar_t[100];
        for (int i = 0; i < p_n; i++) {
            std::stringstream ss;
            ss << "i=" << i << ",";
            const std::string &c = ss.str();
            c2w(p, c.size(), c.c_str());
            Assert::AreEqual(expected[i], result[i], p);
        }
        delete[] p;
    }

    static void c2w(wchar_t *pwstr, size_t len, const char *str) {
        if (str) {
            size_t nu = strlen(str);
            size_t n = (size_t)MultiByteToWideChar(CP_ACP, 0, (const char *)str, (int)nu, NULL, 0);
            if (n >= len)n = len;// 原本有-1的，但是感觉少了一个符号就改了
            MultiByteToWideChar(CP_ACP, 0, (const char *)str, (int)nu, pwstr, (int)n);
            pwstr[n] = 0;
        }
    }
};
}