#include <cmath>
#include <fstream>
#include <iostream>
#include <sstream>
#include <vector>

int main() {
    std::ifstream inputSS;
    inputSS.open("input.txt");

    std::vector<long> arr1;

    int numSafe = 0;

    std::string line;
    while (std::getline(inputSS, line)) {
        std::stringstream ss;
        ss << line;

        int val = 0;
        int lastVal = 0;

        bool safe = true;

        ss >> lastVal;
        int lastlastVal = lastVal;

        while (ss >> val) {
            if (val == lastVal) {
                safe = false;
                break;
            }

            if (abs(val - lastVal) > 3) {
                safe = false;
                break;
            }

            if (lastVal <= val && lastlastVal <= lastVal) {
            } else if (lastVal >= val && lastlastVal >= lastVal) {
            } else {
                safe = false;
                break;
            }

            lastlastVal = lastVal;
            lastVal = val;
        }

        if (safe) {
            numSafe += 1;
        }
    }

    std::cout << numSafe << std::endl;
}