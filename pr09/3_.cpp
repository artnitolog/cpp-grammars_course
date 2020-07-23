#include <iostream>
#include <string>
#include <algorithm>
#include <cctype>

enum class Align { non, both, left, right };

int main() {
    bool noncontracting = true;
    bool s_to_eps = false, s_to_nt = false, to_s = false;
    bool automata_rest = true;
    Align lin = Align::both;
    char from;
    std::string to;
    while (std::cin >> from >> to) {
        if (to.find('S') != std::string::npos) {
            to_s = true;
        }
        if (to == "_") {
            if (from == 'S') {
                s_to_eps = true;
            } else {
                noncontracting = false;
                break;
            }
        } else if (to.length() == 1) {
            if (isupper(to.front())) {
                if (from == 'S') {
                    s_to_nt = true;
                } else {
                    automata_rest = false;
                }
            }
        } else { // len >=2
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
            if (to.length() > 2 || (first == last)) {
                automata_rest = false;
            }
        }
    }
    if (s_to_eps && to_s) {
        noncontracting = false;
    }
    if (s_to_nt && !s_to_eps) {
        automata_rest = false;
    }
    
}