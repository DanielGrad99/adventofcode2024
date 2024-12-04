#include <cmath>
#include <fstream>
#include <iostream>
#include <sstream>
#include <vector>

int numXmas(const std::vector<std::vector<char>>& map, const int i, const int j) {
    if (map[i][j] != 'X') {
        return 0;
    }

    std::string XMAS = "XMAS";

    const std::vector<int> directionI = {1, 1, 1, 0, 0, 0, -1, -1, -1};
    const std::vector<int> directionJ = {1, 0, -1, 1, 0, -1, 1, 0, -1};

    int count = 0;

    for (int d = 0; d < directionI.size(); ++d) {
        int ii = i;
        int jj = j;

        bool valid = true;

        for (int a = 0; a < XMAS.length(); ++a) {
            if (ii < 0 || ii >= map.size() || jj < 0 || jj >= map[ii].size()) {
                valid = false;
                break;
            }

            if (map[ii][jj] != XMAS[a]) {
                valid = false;
                break;
            }

            ii += directionI[d];
            jj += directionJ[d];
        }

        if (valid) {
            // std::cout << i << "," << j << std::endl;
            ++count;
        }
    }

    return count;
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