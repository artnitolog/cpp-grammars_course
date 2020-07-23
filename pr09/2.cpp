#include <iostream>
#include <map>
#include <set>
#include <string>
#include <utility>

bool is_accepted(std::string &str) {
    enum class St { A, AB, AC, AS, ABC, ABS, ACS, ABCS };
    static std::map<std::pair<St, char>, St> transitions{
        {{St::A, '0'}, St::A}, {{St::A, '1'}, St::AB},
        {{St::AB, '0'}, St::AC}, {{St::AB, '1'}, St::ABC}, 
        {{St::AC, '0'}, St::AS}, {{St::AC, '1'}, St::ABS}, 
        {{St::AS, '0'}, St::A}, {{St::AS, '1'}, St::AB}, 
        {{St::ABC, '0'}, St::ACS}, {{St::ABC, '1'}, St::ABCS}, 
        {{St::ABS, '0'}, St::AC}, {{St::ABS, '1'}, St::ABC}, 
        {{St::ACS, '0'}, St::AS}, {{St::ACS, '1'}, St::ABS}, 
        {{St::ABCS, '0'}, St::ACS}, {{St::ABCS, '1'}, St::ABCS},
    };
    static std::set<St> accept_states{ St::AS, St::ABS, St::ACS, St::ABCS };
    St cur_state = St::A;
    for (auto now : str) {
        auto next = transitions.find({cur_state, now});
        if (next == transitions.end()) {
            return false;
        }
        cur_state = next->second;
    }
    return accept_states.find(cur_state) != accept_states.end();
}

int main() {
    std::string str;
    while (std::cin >> str) {
        std::cout << is_accepted(str) << std::endl;
    }
    return 0;
}