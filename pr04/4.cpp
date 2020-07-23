#include <vector>
#include <iostream>
#include <iterator>
#include <algorithm>

template<typename IterNum, typename Iter>
auto myremove(IterNum beg, IterNum end, Iter first, Iter last) {
    std::vector v(beg, end);
    std::sort(v.begin(), v.end());
    v.erase(std::lower_bound(v.begin(), std::unique(v.begin(), v.end()), std::distance(first, last)), v.end());
    v.erase(v.begin(), std::lower_bound(v.begin(), v.end(), 0));
    if (v.size() == 0 || first == last) {
        return last;
    }
    auto reject = v.begin();
    auto slow = first;
    int fast_id = 0;
    for (auto fast = slow; fast != last; ++fast, ++fast_id) {
        if (reject == v.end() || fast_id != *reject) {
            std::swap(*slow, *fast);
            slow++;
        } else {
            reject++;
        }
    }
    return slow;
}