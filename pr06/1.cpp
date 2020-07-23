#include <iostream>
#include <algorithm>
#include <cmath>

int main() {
    unsigned m, n;
    std::cin >> m >> n;
    unsigned r1, c1, r2, c2;
    while (std::cin >> r1 >> c1 >> r2 >> c2) {
        unsigned dr = r1 > r2 ? r1 - r2 : r2 - r1;
        unsigned dc = c1 > c2 ? c1 - c2 : c2 - c1;
        std::cout << std::min(dr, m - dr) + std::min(dc, n - dc) << std::endl;
    }
    return 0;
}