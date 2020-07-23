#include <iostream>
#include <map>
#include <set>
#include <string>
#include <utility>

bool is_accepted(std::string &str) {
    enum class St { A, B, S, F, BC, FS };
    static std::map<std::pair<St, char>, St> transitions{
        {{St::S, 'a'}, St::A}, {{St::S, 'b'}, St::B},
        {{St::A, 'a'}, St::S}, {{St::A, 'b'}, St::F},
        {{St::A, 'c'}, St::BC},
        {{St::BC, 'a'}, St::FS},
        {{St::BC, 'b'}, St::FS},
        {{St::B, 'a'}, St::S},
    };
    static std::set<St> accept_states{ St::F, St::FS };
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