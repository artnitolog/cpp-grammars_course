#include <iostream>
#include <string>
#include <vector>
#include <map>
#include <tuple>
#include <functional>

namespace numbers {
complex eval(const std::vector<std::string> &args, const complex &z) {
    complex_stack stack{};
    auto bin_extract = [](complex_stack &stack) { 
        complex z2 = +stack;
        stack = ~stack;
        complex z1 = +stack;
        stack = ~stack;
        return std::make_pair(z1, z2);
    };
    std::map <std::string, std::function<void()>> functors {
        {"z", [&stack, &z]() { 
            stack = stack << z; 
        } },
        {"+", [&stack, &z, &bin_extract]() {
            auto z = bin_extract(stack);
            stack = stack << z.first + z.second;
        } },
        {"-", [&stack, &z, &bin_extract]() {
            auto z = bin_extract(stack);
            stack = stack << z.first - z.second;
        } },
        {"*", [&stack, &z, &bin_extract]() {
            auto z = bin_extract(stack);
            stack = stack << z.first * z.second;
        } },
        {"/", [&stack, &z, &bin_extract]() {
            auto z = bin_extract(stack);
            stack = stack << z.first / z.second;
        } },
        {"!", [&stack]() { 
            stack = stack << +stack;
        } },
        {";", [&stack]() { 
            stack = ~stack;
        } },
        {"~", [&stack]() { 
            stack = ~stack << ~+stack;
        } },
        {"#", [&stack]() { 
            stack = ~stack << -+stack;
        } },
    };
    for (auto &cur : args) {
        if (functors.find(cur) != functors.end()) {
            functors[cur]();
        } else {
            stack = stack << complex(cur);
        }
    }
    return +stack;
}
}