#include <iostream>

char c{};
bool alright = true;

void bad() {
    if (alright) {
        std::cout << "SAD on " << c << std::endl;
        alright = false;
    }
}
void S();
void P();

void S() {
    if (!alright) {
        return;
    }
    if (c == 'a') {
        std::cout << "S -> aSd\n";
        if (std::cin >> c) {
            S();
        }
    } else if (c == 'b') {
        std::cout << "S -> bPc\n";
        if (std::cin >> c) {
            P();
        }
    } else {
        bad();
    }
    if (c != 'd') {
        bad();
    }
}

void P() {
    if (!alright) {
        return;
    }
    if (c == 'b') {
        std::cout << "P -> bPc\n";
        if (std::cin >> c) {
            P();
        }
    } else {
        std::cout << "P -> eps\n";
    }
    if (c != 'c') {
        bad();
    }
    std::cin >> c;
}

int main() {
    std::cin >> c;
    S();
    if (alright) {
        std::cout << "Hurray!\n";
    }
}