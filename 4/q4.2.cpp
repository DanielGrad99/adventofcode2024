#include <cmath>
#include <fstream>
#include <iostream>
#include <sstream>
#include <vector>

int numXmas(const std::vector<std::vector<char>>& map, const int i, const int j) {
    if (map[i][j] != 'A') {
        return 0;
    }

    const std::vector<int> directionI = {1, 1, -1, -1};
    const std::vector<int> directionJ = {1, -1, 1, -1};

    int numM = 0;
    int numS = 0;

    for (int d = 0; d < directionI.size(); ++d) {
        int ii = i + directionI[d];
        int jj = j + directionJ[d];

        if (ii < 0 || ii >= map.size() || jj < 0 || jj >= map[ii].size()) {
            return 0;
        }

        int ii_d = i - directionI[d];
        int jj_d = j - directionJ[d];

        if (ii_d < 0 || ii_d >= map.size() || jj_d < 0 || jj_d >= map[ii_d].size()) {
            return 0;
        }

        if (map[ii][jj] == 'M') {
            ++numM;

            if (map[ii_d][jj_d] == 'M') {
                return 0;
            }
        }

        if (map[ii][jj] == 'S') {
            ++numS;

            if (map[ii_d][jj_d] == 'S') {
                return 0;
            }
        }

        if (numM == 2 && numS == 2) return 1;
    }

    return 0;
}

int main() {
    std::ifstream inputSS;
    inputSS.open("input.txt");

    std::vector<std::vector<char>> map;

    std::string line;
    while (std::getline(inputSS, line)) {
        std::vector<char> row;
        for (const auto c : line) {
            row.emplace_back(c);
            // std::cout << c;
        }

        // std::cout << std::endl;

        map.emplace_back(row);
    }

    int total = 0;
    for (int i = 0; i < map.size(); ++i) {
        for (int j = 0; j < map[i].size(); ++j) {
            total += numXmas(map, i, j);
        }
    }

    std::cout << total << std::endl;
}