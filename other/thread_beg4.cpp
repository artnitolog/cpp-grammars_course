#include <iostream>
#include <thread>
#include <sstream>
#include <iostream>
#include <chrono>
#include <thread>

struct A {
    A() {std::cout << "A()\n"; }
    ~A() {std::cout << "~A()\n"; }
    // A(A &&) {std::cout << "A(A &&)\n"; }
    A(const A &) {std::cout << "A(const A &)\n"; }
};

void thrfunc(int value, const A& a) {
    std::ostringstream ss;
    std::this_thread::sleep_for(2s);
    ss << "Thread" << 2 << std::endl;
    std::cout << ss.str();
    A aa(a);
}

void thr2() {
    A a;
    std::thread t2(thrfunc, 10, std::cref(a));
    t2.detach();
}

int main() {
    std::thread t1;
    std::thread t2(thr2);
    std::cout << "value" << 1 << std::endl;
    t2.join();
    std::cout << "Done\n";
}