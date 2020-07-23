#include <vector>
#include <iterator>
#include <algorithm>

void process(const std::vector<int> &v1, std::vector<int> &v2) {
    std::vector<int> v(v1);
    std::sort(v.begin(), v.end());
    v.erase(std::unique(v.begin(), v.end()), v.end());
    auto first = v.begin();
    while (first != v.end() && *first < 0) {
        first++;
    }
    auto last = first;
    int size = v2.size();
    while (last != v.end() && *last < size) {
        last++;
    }
    if (first == last) {
        return;
    }
    auto left = first;
    auto right = first + 1;
    auto slow = v2.begin() + *first;
    while (right != last) {
        slow = std::copy(v2.begin() + *left + 1, v2.begin() + *right, slow);
        ++left;
        ++right;
    }
    slow = std::copy(v2.begin() + *left + 1, v2.end(), slow);
    v2.erase(slow, v2.end());
}