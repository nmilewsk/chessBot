#include <iostream>
#include <algorithm>
#include <cctype>
#include <string>
#include "board.h"
#include "move.h"

void printBoard(Board white, Board black);

int main() {
    bool valid = false;
    bool white = false;
    while (!valid) {
        std::cout << "White or black?\n";
        std::string color;
        std::cin >> color;
        std::transform(color.begin(), color.end(), color.begin(), [](unsigned char c){ return std::tolower(c); });
        if (color == "w" || color == "white") {
            valid = true;
            white = true;
        }
        else if (color == "b" || color == "black") {
            valid = true;
        }
        else {
            std::cout << "Error reading input\n";
        }
    }
    Board human = {false};
    Board computer = {true};
    Move moves = {human, computer};
    if (white) { printBoard(human, computer); }
    else { printBoard(computer, human);}
    return 0;
}

void printBoard(Board white, Board black) {
    for (int i = 63; i >= 0; i--) {
        std::cout << "|";
        if ((white.sumPieces() >> i) & 1) { std::cout << "W"; }
        else if ((black.sumPieces() >> i) & 1) { std::cout << "B"; }
        else { std::cout << "0"; }
        if (i % 8 == 0) { std::cout << "|\n"; }
    }
}