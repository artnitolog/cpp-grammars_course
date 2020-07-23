class Sub {
public:
    int value() const { return a_ - b_; }
    Sub(int a, int b) : a_(a), b_(b) {}
    Sub(const Sub &other, int c) : a_(other.value()), b_(c) {}
    Sub(int a, const Sub &other) : a_(a), b_(other.value()) {}
private:
    int a_{}, b_{};
};