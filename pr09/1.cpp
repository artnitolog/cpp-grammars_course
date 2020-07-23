/*
Language: {a^n 0^m b^n 1^m}; where n, m > 0.
Type-1 language, possible non-contracting grammar:
    S = aXP | aXQ | aXPQ
    P = YX | YXP
    Q = UV | UVQ
    aY = aa
    aU = a0
    0U = 00
    0X = 0b
    bX = bb
    bV = b1
    1V = 11
    XY = YX
    XU = UX
*/

#include <iostream>
#include <string>
#include <algorithm>

bool check(std::string &str) {
    auto next = std::find_if(str.begin(), str.end(), [](char c) { return c != 'a'; });
    int n = std::distance(str.begin(), next);
    if (n < 1 || next != std::find(str.begin(), str.end(), '0')) {
        return 0;
    }
    auto prev = next;
    next = std::find_if(prev, str.end(), [](char c) { return c != '0'; });
    int m = std::distance(prev, next);
    if (m < 1 || next != std::find(prev, str.end(), 'b')) {
        return 0;
    }
    prev = next;
    next = std::find_if(prev, str.end(), [](char c) { return c != 'b'; });
    if (std::distance(prev, next) != n || next != std::find(prev, str.end(), '1')) {
        return 0;
    }
    prev = next;
    next = std::find_if(prev, str.end(), [](char c) { return c != '1'; });
    if (std::distance(prev, next) != m || next != str.end()) {
        return 0;
    }
    return 1;
}

int main() {
    std::string str;
    while (std::cin >> str) {
        std::cout << check(str) << std::endl;
    }
}