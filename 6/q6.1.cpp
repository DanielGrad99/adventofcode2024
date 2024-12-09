#include <cmath>
#include <fstream>
#include <iostream>
#include <sstream>
#include <unordered_map>
#include <unordered_set>
#include <vector>

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

bool move(std::vector<std::vector<char>>& map) {
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
        return false;
    }

    if (map[locI][locJ] == '#') {
        map[i][j] = rotate_player(map[i][j]);
        locI = i;
        locJ = j;
        goto fast_track;
    } else {
        map[locI][locJ] = map[i][j];
        map[i][j] = 'X';
    }

    return true;
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

    print(map);

    while (move(map));

    std::cout << std::endl << std::endl << std::endl;
    print(map);

    int sum = 0;
    for (const auto& r : map) {
        for (const auto& c : r) {
            if (c == 'X') {
                ++sum;
            }
        }
    }

    std::cout << sum << std::endl;
}
