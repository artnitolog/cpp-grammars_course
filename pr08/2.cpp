#include <iostream>
#include <cctype>

void reject(char last) {
    if (!std::isspace(last)) {
        while (std::cin >> std::noskipws >> last && !isspace(last));
    }
    std::cout << 0 << std::endl;
}

void check() {
    int cnt0 = 0, cnt1 = 0;
    char c;
    while (std::cin >> std::noskipws >> c && c == '0') {
        ++cnt0;
    }
    if (c != '1') {
        reject(c);
        return;
    }
    while (std::cin >> c && c == '1') {
        ++cnt1;
    }
    while (c == '0') {
        int cnt = 0;
        while (std::cin >> c && c == '0') {
            ++cnt;
        }
        if (c != '1' || cnt != cnt0) {
            reject(c);
            return;
        }
        cnt = 0;
        while (std::cin >> c && c == '1') {
            ++cnt;
        }
        if (cnt != cnt1) {
            reject(c);
            return;
        }
    }
    if (std::cin.eof() || std::isspace(c)) {
        std::cout << 1 << std::endl;
    } else {
        reject(c);
    }
}

int main() {
    char first;
    while (std::cin >> std::skipws >> first) {
        if (first == '0') {
            check();
        } else {
            reject(first);
        }
    }
    return 0;
}