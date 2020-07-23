#include <algorithm>
#include <iostream>
#include <iomanip>
#include <vector>

class Mean {
public:
    Mean() = default;
    void operator()(double cur) {
        sum_ += cur;
        ++size_;
    }
    double get() {
        return sum_ / size_;
    }
private:
    double sum_{};
    int size_{};
};


int main() {
    double cur;
    std::vector<double> v;
    while (std::cin >> cur) {
        v.push_back(cur);
    }
    int frac = v.size() / 10;
    auto left = v.begin() + frac;
    auto right = v.end() - frac;
    std::sort(left, right);
    frac = std::distance(left, right) / 10;
    left += frac;
    right -= frac;
    std::cout << std::setprecision(10) << 
            std::for_each(left, right, Mean()).get() << std::endl;
    return 0;
}