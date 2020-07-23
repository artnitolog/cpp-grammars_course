#include <complex>
#include <utility>
#include <array>
#include <vector>
#include <limits>

namespace Equations {
template <typename T>
std::pair<bool, std::vector<std::complex<T>>> quadratic(std::array<std::complex<T>, 3> v) {
    auto eps = std::numeric_limits<T>::epsilon() * 32;
    if (std::norm(v[2]) < eps) {
        if (std::norm(v[1]) < eps) {
            if (std::norm(v[0]) < eps) {
                return {false, {}};
            } else {
                return {true, {}};
            }
        } else {
            return {true, {-v[0] / v[1]}};
        }
    } else {
        auto d = std::sqrt(v[1] * v[1] - T{4} * v[0] * v[2]);
        auto z1 = (-v[1] - d) / (T{2} * v[2]);
        auto z2 = (-v[1] + d) / (T{2} * v[2]);
        return {true, {z1, z2}};
    }
}
}
