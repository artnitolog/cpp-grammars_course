#include <iostream>
#include <iomanip>
#include <cmath>

constexpr int PREC = 10;

int main() {
    double sum, sum2, cur;
    sum = 0;
    sum2 = 0;
    int n = 0;
    while (std::cin >> cur) {
        sum += cur;
        sum2 += cur * cur;
        ++n;
    }
    if (n == 0) {
        return 1;
    }
    double mean = sum / n;
    double std = std::sqrt((sum2 + n * mean * mean - 2 * mean * sum) / n);
    std::cout << std::setprecision(PREC) << mean << std::endl << std << std::endl;
    return 0;
}