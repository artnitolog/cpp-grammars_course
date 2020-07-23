#include <iostream>
#include <string>
#include <cctype>
#include <algorithm>
#include <iterator>

enum class Align { non, both, left, right };

size_t rule_length(std::string str) {
    if (str == "_") {
        return 0;
    }
    return str.length();
}

int main() {
    bool noncontracting = true;
    bool s_to_eps = false, s_to_nt = false, to_s = false;
    bool automata = true;
    Align lin = Align::both;
    char from;
    std::string to;
    while(std::cin >> from >> to) {
        size_t len = rule_length(to);
        if (from == 'S') {
            s_to_eps = s_to_eps || len == 0;
            if (len == 1 && isupper(to.front())) {
                if (!s_to_nt) {
                    s_to_nt = true;
                } else {
                    automata = false;
                }
            }
        } else if (len == 0) {
            noncontracting = false;
        } else if (len == 1 && isupper(to.front())) {
            automata = false;
        }
        to_s = to_s || to.find('S') != std::string::npos;
        if (len > 1) {
            if (std::find_if(std::next(to.begin()), std::prev(to.end()),
                    [](char c) { return isupper(c); }) != std::prev(to.end())) {
                lin = Align::non;
            }
            bool first = isupper(to.front()), last = isupper(to.back());
            if ((first && last) || (first && lin == Align::right) 
                    || (last && lin == Align::left)) {
                lin = Align::non;
            }
            if (lin == Align::both) {
                if (first) {
                    lin = Align::left;
                } else if (last) {
                    lin = Align::right;
                }
            }
            if (len > 2 || (first == last)) {
                automata = false;
            }
        }
    }
    noncontracting = noncontracting && (!to_s || !s_to_eps);
    if (s_to_nt && !s_to_eps) {
        automata = false;
    }
    automata = automata && noncontracting;
    if (lin == Align::left || lin == Align::both) {
        if (automata) {
            std::cout << 311;
        } else {
            std::cout << 31;
        }
    } else if (lin == Align::right) {
        if (automata) {
            std::cout << 321;
        } else {
            std::cout << 32;
        }
    } else if (noncontracting) {
        std::cout << 21;
    } else {
        std::cout << 2;
    }
    std::cout << std::endl;
    return 0;
}
