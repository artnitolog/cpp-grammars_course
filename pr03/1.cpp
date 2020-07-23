#include <vector>
#include <cstdint>
#include <iterator>

void process(const std::vector<uint64_t> &v1, std::vector<uint64_t> &v2, int step) {
    auto it1 = v1.begin();
    auto it2 = v2.rbegin();
    while (it1 != v1.end() && it2 != v2.rend()) {
        *it2 += *it1;
        if (std::distance(it1, v1.end()) <= step) {
            break;
        }
        it1 += step;
        ++it2;
    }
}