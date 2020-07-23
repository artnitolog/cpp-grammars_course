#include <cstdint>

class Sum {
public:
    Sum(int64_t a, int64_t b) : a_(a), b_(b) {}
    Sum(const Sum &s, int64_t c) : a_(s.a_ + s.b_), b_(c) {}
    int64_t get() const { return a_ + b_; }
private:
    int64_t a_, b_;
};
