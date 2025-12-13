/* UTF-8 */
/**
 * @file bigint.hpp
 * @brief 包含了大整数运算的类的定义
 */
#ifndef BIG_INT_HPP
#define BIG_INT_HPP
#include <iostream>
#include <cstdint>
#include <cstring>
#include <vector>
#include <type_traits>

namespace bigint {
class BigInt {
private:
    struct Digit {
    public:
        std::vector<uint8_t> digit;
        int digit_num;
        bool digit_sign;
        Digit() : digit({}), digit_num(0), digit_sign(0) {}
        Digit(const Digit& other) = default;
        Digit(const std::string& raw_str);
        Digit(const int intanger);

    private:
        friend class BigInt;
        /**
         * @brief 判断数字是否为零
         * @return true 为零
         * @return false 非零
         */
        bool isZero() const;
        /**
         * @brief 判断字符串是否正确表示大整数
         * @param raw_str 表示大整数的字符串
         * @return true 字符串合法
         * @return false 字符串非法
         */
        bool isValidStr(const std::string& raw_str);
        Digit addAbsolute(const Digit& other) const;
        Digit subAbsolute(const Digit& other) const;
        Digit mulAbsolute(const Digit& other) const;
        Digit divAbsolute(const Digit& other) const;
        Digit modAbsolute(const Digit& other) const;
        /**
         * @brief 比较两个大整数的大小关系
         * @param digit1 前一个数
         * @param digit2 后一个数
         * @return 1 digit1>digit2
         * @return 0 digit1=digit2
         * @return -1 digit1<digit2
         */
        static int compareAbsoluteDigits(
            const Digit& digit1, const Digit& digit2
        );
        void normalize();
    };

    Digit _digit;

public:
    BigInt();
    BigInt(const BigInt& other);
    explicit BigInt(const std::string& raw_str);
    explicit BigInt(const int intanger);
    /**
     * @brief 复制构造函数
     * @param rhs 需要复制的原对象
     * @return 当前对象的左值引用
     */
    BigInt& operator=(const BigInt& rhs);
    /*** @brief 移动构造函数
     * @param rhs 需要移动的原对象
     * @return 当前对象的左值引用
     * @note rhs在移动后若要使用，应当重新赋值
     */
    BigInt& operator=(const BigInt&& rhs);
    /**
     * @brief Get the Digits Num object
     * @return std::int 整数位数,不计入前导零
     */
    int getDigitsNum() const;
    std::string getStr() const;
    std::string getAbsStr() const;
    static int compareAbsolute(const BigInt& lhs, const BigInt& rhs);

    BigInt& operator+=(const BigInt& rhs);
    BigInt& operator-=(const BigInt& rhs);
    BigInt& operator*=(const BigInt& rhs);
    BigInt& operator/=(const BigInt& rhs);
    BigInt& operator%=(const BigInt& rhs);
    explicit operator bool() const;

    friend BigInt operator+(const BigInt& lhs, const BigInt& rhs);
    friend BigInt operator-(const BigInt& lhs, const BigInt& rhs);
    friend BigInt operator*(const BigInt& lhs, const BigInt& rhs);
    friend BigInt operator/(const BigInt& lhs, const BigInt& rhs);
    friend BigInt operator%(const BigInt& lhs, const BigInt& rhs);
    friend bool operator==(const BigInt& lhs, const BigInt& rhs);
    friend bool operator!=(const BigInt& lhs, const BigInt& rhs);
    friend bool operator>(const BigInt& lhs, const BigInt& rhs);
    friend bool operator>=(const BigInt& lhs, const BigInt& rhs);
    friend bool operator<(const BigInt& lhs, const BigInt& rhs);
    friend bool operator<=(const BigInt& lhs, const BigInt& rhs);
};
}  // namespace bigint
#endif