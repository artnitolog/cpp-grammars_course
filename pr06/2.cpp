#include <algorithm>

template <typename T>
class Coord {
public:
    typedef T value_type;
    T row{}, col{};
    Coord(T r = 0, T c = 0) : row{r}, col{c} {}
};


template <typename CoorT>
auto dist(const CoorT &size, const CoorT &p1, const CoorT &p2) {
    auto m0 = p1.row > p2.row ? p1.row - p2.row : p2.row - p1.row;
    auto n0 = p1.col > p2.col ? p1.col - p2.col : p2.col - p1.col;
    return std::max(std::min(m0, size.row - m0), std::min(n0, size.row - n0));
}