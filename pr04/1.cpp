#include <vector>
#include <iostream>

template<typename T>
auto process(const T &stl)// -> typename T::value_type
{
    typename T::value_type sum{};
    int cnt = 1;
    for (auto cur = stl.rbegin(); cur != stl.rend() && cnt <= 5; ++cnt, ++cur) {
        if (cnt % 2) {
            sum += *cur;
        }
    }
    return sum;
}

// int main() {
//     std::vector<int> a{1,2,3,4,5,6,7};
//     std::cout << process(a);
// }
