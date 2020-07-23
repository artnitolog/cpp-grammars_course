#include <cmath>
#include <string>

class Rectangle: public Figure {
public:
    Rectangle (double a, double b) : a_{a}, b_{b} {}
    double get_square() const override {
        return a_ * b_;
    }
    static Rectangle *make(const std::string &str) {
        size_t pos;
        double a = std::stod(str, &pos);
        double b = std::stod(str.substr(pos + 1));
        return new Rectangle(a, b);
    }
    std::string to_string() const override {
        return "R " + std::to_string(a_) + " " + std::to_string(b_);
    }
private:
    double a_{}, b_{};
};

class Square: public Figure {
public:
    Square(double a): a_{a} {}
    double get_square() const override {
        return a_ * a_;
    }
    static Square *make(const std::string &str) {
        return new Square(std::stod(str, nullptr));
    }
    std::string to_string() const override {
        return "S " + std::to_string(a_);
    }
private:
    double a_{};
};

class Circle: public Figure {
public:
    Circle(double r): r_{r} {}
    double get_square() const override {
        return M_PI * r_ * r_;
    }
    static Circle *make(const std::string &str) {
        return new Circle(std::stod(str, nullptr));
    }
    std::string to_string() const override {
        return "C " + std::to_string(r_);
    }
private:
    double r_{};
};