#include <iostream>

namespace Sample {
template <class T, size_t m, size_t n> // m rows, n cols
class Matrix {
public:
    T *operator[](size_t idx1) {
        return matrix_[idx1];
    }
    const T *operator[](size_t idx1) const {
        return matrix_[idx1];
    }
private:
    T matrix_[m][n];
};
}