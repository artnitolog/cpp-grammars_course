#include <iostream>
#include <cstdint>

// This kind of Ackermann function is used to
// check students' ability to shoot the legs off

class Result {
public:
    Result(int64_t val) : val_{val} {}
    int64_t val_{};
};

void func(int64_t a, int64_t b, uint32_t k) {
    try {
        if (k == 0) {
            throw Result(a + b);
        } else if (k > 0 && b == 1) {
            throw Result(a);
        } else if (k > 0 && b > 1) {
            try {
                func(a, b - 1, k);
            } catch (Result &r) {
                func(a, r.val_, k - 1);
            }
        }
    } catch (Result &r) {
        throw;
    }
}

int main() {
    int64_t a, b;
    uint32_t k;
    while (std::cin >> a >> b >> k) {
        try {
            func(a, b, k);
        } catch (Result &r) {
            std::cout << r.val_ << std::endl;
        }
    }
}