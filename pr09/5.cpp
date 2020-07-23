#include <iostream>
#include <map>
#include <set>
#include <vector>
#include <utility>
#include <cctype>
#include <algorithm>
#include <iterator>

class CFGrammar {
public:
    CFGrammar(std::vector<std::pair<char, std::string>> &&rules) : rules_(std::move(rules)) {
        for (auto &[from, to]: rules_) {
            std::copy_if(to.begin(), to.end(), 
                    std::inserter(nt_graph_[from], nt_graph_[from].end()), 
                    [](char c){ return isupper(c); });
        }
    }
    void print_reachable() {
        std::set<char> visited;
        dfs('S', visited);
        for (auto &[from, to]: rules_) {
            if (visited.find(from) != visited.end()) {
                std::cout << from << " " << to << std::endl;
            }
        }
    }
private:
    std::vector<std::pair<char, std::string>> rules_{};
    std::map<char, std::set<char>> nt_graph_{}; // not a sym-graph, bc without terminals
    void dfs(char cur, std::set<char> &visited) {
        visited.insert(cur);
        for (auto now : nt_graph_[cur]) {
            if (visited.find(now) == visited.end()) {
                dfs(now, visited);
            }
        }
    }
};

int main() {
    char from;
    std::string to;
    std::vector<std::pair<char, std::string>> rules;
    while (std::cin >> from >> to) {
        rules.push_back({from, to});
    }
    CFGrammar grammar(std::move(rules));
    grammar.print_reachable();
    return 0;
}