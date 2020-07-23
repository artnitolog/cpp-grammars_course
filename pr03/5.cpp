#include <vector>
#include <string>
#include <iostream>
#include <sstream>
#include <cinttypes>
#include <algorithm>

class Surface {
public:
    Surface(uint32_t height=0) : height_{height} {}
    const Surface &operator-=(uint32_t corrective) {
        height_ = height_ > corrective ? height_ - corrective : 0;
        return *this;
    }
    friend std::ostream &operator<<(std::ostream &out, const Surface &obj) {
        return out << obj.height_;
    }
    friend std::istream &operator>>(std::istream &in, Surface &obj) {
        return in >> obj.height_;
    }
    friend bool operator<(const Surface &obj1, const Surface &obj2) {
        return obj1.height_ < obj2.height_;
    }
private:
    uint32_t height_{};
};

std::ostream &operator<<(std::ostream &out, const std::vector<std::vector<Surface>> &obj) {
    for (auto &row : obj) {
        out << row.front();
        for (auto cur = row.begin() + 1; cur != row.end(); ++cur) {
            out << " " << *cur;
        }
        out << std::endl;
    }
    return out;
}

std::istream &operator>>(std::istream &in, std::vector<std::vector<Surface>> &obj) {
    std::string line;
    while (std::getline(in, line), line.length() > 0) {
        std::istringstream stream(line);
        obj.push_back({});
        auto row = obj.rbegin();
        int tmp;
        while (stream >> tmp) {
            row->push_back(tmp);
        }
    }
    return in;
}

std::istream &operator>>(std::istream &in, std::vector<uint32_t> &obj) {
    std::string line;
    std::getline(in, line);
    std::istringstream stream(line);
    uint32_t cur;
    while (stream >> cur) {
        obj.push_back(cur);
    }
    std::sort(obj.rbegin(), obj.rend());
    return in;
}

void fix_row(std::vector<Surface> &row, size_t pos, uint32_t official) {
    auto now = row.begin();
    if (pos > 0) {
        if (row.size() >= pos) {
            std::advance(now, pos - 1);
            *now -= official / 2;
            std::advance(now, 1);
        } else {
            return;
        }
    }
    if (now != row.end()) {
        *now -= official;
        std::advance(now, 1);
    }
    if (now != row.end()) {
        *now -= official / 2;
    }
}

void fix(std::vector<std::vector<Surface>> &obj, uint32_t official) {
    auto max_row = obj.begin();
    auto max = obj[0].begin();
    for (auto row = obj.begin(); row != obj.end(); row++) {
        auto cur = std::max_element(row->begin(), row->end());
        if (*max < *cur) {
            max = cur;
            max_row = row;
        }
    }
    size_t pos = std::distance(max_row->begin(), max);
    fix_row(*max_row, pos, official);
    if (max_row != obj.begin()) {
        fix_row(*std::prev(max_row), pos, official / 2);
    }
    if (std::distance(max_row, obj.end()) > 1) {
        fix_row(*std::next(max_row), pos, official / 2);
    }
}

int main() {
    std::vector<std::vector<Surface>> K___ya;
    std::vector<uint32_t> correctives;
    std::cin >> K___ya >> correctives;
    for (auto now : correctives) {
        fix(K___ya, now);
    }
    std::cout << K___ya;
}