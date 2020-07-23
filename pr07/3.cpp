#include <iostream>
#include <utility>

class S {
public:
    S() { 
        if (std::cin >> val_) {
            cin_flag_ = true;
        }
    }
    S(S &&other) : S() { 
        val_ += other.val_;
        move_flag_ = true; 
    }
    ~S() { 
        if (!cin_flag_ && move_flag_) {
            std::cout << val_;
        }
    }
    explicit operator bool() const {
        return cin_flag_;
    }
private:
    int val_{};
    bool cin_flag_{}, move_flag_{};
};