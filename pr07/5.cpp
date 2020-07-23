#include <boost/date_time/gregorian/gregorian.hpp>
#include <iostream>

int main() {
    int y, m, d;
    char delim;
    std::cin >> y >> delim >> m >> delim >> d;
    boost::gregorian::date prev(y, m, d);
    unsigned cnt = 0;
    while (std::cin >> y >> delim >> m >> delim >> d) {
        boost::gregorian::date cur(y, m, d);
        cnt += std::abs((prev - cur).days());
        prev = cur;
    }
    std::cout << cnt << std::endl;
}