#include <iterator>
#include <functional>
#include <vector>

template<typename Iter, typename F>
void myapply(Iter first, Iter last, F f) {
    for (auto it = first; it != last; ++it) {
        f(*it);
    }
}

template<typename Iter, typename Pred>
auto myfilter2(Iter first, Iter last, Pred pred) {
    std::vector<std::reference_wrapper<typename std::iterator_traits<Iter>::value_type>> tmp{};
    for (auto it = first; it != last; ++it) {
        if (pred(*it)) {
            tmp.push_back(*it);
        }
    }
    return tmp;
}