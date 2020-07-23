#include <thread>
#include <future>
#include <mutex>
#include <iostream>
#include <exception>
#include <unistd.h>
#include <chrono>

void g(std::promise<int> &p) {
    std::cout << "g thread: " << std::this_thread::get_id() << std::endl;
    p.set_value(487);
}


int h(int a) {
    std::this_thread::sleep_for(std::chrono::seconds(1));
    std::cout << "h thread: " << std::this_thread::get_id() << std::endl;
    return 42 + a;
}

int main() {
    std::promise<int> p;
    std::thread thr(g, std::ref(p));
    std::future<int> f = p.get_future();
    std::cout << f.get() << std::endl;
    thr.join();

    std::future<int> f1 = std::async(std::launch::async, h, 10);
    std::cout << "main: " << std::this_thread::get_id() << std::endl;
    // std::future<int> f1 = std::async(std::launch::deferred, h, 10);
    std::cout << f1.get() << std::endl;
    
    // 3 сущности
    std::packaged_task<int(int)> pt([](int a ){ return a + 1; }); // 1) где что хотим вычислить
    auto f2 = pt.get_future();
    pt(24); // 2) где вычисляем
    std::cout << f2.get() << std::endl; // 3) где получаем результат этого вычисления
}