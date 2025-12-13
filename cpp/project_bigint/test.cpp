// test.cpp
#include "bigint.hpp"
#include <iostream>
#include <cassert>

void testConstructors() {
    std::cout << "=== 测试构造函数 ===" << std::endl;

    // 测试默认构造
    bigint::BigInt a;
    std::cout << "默认构造: " << a.getStr() << std::endl;

    // 测试字符串构造
    bigint::BigInt b("12345");
    std::cout << "字符串构造 '12345': " << b.getStr() << std::endl;

    // 测试整数构造
    bigint::BigInt c(6789);
    std::cout << "整数构造 6789: " << c.getStr() << std::endl;

    // 测试负数字符串
    bigint::BigInt d("-123");
    std::cout << "负数字符串 '-123': " << d.getStr() << std::endl;

    // 测试负整数
    bigint::BigInt e(-456);
    std::cout << "负整数 -456: " << e.getStr() << std::endl;

    std::cout << std::endl;
}

void testComparison() {
    std::cout << "=== 测试比较运算符 ===" << std::endl;

    bigint::BigInt a("100");
    bigint::BigInt b("200");
    bigint::BigInt c("100");

    std::cout << "100 == 100: " << (a == c) << " (应为 1)" << std::endl;
    std::cout << "100 != 200: " << (a != b) << " (应为 1)" << std::endl;
    std::cout << "100 < 200: " << (a < b) << " (应为 1)" << std::endl;
    std::cout << "200 > 100: " << (b > a) << " (应为 1)" << std::endl;
    std::cout << "100 >= 100: " << (a >= c) << " (应为 1)" << std::endl;
    std::cout << "100 <= 100: " << (a <= c) << " (应为 1)" << std::endl;

    // 测试负数比较
    bigint::BigInt d("-50");
    bigint::BigInt e("-100");
    std::cout << "-50 > -100: " << (d > e) << " (应为 1)" << std::endl;

    std::cout << std::endl;
}

void testArithmetic() {
    std::cout << "=== 测试算术运算 ===" << std::endl;

    // 加法
    bigint::BigInt a("123");
    bigint::BigInt b("456");
    bigint::BigInt sum = a + b;
    std::cout << "123 + 456 = " << sum.getStr() << " (应为 579)" << std::endl;

    // 减法
    bigint::BigInt c("1000");
    bigint::BigInt d("123");
    bigint::BigInt diff = c - d;
    std::cout << "1000 - 123 = " << diff.getStr() << " (应为 877)" << std::endl;

    // 负数加法
    bigint::BigInt e("-100");
    bigint::BigInt f("50");
    std::cout << "-100 + 50 = " << (e + f).getStr() << " (应为 -50)"
              << std::endl;

    // 乘法
    bigint::BigInt x("16151323");
    bigint::BigInt y("123445");
    std::cout << "16151323 * 123445 = " << (x * y).getStr()
              << " (应为 1993532029135)" << std::endl;

    // 除法
    bigint::BigInt m("635968243");
    bigint::BigInt n("-245962");
    std::cout << "635968243 / -245962 = " << (m / n).getStr() << " (应为 -2586)"
              << std::endl;
    // 取模
    bigint::BigInt p("10");
    bigint::BigInt q("3");
    std::cout << "10 % 3 = " << (p % q).getStr() << " (应为 1)" << std::endl;

    // 复合赋值
    bigint::BigInt g("500");
    g += bigint::BigInt("300");
    std::cout << "500 += 300 = " << g.getStr() << " (应为 800)" << std::endl;

    std::cout << std::endl;
}

void testEdgeCases() {
    std::cout << "=== 测试边界情况 ===" << std::endl;

    // 测试 0
    bigint::BigInt zero("0");
    std::cout << "零: " << zero.getStr() << " (应为 0)" << std::endl;

    // 测试大数
    bigint::BigInt big("123456789012345678901234567890");
    std::cout << "大数: " << big.getStr() << std::endl;

    // 测试 bool 转换
    std::cout << "零转换为bool: " << static_cast<bool>(zero)
              << " (应为 0/false)" << std::endl;

    bigint::BigInt nonZero("123");
    std::cout << "非零转换为bool: " << static_cast<bool>(nonZero)
              << " (应为 1/true)" << std::endl;

    std::cout << std::endl;
}

int main() {
    try {
        std::cout << "开始测试 BigInt 类..." << std::endl << std::endl;

        testConstructors();
        testComparison();
        testArithmetic();
        testEdgeCases();

        std::cout << "所有测试完成！" << std::endl;
        return 0;
    } catch (const std::exception& e) {
        std::cerr << "测试异常: " << e.what() << std::endl;
        return 1;
    }
}