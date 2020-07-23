class Figure {
public:
    virtual bool equals(const Figure *other) const = 0;
    virtual ~Figure() {}
};

class Rectangle: public Figure {
public:
    Rectangle (int a, int b) : a_{a}, b_{b} {}
    bool equals(const Figure *other) const override {
        const Rectangle &another = dynamic_cast<const Rectangle &>(*other);
        return another.a_ == a_ && another.b_ == b_;
    }
private:
    int a_{}, b_{};
};

class Triangle: public Figure {
public:
    Triangle (int a, int b, int c) : a_{a}, b_{b}, c_{c} {}
    bool equals(const Figure *other) const override {
        const Triangle &another = dynamic_cast<const Triangle &>(*other);
        return another.a_ == a_ && another.b_ == b_ && another.c_ == c_;
    }
private:
    int a_{}, b_{}, c_{};
};
