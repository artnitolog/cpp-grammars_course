#include <iostream>
#include <string>

int main() {
    std::string left, right;
    bool start = false, right_start = false, start_eps = false;
    bool context_free = true, noncontracting = true;
    while (std::cin >> left >> right) {
        bool nonterminal = false;
        for (auto now : left) {
            if (now >= 'A' && now <= 'Z') {
                nonterminal = true;
                break;
            }
        }
        if (!nonterminal) {
            std::cout << -1 << std::endl;
            return 0;
        }
        start = start || left == "S";
        context_free = context_free && left.length() == 1;
        right_start = right_start || right.find('S') != std::string::npos;
        start_eps = start_eps || (right == "_" && left == "S");
        noncontracting = noncontracting && context_free && (!start_eps || !right_start) && 
                ((left.length() <= right.length() && right != "_") || left == "S");
    }
    if (!start) {
        std::cout << -1;
    } else if (noncontracting) {
        std::cout << 23;
    } else if (context_free) {
        std::cout << 2;
    } else {
        std::cout << 10;
    }
    std::cout << std::endl;
    return 0;
}