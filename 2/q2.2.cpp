#include <cmath>
#include <fstream>
#include <iostream>
#include <sstream>
#include <vector>

bool isSafe(std::vector<int>& row) {

    for (int i = 2; i < row.size(); ++i) {
        if (row[i - 2] < row[i - 1] && row[i - 1] < row[i]) {

        } else if (row[i - 2] > row[i - 1] && row[i - 1] > row[i]) {

        } else {
            return false;
        }

        if (abs(row[i - 2] - row[i - 1]) > 3) {
            return false;
        }

        if (abs(row[i - 1] - row[i]) > 3) {
            return false;
        }
    }

    return true;
}

bool isSafeRemove(std::vector<int> row) {
    if (isSafe(row)) {
        return true;
    }

    for (int i = 0; i < row.size(); ++i) {
        auto r = row;

        r.erase(r.begin() + i);

        if (isSafe(r)) {
            return true;
        }
    }

    return false;
}

int main() {
    std::ifstream inputSS;
    inputSS.open("input.txt");

    std::vector<long> arr1;

    int numSafe = 0;

    std::string line;
    while (std::getline(inputSS, line)) {
        std::stringstream ss;
        ss << line;

        std::vector<int> row;
        int val = 0;

        while (ss >> val) {
            row.emplace_back(val);
        }

        if (isSafeRemove(row)) {
            ++numSafe;
        }
        
        std::cout << line << " : " << numSafe << std::endl;
    }

    std::cout << numSafe << std::endl;
}