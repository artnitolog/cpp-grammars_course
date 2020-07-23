#include <iostream>

class A {
public:
    A() {
        std::cin >> num_;
    }

    A(const A &obj) : flag_{true} {
        std::cin >> num_;
        num_ += obj.num_;
    }

    ~A() {
        if (flag_) {
            std::cout << num_ << std::endl;
        }
    }

private:
    int num_;
    bool flag_{false};
};