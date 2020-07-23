#include <string>
#include <iostream>
#include <algorithm>

void turing(std::string::iterator beg, std::string::iterator end) {
    auto first = std::find_if_not(beg, end, [](auto &c) { return c == '#'; });
    if (first == end) {
        return;
    }
    auto last = std::find(first, end, '#');
    if (std::count(first, last, '1') & 1) {
        *std::find(first, last, '1') = '0';
    } else {
        turing(last, end);
    }
}

int main() {
    std::string s;
    std::cin >> s;
    turing(s.begin(), s.end());
    std::cout << s << std::endl;
}