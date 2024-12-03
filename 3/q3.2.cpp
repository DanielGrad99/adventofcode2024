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

    bool enabled = true;

    while (true) {
        while (c != 'm' && c != 'd' && inputSS >> c);
        if (c != 'm' && c != 'd') break;

        if (c == 'd') {
            if (!(inputSS >> c)) break;
            if (c != 'o') {
                continue;
            }

            if (!(inputSS >> c)) break;
            if (c == '(') {
                if (!(inputSS >> c)) break;
                if (c == ')') enabled = true;

                continue;
            }

            if (c != 'n') {
                continue;
            }

            if (!(inputSS >> c)) break;
            if (c != '\'') {
                continue;
            }

            if (!(inputSS >> c)) break;
            if (c != 't') {
                continue;
            }

            if (!(inputSS >> c)) break;
            if (c == '(' && inputSS >> c && c == ')') {
                enabled = false;
                continue;
            }

            continue;
        }

        if (c == 'm') {
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

            if (enabled) sum += num1 * num2;
        }
    }

    std::cout << sum << std::endl;

    // std::string line;
    // while (std::getline(inputSS, line)) {
    //     std::stringstream ss;
    //     ss << line;
    // }
}