#include <iostream>
#include <thread>
#include <sstream>
#include <exception>

// чо с эксепшенами

std::exception_ptr epic_fail;

int func(int z) {
    if (z < 0) 
        // throw 100500;
        throw std::domain_error("lol");
    if (!z) return 42;
    int t = func(z - 10);
    return t + 2;
}


void thrfunc() {
    try {
        int x;
        std::cin >> x;
        func(x);
    } catch (...) {
        epic_fail = std::current_exception();
    }
}


int main() {
    try {
        std::thread t1;
        std::thread t2(thrfunc);
        std::cout << "Value " << 1 << std::endl;
        t2.join();
        if (epic_fail) { // кастится к булу
            std::rethrow_exception(epic_fail);
        } 
        std::cout << "Done\n";
    } catch (int out) {
        std::cout << "exception " << out << std::endl;
    } catch (const )
}