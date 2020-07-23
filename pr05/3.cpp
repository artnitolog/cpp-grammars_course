#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <map>
#include <functional>
#include <memory>
#include <sstream>

class Factory {
public:
    static Factory &factory_instance() {
        static Factory instance;
        return instance;
    }
    std::unique_ptr<Figure> creator(const std::string &str) const {
        std::istringstream iss(str);
        char key;
        std::string params;
        iss >> key >> std::ws;
        std::getline(iss, params);
        static std::map <char, std::function<Figure *(std::string)>> maker {
            {'R', Rectangle::make},
            {'S', Square::make},
            {'C', Circle::make}
        };
        return std::unique_ptr<Figure>(maker[key](params));
    }
private:        
    Factory() {}
};

int main() {
    std::vector<std::unique_ptr<Figure>> v;
    std::string cur;
    Factory tyler = Factory::factory_instance();
    while (std::getline(std::cin, cur)) {
        v.emplace_back(tyler.creator(cur));
    }
    std::stable_sort(v.begin(), v.end(), 
        [](const std::unique_ptr<Figure> &p1, const std::unique_ptr<Figure> &p2)
                { return p1->get_square() < p2->get_square(); });
    for (auto &now : v) {
        std::cout << now->to_string() << std::endl;
    }
}