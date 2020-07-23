#include <iostream>
#include <vector>
#include <cstdint>

void process(std::vector<uint64_t> &v, uint32_t s) {
    uint64_t cur_sum = 0;
    std::vector<uint64_t> new_vec{};
    for (size_t i = 0; i < v.size(); i++) {
        new_vec.push_back(v[i]);
        cur_sum += v[i];
        if (!((i + 1) % s)) {
            new_vec.push_back(cur_sum);
        }
    }
    v.swap(new_vec);
}
