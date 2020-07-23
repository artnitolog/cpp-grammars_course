#include <iostream>
#include <string>

struct RevExcept {
    bool flag = 0;
    std::string str_{};
    RevExcept() = default;
    RevExcept(std::string &str) : flag{1}, str_{str} {}
    ~RevExcept() {
        if (flag) {
            std::cout << str_ << std::endl;
        }
    }
};

void f() {
    std::string cur;
    try {
        if (std::cin >> cur) {
            f();
        } else throw 0;
    } catch (const RevExcept &e) {
        throw RevExcept(cur);
    } catch (int) {
        throw RevExcept();
    }
}

int main() {
    try {
        f();
    } catch (const RevExcept &e) {}
}