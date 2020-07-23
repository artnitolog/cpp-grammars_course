#include <string>
#include <iostream>
#include <sstream>
#include <stdexcept>
#include <exception>
#include <type_traits>
#include <algorithm>
#include <vector>

namespace RangeImpl {
void FormatCheck(const std::string &str) {
    size_t c1_pos, c2_pos, c3_pos;
    c1_pos = str.find('(');
    c2_pos = str.find(',');
    c3_pos = str.find(')');
    if (c1_pos != 0 || c2_pos == std::string::npos || c3_pos != str.length() - 1) {
        throw std::invalid_argument("cant we talk it over");
    }
}
}

template<class T>
class Range {
public:
    static_assert((std::is_signed_v<T> && std::is_integral_v<T>) ||
            std::is_class_v<T>, "lightning strikes me");
    Range(T left = {}, T right = {}) : low{left}, high{right} { check(); }
    explicit Range(const std::string &str) {
        RangeImpl::FormatCheck(str);
        if constexpr (std::is_class_v<T>) {
            size_t pos = str.find(',');
            low = T(str.substr(1, pos - 1));
            high = T(str.substr(pos + 1, str.length() - pos - 2));
        } else {
            size_t pos1, pos2;
            long long left, right;
            try {
                left = std::stoll(str.substr(1), &pos1);
                right = std::stoll(str.substr(pos1 + 2), &pos2);
            } catch (const std::out_of_range &e) {
                throw std::range_error("what have i got to do"); 
            }
            if (str[pos1 + 1] != ',' ||  str[pos1 + pos2 + 2] != ')') {
                throw std::invalid_argument("to make you love my");
            }
            if (static_cast<T>(left) != left || static_cast<T>(right) != right) {
                throw std::range_error("to make you care"); 
            }
            low = left;
            high = right;
        }
        check();
    }
    std::string to_string() const {
        std::ostringstream oss;
        oss << "(" << +low << "," << +high << ")";
        return oss.str();
    }
    T get_low() const {
        return low;
    }
    T get_high() const {
        return high;
    }
    const Range &operator*=(const Range &other) {
        std::vector<T> v(4);
        if constexpr (std::is_class_v<T>) {
            v[0] = low * other.low;
            v[1] = low * other.high;
            v[2] = high * other.low;
            v[3] = high * other.high;
        } else {
            if (__builtin_mul_overflow(low, other.low, &v[0]) ||
                    __builtin_mul_overflow(low, other.high, &v[1]) ||
                    __builtin_mul_overflow(high, other.low, &v[2]) ||
                    __builtin_mul_overflow(high, other.high, &v[3])) {
                throw std::overflow_error("it\'s saaad");
            }
        }
        low = *std::min_element(v.begin(), v.end());
        high = *std::max_element(v.begin(), v.end());
        return *this;
    }
    const Range operator-() const {
        auto tmp = Range(-1, -1);
        return tmp *= *this;
    }
    const Range &operator+=(const Range &other) {
        if constexpr (std::is_class_v<T>) {
            low = low + other.low;
            high = high + other.high;
        } else {
            if (__builtin_add_overflow(low, other.low, &low) ||
                    __builtin_add_overflow(high, other.high, &high)) {
                throw std::overflow_error("so saaad");
            }
        }
        return *this;
    }
    const Range &operator-=(const Range &other) {
        return *this += -other;
    }

    friend Range operator+(Range r1, const Range &r2) {
        return r1 += r2;
    }
    friend Range operator-(Range r1, const Range &r2) {
        return r1 -= r2;
    }
    friend Range operator*(Range r1, const Range &r2) {
        return r1 *= r2;
    }
private:
    T low{}, high{};
    void check() {
        // std::cout << low << " " << high << std::endl;
        if (high < low) {
            throw std::invalid_argument("it\'s a sad, sad situation");
        }
    }
};

// struct A {};

// int main() {
//     std::string str = "(12asdf34,56789338382)";
//     size_t pos = str.find(',');
//     std::cout << "[" << str.substr(1, pos - 1) << ";" << str.substr(pos + 1, str.length() - pos - 2) << "]\n";
// }