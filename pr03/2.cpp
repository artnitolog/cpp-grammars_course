#include <vector>
#include <cstdint>

void process(std::vector<int64_t> &v, int64_t threshold) {
    size_t new_size = v.size();
    for (auto now : v) {
        new_size += now >= threshold;
    }
    v.reserve(new_size);
    for (auto it = v.rbegin(); it != v.rend(); it++) {
        if (*it >= threshold) {
            v.push_back(*it);
        }
    }
}