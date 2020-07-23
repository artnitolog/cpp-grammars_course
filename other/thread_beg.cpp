#include <iostream>
#include <thread>

void thrfunc() {
    std::cout << "Thread " << 2 << std::endl;
}


// системные вызовы лайк экзит завершают все все к хренам
// или непойманное исключение

// принудительное завершение отдельной нити дерьмо
// так как ОС ничо не очистит за ней

int main() {
    std::thread t1;
    std::thread t2(thrfunc);
    std::cout << "Value " << 1 << std::endl;
    // t2.join();
    t2.detach(); // может завершиться - может нет - как пойдет
    // запустили - забыли
}