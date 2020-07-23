#include <iostream>
#include <map>
#include <set>
#include <string>
#include <vector>

class DFA {
public:
    explicit DFA() { read(); }
    void test() const {
        St cur_state = init_state;
        char cur_symbol;
        bool is_accepted = true;
        unsigned long long cnt = 0;
        while (std::cin >> cur_symbol) {
            auto next = transitions.find({cur_state, cur_symbol});
            if (next == transitions.end()) {
                is_accepted = false;
                break;
            }
            cnt++;
            cur_state = next->second;
        }
        if (accept_states.find(cur_state) == accept_states.end()) {
            is_accepted = false;
        }
        std::cout << is_accepted << std::endl << cnt << std::endl << cur_state << std::endl;
    }
private:
    typedef std::string St;
    std::map<std::pair<St, char>, St> transitions{};
    St init_state{};
    std::set<St> accept_states{};
    void read() {
        St from_state, to_state;
        char symbol;
        std::cin >> from_state;
        while (from_state != "END") {
            std::cin >> symbol >> to_state;
            transitions.insert({{from_state, symbol}, to_state});
            std::cin >> from_state;
        }
        St accept_state;
        while (std::cin >> accept_state && accept_state != "END") {
            accept_states.insert(accept_state);
        }
        std::cin >> init_state;
    }
};

int main() {
    DFA dfa = DFA();
    dfa.test();
    return 0;
}