#include <algorithm>

namespace Game {
template <typename T>
class Coord {
public:
    typedef T value_type;
    T row{}, col{};
    Coord(T r = 0, T c = 0) : row{r}, col{c} {}
    Coord trans() const {
        return Coord(col, row - (col + 1) / 2);
    }
};

template <typename CoorT>
auto dist(const CoorT &size, const CoorT &p1, const CoorT &p2) {
    auto pp1 = p1.trans();
    auto pp2 = p2.trans();
    return std::max({
        std::abs(pp1.row - pp2.row), 
        std::abs(pp1.col - pp2.col), 
        std::abs(pp1.row + pp1.col - pp2.row - pp2.col)});
}
}