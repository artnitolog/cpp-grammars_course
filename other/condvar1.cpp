#include <iostream>
#include <vector>
#include <mutex>
#include <thread>
#include <condition_variable> // второе средство - для уведомлений (мьютексы для блока)
#include <atomic>

// volatile int value; // если мы юзаем волатайл в многонитевой хрени, то мы дерьмо
// с мьютексами он не нужен - они уже барьер, компилятор поймет после их использования
int value;
std::mutex m;
std::condition_variable c;

bool consumed;
std::mutex mc;
std::condition_variable cc;

std::atomic<bool> done = false;

void func() {
    for (int i = 1; i < 100; ++i) {
        if (i % 5 == 0) {
            {
                std::lock_guard l{m};
                value = i;
                c.notify_one();
            }
            {
                std::unique_lock ll{mc};
                cc.wait(ll, [](){return  consumed;});
                consumed = false;
            }
        }
    }
    done = true;
    c.notify_one();
}

int main() {
    std::thread t(func);
    while (!done) {
        int local;
        {
            std::unique_lock l{m};
            /*
            while (!value) {
                c.wait(l); // разлочили временно для другой нити!
            }
            */
            c.wait(l, [](){return bool(value) || done;});
            if (done) break;
            local = value;
            value = 0;
        }
        std::cout << local << std::endl;
        {
            std::lock_guard ll{mc};
            consumed = true;
            cc.notify_one();
        }
    }
    t.join();
}