#include <cmath>
#include <fstream>
#include <iostream>
#include <sstream>
#include <vector>

int main() {
    std::ifstream inputSS;
    inputSS.open("input.txt");

    std::vector<long> arr1;
    std::vector<long> arr2;

    long sum = 0;

    char c = '\0';

    while (true) {

        while (c != 'm' && inputSS >> c);

        if (c != 'm') break;

        if (c != 'm') {
            continue;
        }

        if (!(inputSS >> c)) break;
        if (c != 'u') {
            continue;
        }

        if (!(inputSS >> c)) break;
        if (c != 'l') {
            continue;
        }

        if (!(inputSS >> c)) break;
        if (c != '(') {
            continue;
        }

        if (!isdigit(inputSS.peek())) continue;

        long num1;
        if (!(inputSS >> num1)) break;

        if (!(inputSS >> c)) break;
        if (c != ',') {
            continue;
        }

        if (!isdigit(inputSS.peek())) continue;

        long num2;
        if (!(inputSS >> num2)) break;

        if (!(inputSS >> c)) break;
        if (c != ')') {
            continue;
        }

        sum += num1 * num2;
    }

    std::cout << sum << std::endl;

    // std::string line;
    // while (std::getline(inputSS, line)) {
    //     std::stringstream ss;
    //     ss << line;
    // }
}