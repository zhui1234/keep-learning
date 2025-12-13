/* UTF-8 */
#include <iostream>
#include <cstdio>
#include <cstdint>
#include <type_traits>
#include "bigint.hpp"

namespace bigint {

BigInt::Digit::Digit(const std::string& raw_str)
    : digit({}), digit_num(0), digit_sign(0) {
    if (!isValidStr(raw_str)) {
        std::cerr << "Error:大整数字符串不合法" << std::endl;
        return;
    }
    int str_len = raw_str.size(), str_start = 0;
    if (raw_str[0] == '+' || raw_str[0] == '-') {
        str_start = 1;
        if (raw_str[0] == '-') digit_sign = 1;
    }
    while (raw_str[str_start] == '0' && str_start < str_len - 1) {
        str_start++;
    }
    digit_num = str_len - str_start;
    for (int i = str_len - 1; i >= str_start; i--) {
        digit.push_back(raw_str[i] - '0');
    }
    normalize();
}

BigInt::Digit::Digit(const int intanger)
    : digit({}), digit_num(0), digit_sign(0) {
    if (intanger == 0) {
        digit.push_back(0);
        digit_num = 1;
        digit_sign = 0;
        return;
    }
    int temp = intanger;
    if (temp < 0) {
        temp = -temp;
        digit_sign = 1;
    }
    while (temp) {
        digit.push_back(temp % 10);
        digit_num++;
        temp /= 10;
    }
}

bool BigInt::Digit::isZero() const {
    if (digit_num == 1 && digit[0] == 0) return 1;
    return 0;
}

bool BigInt::Digit::isValidStr(const std::string& num_raw) {
    int str_len = num_raw.size(), str_start = 0;
    if (!str_len) {
        return 0;
    }
    if (num_raw[0] == '+' || num_raw[0] == '-') {
        str_start = 1;
        if (str_len == 1) return 0;
    }
    for (int i = str_start; i < str_len; i++) {
        if (!(num_raw[i] >= '0' && num_raw[i] <= '9')) return 0;
    }
    return 1;
}

int BigInt::Digit::compareAbsoluteDigits(
    const Digit& digit1, const Digit& digit2
) {
    if (digit1.digit_num != digit2.digit_num) {
        if (digit1.digit_num > digit2.digit_num) return 1;
        return -1;
    }
    for (int i = digit1.digit_num - 1; i >= 0; i--) {
        if (digit1.digit[i] != digit2.digit[i]) {
            if (digit1.digit[i] > digit2.digit[i]) return 1;
            return -1;
        }
    }
    return 0;
}

void BigInt::Digit::normalize() {
    while (!digit[digit_num - 1] && digit_num > 1) {
        digit.pop_back();
        digit_num--;
    }
    if (isZero()) {
        digit_sign = 0;
    }
}

BigInt::Digit BigInt::Digit::addAbsolute(const Digit& other) const {
    int max_num = std::max(digit_num, other.digit_num);
    Digit result = Digit();
    result.digit.resize(max_num, 0);
    result.digit_num = max_num;
    uint8_t carry = 0;
    for (int i = 0; i < max_num; i++) {
        uint8_t a = (i < digit_num) ? digit[i] : 0;
        uint8_t b = (i < other.digit_num) ? other.digit[i] : 0;
        uint8_t sum = a + b + carry;
        result.digit[i] = sum % 10;
        carry = sum / 10;
    }
    if (carry > 0) {
        result.digit.push_back(carry);
        result.digit_num++;
    }
    return result;
}

BigInt::Digit BigInt::Digit::subAbsolute(const Digit& other) const {
    int max_num = std::max(digit_num, other.digit_num);
    Digit result = Digit();
    result.digit.resize(max_num, 0);
    result.digit_num = max_num;
    bool carry = 0;
    bool p = compareAbsoluteDigits(*this, other) >= 0;
    for (int i = 0; i < max_num; i++) {
        uint8_t a = (i < digit_num) ? digit[i] : 0;
        uint8_t b = (i < other.digit_num) ? other.digit[i] : 0;
        int8_t sum = p ? a - b : b - a;
        if (carry) sum--;
        if (sum >= 0) {
            result.digit[i] = sum;
            carry = 0;
        } else {
            result.digit[i] = sum + 10;
            carry = 1;
        }
    }
    result.normalize();
    result.digit_sign = !p;
    return result;
}

BigInt::Digit BigInt::Digit::mulAbsolute(const Digit& other) const {
    int num1 = digit_num;
    int num2 = other.digit_num;
    Digit result = Digit();
    result.digit.resize(num1 + num2, 0);
    result.digit_num = num1 + num2;
    for (int i = 0; i < num1; i++)
        for (int j = 0; j < num2; j++) {
            int pos = i + j;
            uint8_t a = digit[i];
            uint8_t b = other.digit[j];
            uint8_t sum = a * b + result.digit[pos];
            result.digit[pos] = sum % 10;
            result.digit[pos + 1] += sum / 10;
        }
    result.normalize();
    return result;
}

BigInt::Digit BigInt::Digit::divAbsolute(const Digit& other) const {
    if (other.isZero()) {
        throw std::runtime_error("Division by zero");
    }
    if (compareAbsoluteDigits(*this, other) == -1) return Digit("0");
    if (compareAbsoluteDigits(*this, other) == 0) return Digit("1");
    int num1 = digit_num;
    Digit reverse_result = Digit();
    Digit remainder = Digit();
    Digit temp[10] = {};
    for (int i = 0; i <= 9; i++) {
        temp[i] = other.mulAbsolute(Digit(i));
    }
    for (int i = num1 - 1; i >= 0; i--) {
        if (!remainder.isZero()) {
            remainder.digit_num++;
            remainder.digit.push_back(0);
            for (int j = remainder.digit.size() - 1; j > 0; j--)
                remainder.digit[j] = remainder.digit[j - 1];
        }
        remainder.digit[0] = digit[i];
        for (int j = 9; j >= 0; j--) {
            Digit sub = remainder.subAbsolute(temp[j]);
            if (sub.digit_sign == 0) {
                reverse_result.digit.push_back(j);
                remainder = sub;
                break;
            }
        }
    }
    Digit result = Digit();
    int finish = 0;
    while (!reverse_result.digit[finish] && finish < num1 - 1) {
        finish++;
    }
    result.digit_num = num1 - finish;
    for (int i = num1 - 1; i >= finish; i--) {
        result.digit.push_back(reverse_result.digit[i]);
    }
    return result;
}

BigInt::Digit BigInt::Digit::modAbsolute(const Digit& other) const {
    if (other.isZero()) {
        throw std::runtime_error("Division by zero");
    }
    if (compareAbsoluteDigits(*this, other) == -1) return Digit("0");
    if (compareAbsoluteDigits(*this, other) == 0) return Digit("1");
    int num1 = digit_num;
    Digit remainder = Digit();
    Digit temp[10] = {};
    for (int i = 0; i <= 9; i++) {
        temp[i] = other.mulAbsolute(Digit(i));
    }
    for (int i = num1 - 1; i >= 0; i--) {
        if (!remainder.isZero()) {
            remainder.digit_num++;
            remainder.digit.push_back(0);
            for (int j = remainder.digit.size() - 1; j > 0; j--)
                remainder.digit[j] = remainder.digit[j - 1];
        }
        remainder.digit[0] = digit[i];
        for (int j = 9; j >= 0; j--) {
            Digit sub = remainder.subAbsolute(temp[j]);
            if (sub.digit_sign == 0) {
                remainder = sub;
                break;
            }
        }
    }
    remainder.digit_num = remainder.digit.size();
    remainder.normalize();
    return remainder;
}

BigInt::BigInt() : _digit() {}

BigInt::BigInt(const BigInt& other) : _digit(other._digit) {}

BigInt::BigInt(const std::string& raw_str) : _digit(raw_str) {}

BigInt::BigInt(const int intanger) : _digit(intanger) {}

BigInt::operator bool() const { return !_digit.isZero(); }

BigInt& BigInt::operator=(const BigInt& rhs) {
    if (this == &rhs) return *this;
    _digit.digit = rhs._digit.digit;
    _digit.digit_num = rhs._digit.digit_num;
    _digit.digit_sign = rhs._digit.digit_sign;
    return *this;
}

BigInt& BigInt::operator=(const BigInt&& rhs) {
    if (this == &rhs) return *this;
    _digit.digit = std::move(rhs._digit.digit);
    _digit.digit_num = rhs._digit.digit_num;
    _digit.digit_sign = rhs._digit.digit_sign;
    return *this;
}

int BigInt::getDigitsNum() const { return _digit.digit_num; }

std::string BigInt::getStr() const {
    std::string result = "";
    if (_digit.digit_sign) {
        result.push_back('-');
    }
    for (int i = _digit.digit_num - 1; i >= 0; i--) {
        result.push_back(_digit.digit[i] + '0');
    }
    return result;
}

std::string BigInt::getAbsStr() const {
    std::string result = "";
    for (int i = _digit.digit_num - 1; i >= 0; i--) {
        result.push_back(_digit.digit[i] + '0');
    }
    return result;
}

int BigInt::compareAbsolute(const BigInt& lhs, const BigInt& rhs) {
    return Digit::compareAbsoluteDigits(lhs._digit, rhs._digit);
}

BigInt& BigInt::operator+=(const BigInt& rhs) {
    if (_digit.digit_sign == rhs._digit.digit_sign) {
        Digit digit_abs = _digit.addAbsolute(rhs._digit);
        digit_abs.digit_sign = _digit.digit_sign;
        _digit = digit_abs;
    } else {
        Digit digit_abs = _digit.subAbsolute(rhs._digit);
        digit_abs.digit_sign ^= _digit.digit_sign;
        _digit = digit_abs;
    }
    return *this;
}

BigInt& BigInt::operator-=(const BigInt& rhs) {
    if (_digit.digit_sign != rhs._digit.digit_sign) {
        Digit digit_abs = _digit.addAbsolute(rhs._digit);
        digit_abs.digit_sign = _digit.digit_sign;
        _digit = digit_abs;
    } else {
        Digit digit_abs = _digit.subAbsolute(rhs._digit);
        digit_abs.digit_sign ^= _digit.digit_sign;
        _digit = digit_abs;
    }
    return *this;
}

BigInt& BigInt::operator*=(const BigInt& rhs) {
    Digit digit_abs = _digit.mulAbsolute(rhs._digit);
    digit_abs.digit_sign = _digit.digit_sign ^ rhs._digit.digit_sign;
    _digit = digit_abs;
    return *this;
}

BigInt& BigInt::operator/=(const BigInt& rhs) {
    Digit digit_abs = _digit.divAbsolute(rhs._digit);
    digit_abs.digit_sign = _digit.digit_sign ^ rhs._digit.digit_sign;
    _digit = digit_abs;
    return *this;
}

BigInt& BigInt::operator%=(const BigInt& rhs) {
    Digit digit_abs = _digit.modAbsolute(rhs._digit);
    digit_abs.digit_sign = 0;
    _digit = digit_abs;
    return *this;
}

BigInt operator+(const BigInt& lhs, const BigInt& rhs) {
    BigInt result = lhs;
    result += rhs;
    return result;
}

BigInt operator-(const BigInt& lhs, const BigInt& rhs) {
    BigInt result = lhs;
    result -= rhs;
    return result;
}

BigInt operator*(const BigInt& lhs, const BigInt& rhs) {
    BigInt result = lhs;
    result *= rhs;
    return result;
}

BigInt operator/(const BigInt& lhs, const BigInt& rhs) {
    BigInt result = lhs;
    result /= rhs;
    return result;
}

BigInt operator%(const BigInt& lhs, const BigInt& rhs) {
    BigInt result = lhs;
    result %= rhs;
    return result;
}

bool operator==(const BigInt& lhs, const BigInt& rhs) {
    return lhs.getStr() == rhs.getStr();
}

bool operator!=(const BigInt& lhs, const BigInt& rhs) {
    return lhs.getStr() != rhs.getStr();
}

bool operator>(const BigInt& lhs, const BigInt& rhs) {
    if (lhs._digit.digit_sign != rhs._digit.digit_sign) {
        if (lhs._digit.digit_sign == 0) return 1;
        return 0;
    }
    if (lhs._digit.digit_sign == 0)
        return BigInt::compareAbsolute(lhs, rhs) == 1;
    return BigInt::compareAbsolute(lhs, rhs) == -1;
}

bool operator>=(const BigInt& lhs, const BigInt& rhs) {
    if (lhs._digit.digit_sign != rhs._digit.digit_sign) {
        if (lhs._digit.digit_sign == 0) return 1;
        return 0;
    }
    if (lhs._digit.digit_sign == 0)
        return BigInt::compareAbsolute(lhs, rhs) >= 0;
    return BigInt::compareAbsolute(lhs, rhs) <= 0;
}

bool operator<(const BigInt& lhs, const BigInt& rhs) { return !(lhs >= rhs); }

bool operator<=(const BigInt& lhs, const BigInt& rhs) { return !(lhs > rhs); }
}  // namespace bigint