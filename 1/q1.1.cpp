#include <iostream>
#include <fstream>
#include <sstream>
#include <vector>
#include <cmath>


int main() {

    std::ifstream inputSS;
    inputSS.open("input.txt");

    std::vector<long> arr1;
    std::vector<long> arr2;

    std::string line;
    while (std::getline(inputSS, line)) {
        std::stringstream ss;
        ss << line;

        long l1 = 0;
        long l2 = 0;

        ss >> l1;
        ss >> l2;

        arr1.emplace_back(l1);
        arr2.emplace_back(l2);

    }

    std::sort(arr1.begin(), arr1.end());
    std::sort(arr2.begin(), arr2.end());

    long absDiff = 0;
    for (int i = 0; i < arr1.size(); ++i) {
        absDiff += abs(arr1[i] - arr2[i]);
    }

    std::cout << absDiff << std::endl;
}