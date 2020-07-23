#include <iostream>
#include <string>

bool check(std::string &str) {
    auto it = str.begin();
    for (; it != str.end() && (*it == '3' || *it == '4'); it++);
    if (it == str.end()) {
        return true;
    }
    for (; it != str.end() && (*it == '1' || *it == '2'); it++);
    if (it == str.end()) {
        return true;
    }
    return false;
}

int main() {
    std::string cur;
    while (std::cin >> cur) {
        std::cout << check(cur) << std::endl;
    }
    return 0;
}