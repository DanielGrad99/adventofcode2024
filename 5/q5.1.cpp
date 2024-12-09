#include <cmath>
#include <fstream>
#include <iostream>
#include <sstream>
#include <unordered_map>
#include <unordered_set>
#include <vector>

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
        // std::cout << line << std::endl;

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
            sum += row[row.size() / 2];
        }
    }

    std::cout << sum << std::endl;
}