#include <iostream>
#include <algorithm>
#include <cctype>
#include <string>
#include "board.h"

int main() {
    bool valid = false;
    while (!valid) {
        std::cout << "White or black?\n";
        std::string color;
        std::cin >> color;
        std::transform(color.begin(), color.end(), color.begin(), [](unsigned char c){ return std::tolower(c); });
        if (color == "w" || color == "white") {
            valid = true;
        }
        else if (color == "b" || color == "black") {
            valid = true;
        }
        else {
            std::cout << "Error reading input\n";
        }
    }
    Board human = {false};
    Board bot = {true};
    human.printBoard(bot);
    return 0;
}