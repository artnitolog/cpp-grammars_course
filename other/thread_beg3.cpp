#include <iostream>
#include <thread>
#include <sstream>
#include <exception>

struct A {
    A() {std::cout << "A()\n"; }
    ~A() {std::cout << "~A()\n"; }
    // A(A &&) {std::cout << "A(A &&)\n"; }
    A(const A &) {std::cout << "A(const A &)\n"; }
};

void thrfunc(int value, const A& a) {
    std::ostringstream ss;
    ss << "Thread" << 2 << std::endl;
    std::cout << ss.str();
}


int main() {
    std::thread t1;
    A a;
    std::thread t2(thrfunc, 10, std::cref(a));
    std::cout << "value" << 1 << std::endl;
    t2.join();
    std::cout << "Done\n";
}