#include <iostream>
#include <fstream>
#include <sstream>
#include <vector>
#include <unordered_map>
#include <cmath>


int main() {

    std::ifstream inputSS;
    inputSS.open("input.txt");

    std::vector<long> arr1;
    std::unordered_map<long, long> m;

    std::string line;
    while (std::getline(inputSS, line)) {
        std::stringstream ss;
        ss << line;

        long l1 = 0;
        long l2 = 0;

        ss >> l1;
        ss >> l2;

        arr1.emplace_back(l1);
        m[l2] += 1;

        // std::cout << l1 << " " << m[l2] << std::endl;
    }

    // std::sort(arr1.begin(), arr1.end());
    // std::sort(arr2.begin(), arr2.end());

    long sum = 0;
    for (int i = 0; i < arr1.size(); ++i) {
        sum += abs(arr1[i] * m[arr1[i]]);
    }

    std::cout << sum << std::endl;
}