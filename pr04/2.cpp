template<typename T, typename PT>
auto myfilter(const T &stl, PT pred) {
    T new_stl{};
    for (auto now : stl) {
        if (pred(now)) {
            new_stl.insert(new_stl.end(), now);
        }
    }
    return new_stl;
}