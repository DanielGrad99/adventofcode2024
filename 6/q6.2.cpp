#include <cmath>
#include <fstream>
#include <iostream>
#include <sstream>
#include <unordered_map>
#include <unordered_set>
#include <vector>
#include <algorithm>

struct Pair {
public:
    int i;
    int j;

    Pair();
    Pair(int i, int j) : i(i), j(j) {}

    inline std::size_t const hash() const {return i * 10000 + j;}
};

inline bool operator==(const Pair& lhs, const Pair& rhs) { return lhs.i == rhs.i && lhs.j == rhs.j; }
inline bool operator!=(const Pair& lhs, const Pair& rhs) { return !(lhs == rhs); }

template <>
struct std::hash<Pair>
{
  std::size_t operator()(const Pair& k) const
  {
    using std::size_t;
    using std::hash;
    using std::string;

    // Compute individual hash values for first,
    // second and third and combine them using XOR
    // and bit shifting:

    return k.hash();
  }
};


void print(const std::vector<std::vector<char>>& m) {
    for (const auto& r : m) {
        for (const auto& c : r) {
            std::cout << c;
        }

        std::cout << std::endl;
    }
}

bool is_player(char c) { return c == '<' || c == '^' || c == '>' || c == 'V'; }

char rotate_player(char c) {
    if (c == '^') {
        return '>';
    } else if (c == '>') {
        return 'V';
    } else if (c == 'V') {
        return '<';
    } else if (c == '<') {
        return '^';
    }

    std::cerr << "rotate_player: WE SHOULD NOT BE HERE" << std::endl;
    exit(1);
}

enum State {Inside, Outside, Loop};

State move(std::vector<std::vector<char>>& map, std::unordered_map<Pair, std::unordered_set<char>>& rotated_on) {
    int locI = -1;
    int locJ = -1;

    for (int i = 0; i < map.size(); ++i) {
        for (int j = 0; j < map[j].size(); ++j) {
            if (is_player(map[i][j])) {
                locI = i;
                locJ = j;
            }
        }
    }

    if (locI == -1 || locJ == -1) {
        std::cerr << "SOMETHING WENT WRONG" << std::endl;
        print(map);
        exit(1);
    }

    int i = locI;
    int j = locJ;

fast_track:
    char c = map[locI][locJ];
    if (c == '^') {
        --locI;
    } else if (c == 'V') {
        ++locI;
    } else if (c == '<') {
        --locJ;
    } else if (c == '>') {
        ++locJ;
    } else {
        std::cerr << "WE SHOULD NOT BE HERE" << std::endl;
        exit(1);
    }

    if (locI < 0 || locI >= map.size() || locJ < 0 || locJ >= map[locI].size()) {
        map[i][j] = 'X';
        return Outside;
    }

    if (map[locI][locJ] == '#') {
        Pair p = {locI, locJ};
        if (rotated_on.contains(p) && rotated_on[p].contains(map[i][j])) {
            return Loop;
        }

        rotated_on[p].insert(map[i][j]);

        map[i][j] = rotate_player(map[i][j]);
        locI = i;
        locJ = j;
        goto fast_track;
    } else {
        map[locI][locJ] = map[i][j];
        map[i][j] = 'X';
    }

    return Inside;
}

int main() {
    std::ifstream inputSS;
    inputSS.open("input.txt");

    std::vector<std::vector<char>> map;

    std::string line;
    while (std::getline(inputSS, line)) {
        if (line == "") {
            break;
        }

        map.emplace_back(std::vector<char>());
        for (const auto& c : line) {
            map.back().emplace_back(c);
        }
    }

    const std::vector<std::vector<char>> original_map = map;

    std::unordered_map<Pair, std::unordered_set<char>> rotated_on;
    while (move(map, rotated_on) == Inside);

    const std::vector<std::vector<char>> moved_map = map;
    print(moved_map);

    int count = 0;
    for (int i = 0; i < moved_map.size(); ++i) {
        for (int j = 0; j < moved_map[i].size(); ++j) {
            if (moved_map[i][j] != 'X' || is_player(original_map[i][j])) {
                continue;
            }

            map = original_map;
            map[i][j] = '#';

            std::unordered_map<Pair, std::unordered_set<char>> rotated_on;

            State result;
            do {
                result = move(map, rotated_on);
            } while(result == Inside);

            if (result == Loop) {
                ++count;

                std::cout << "New count: " << count << std::endl;
                // print(map);
                // std::cout << std::endl << std::endl << std::endl;
                // map = original_map;
                // map[i][j] = '#';
                // print(map);
            }
        }
    }



    std::cout << std::endl << std::endl << std::endl;
    print(map);



    std::cout << count << std::endl;
}
