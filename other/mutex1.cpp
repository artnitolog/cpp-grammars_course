#include <thread>
#include <mutex>
#include <vector>
#include <iostream>

// volatile long long v1 = 0;
// volatile long long v2 = 0;
long long v1, v2 = 0; // несколько нитей => НЕ НАДО ВОЛАТАЙЛ ЕСТЬ МЬЮТЕКС

std::mutex m, m2;


int main() {
    std::vector<std::thread> thrs;
    for (int i = 0; i < 10; i++) {
        thrs.emplace_back([](int i) {
            for (int j = 0; j < 100000; ++j) {
                // std::lock_guard lock{m};
                // std::unique_lock lock{m}; // семантика владения, можно передавать внутрь кому-то
                // std::shared_lock lock{m};
                // std::scoped_lock lock{m, m2}; // умеет захватывать несколько мьютексов одновременно
                std::lock_guard l1{m}, l2{m2}; // обедающие философы -> дедлок из-за порядка
                v1 += i;
                v2 -= i;
            }
        }, i);
    }
    for (auto &t : thrs) {
        t.join();
    }
    std::cout << v1 << " " << v2 << std::endl;
}