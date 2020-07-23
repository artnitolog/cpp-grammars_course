#include "cmc_complex.h"
#include "cmc_complex_stack.h"
#include "cmc_complex_eval.h"

#include <iostream>
#include <string>
#include <cmath>
#include <cstdlib>

std::ostream &operator<<(std::ostream &out, const numbers::complex &z) {
    return out << z.to_string();
}

int main(int argc, char *argv[]) {
    numbers::complex c{argv[1]};
    double r{std::strtod(argv[2], NULL)};
    int n{std::strtol(argv[3], NULL, 10)};
    std::vector <std::string> f(argv + 4, argv + argc);
    numbers::complex integral{};
    numbers::complex z_prev = c + r;
    for (int k = 1; k <= n; k++) {
        double phi = 2 * M_PI * k / n;
        numbers::complex z_cur = c + r * numbers::complex{std::cos(phi), std::sin(phi)};
        integral += numbers::eval(f, (z_cur + z_prev) / 2) * (z_cur - z_prev);
        z_prev = z_cur;
    }
    std::cout << integral << std::endl;
    return 0;
}