#include <cmath>
#include <fstream>
#include <iostream>
#include <sstream>
#include <unordered_map>
#include <unordered_set>
#include <vector>

void print(const std::vector<int>& v) {
    for (int i = 0; i < v.size(); ++i) {
        std::cout << v[i];

        if (i + 1 != v.size()) {
            std::cout << ",";
        }
    }

    std::cout << std::endl;
}

int main() {
    std::ifstream inputSS;
    inputSS.open("input.txt");

    std::unordered_map<int, std::unordered_set<int>> orders;

    std::string line;
    while (std::getline(inputSS, line)) {
        if (line == "") {
            break;
        }

        std::stringstream ss;
        ss << line;

        int num1 = 0;
        int num2 = 0;
        char c;

        ss >> num1 >> c >> num2;

        if (c != '|') {
            std::cerr << "ERROR: C != |" << std::endl << line << std::endl;
            return 1;
        }

        orders[num1].insert(num2);
    }

    int sum;

    while (std::getline(inputSS, line)) {
        std::stringstream ss;
        ss << line;

        std::vector<int> row;

        int num;
        char c;
        while (ss >> num) {
            row.emplace_back(num);
            if (!(ss >> c)) {
                break;
            }
        }

        bool validSet = true;

        std::unordered_set<int> seen_ints;
        for (const auto& i : row) {
            if (orders.contains(i)) {
                for (const auto& b : orders[i]) {
                    if (seen_ints.contains(b)) {
                        validSet = false;
                        break;
                    }
                }
            }

            if (!validSet) {
                break;
            }

            seen_ints.insert(i);
        }

        if (validSet) {
            continue;
        }

        // std::cout << line << std::endl;
        // print(row);

        int idx = 0;
        while (idx < row.size()) {
            if (orders.contains(row[idx])) {
                for (const auto& b : orders[row[idx]]) {
                    for (int j = 0; j < idx; ++j) {
                        if (row[j] == b) {
                            
                            int num = row[idx];
                            row[idx] = row[j];
                            row[j] = num;

                            idx = j - 1;
                            goto qe;
                        }
                    }
                }
            }

qe:
            ++idx;
        }

        // print(row);

        sum += row[row.size() / 2];

    }

    std::cout << sum << std::endl;
}