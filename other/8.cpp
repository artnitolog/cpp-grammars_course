#include <iostream>
#include <string>

std::string gen_power(uint32_t power) {
    if (power == 0) {
        return "1";
    } else if (power == 1) {
        return "x";
    } else {
        return std::string(power, 'x') + std::string(power - 1, '*');
    }
}