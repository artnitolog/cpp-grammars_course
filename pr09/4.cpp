/* The following grammar:
    S -> aA
    A -> aAd | bBcd
    B -> bBc | ε
generates {a^n b^m c^m d^n | m, n > 0}
and allows recursive descent.
*/

#include <iostream>

void fori(int, int);
void ad(int, int);
void bc(int);

void fori(int k, int i) {
    if (i < k) {
        ad(k, i);
        std::cout << std::endl;
        fori(k, i + 1);
    } 
}

void ad(int k, int m) {
    if (k != m) {
        std::cout << 'a';
        ad(k - 1, m);
        std::cout << 'd';
    } else {
        bc(m);
    }
}

void bc(int m) {
    std::cout << 'b';
    if (m > 1) {
        bc(m - 1);
    }
    std::cout << 'c';
}

int main() {
    int k;
    std::cin >> k;
    if (k % 2 == 0) {
        fori(k / 2, 1);
    }
    return 0;
}