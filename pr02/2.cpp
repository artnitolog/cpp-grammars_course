#pragma once
#include <algorithm>
#include <string>

namespace numbers {
class complex_stack {
public:
    complex_stack(size_t size = 0)
            : size_{size}, reserved_{2 * size} {
        if (reserved_) {
            stack_ = new complex[reserved_];
        }
    }
    ~complex_stack() {
        delete[] stack_;
    }
    complex_stack(const complex_stack &other) 
            : size_{other.size_}, reserved_{other.reserved_} {
        if (other.stack_) {
            stack_ = new complex[reserved_];
            std::copy_n(other.stack_, size_, stack_);
        }
    }
    void swap(complex_stack &other) noexcept {
        std::swap(size_, other.size_);
        std::swap(reserved_, other.reserved_);
        std::swap(stack_, other.stack_);
    }
    const complex_stack &operator=(complex_stack other) {
        swap(other);
        return *this;
    }
    size_t size() const {
        return size_;
    }
    const complex &operator[](size_t idx) const {
        return stack_[idx];
    }
    complex operator+() const {
        return (*this)[size_ - 1];
    }
    complex_stack operator~() const {
        complex_stack tmp = *this;
        --tmp.size_;
        return tmp;
    }
    complex_stack operator<<(const complex &top) const {
        if (size_ == reserved_) {
            complex_stack tmp{size_ + 1};
            std::copy_n(stack_, size_, tmp.stack_);
            tmp.stack_[size_] = top;
            return tmp;
        }
        complex_stack tmp = *this;
        tmp.stack_[size_] = top;
        ++tmp.size_;
        return tmp;
    }
private:
    size_t size_{}, reserved_{};
    complex *stack_{};
};
}
