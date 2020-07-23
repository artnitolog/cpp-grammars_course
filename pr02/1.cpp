#pragma once
#include <iostream>
#include <iomanip>
#include <cmath>
#include <string>

namespace numbers {
class complex {
public:
    complex(double re = 0, double im = 0) : re_(re), im_(im) {}

    explicit complex(const std::string &str) {
        size_t pos;
        re_ = std::stod(str.substr(1), &pos);
        im_ = std::stod(str.substr(pos + 2));
    }

    double re() const {
        return re_;
    }

    double im() const {
        return im_;
    }

    double abs2() const {
        return re_ * re_ + im_ * im_;
    }

    double abs() const {
        return std::sqrt(abs2());
    }

    std::string to_string() const {
        std::ostringstream obj;
        obj << std::setprecision(10);
        obj << "(" << re_ << "," << im_ << ")";
        return obj.str();
    }

    complex operator-() const {
        return complex(-re_, -im_);
    }

    complex operator~() const {
        return complex(re_, -im_);
    }

    const complex &operator+=(const complex &z) { 
        re_ += z.re_;
        im_ += z.im_;
        return *this;
    }

    const complex &operator-=(const complex &z) { 
        return *this += -z;
    }

    const complex &operator*=(const complex &z) { 
        double new_re = re_ * z.re_ - im_ * z.im_;
        double new_im = re_ * z.im_ + im_ * z.re_;
        re_ = new_re;
        im_ = new_im;
        return *this;
    }
    
    const complex &operator/=(const complex &z) {
        *this *= ~z;
        return *this *= 1 / z.abs2();
    }

private:
    double re_{}, im_{};
};

complex operator+(complex z1, const complex &z2) {
        return z1 += z2;
}
complex operator-(complex z1, const complex &z2) {
        return z1 -= z2;
}
complex operator*(complex z1, const complex &z2) {
        return z1 *= z2;
}
complex operator/(complex z1, const complex &z2) {
        return z1 /= z2;
}



}

// int main() {
//     numbers::complex z1(1, 1), z2(2, 2);
//     (z1 += z2) += z1;
//     std::cout << z1.to_string() << std::endl;
//     return 0;
// }