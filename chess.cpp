#include <iostream>
#include <algorithm>
#include <cctype>
#include <string>
#include <vector>
#include <fstream>
#include <cstdint>
#include "board.h"
#include "move.h"

void printBoard(Board white, Board black);
void configSetUp(Move &toSet);

int main() {
    bool record = false;
    std::cout << "What is your rating? (approximates will do fine)\n";
    std::string rating;
    std::cin >> rating;
    std::ofstream data("ratingData.txt", std::ios::app);
    data << std::stoi(rating, nullptr, 10) << " ";
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
    configSetUp(moves);
    if (white) { printBoard(human, computer); }
    else { printBoard(computer, human); }

    data << "\n";
    data.close();

    return 0;
}

void configSetUp(Move &toSet) {
    std::ifstream magicRook("rook.txt");
    std::ifstream magicBishop("bishop.txt");
    std::string streamTemp;
    for (int i = 0; i < 64; i++) { 
        getline(magicRook, streamTemp);
        rookMagics[i] = std::stoull(streamTemp, nullptr, 16);
        getline(magicBishop, streamTemp);
        bishopMagics[i] = std::stoull(streamTemp, nullptr, 16);

        uint64_t currentPosition = 1ULL << i;
        uint64_t left = (currentPosition >> 1) & wrapLeftOne;
        uint64_t right = (currentPosition << 1) & wrapRightOne;
        uint64_t up = currentPosition << 8;
        uint64_t down = currentPosition >> 8;
        uint64_t diagUp = (left | right) << 8;
        uint64_t diagDown = (left | right) >> 8;

        kingAttacks[i] = left | right | up | down | diagUp | diagDown;
        
        
        if (i >= 8 && i < 16) { 
            pawnMoves[0][i] = up | (up << 8);
            pawnAttacks[0][i] = diagUp | diagDown; 
        }
    }
    magicRook.close();
    magicBishop.close();
    return;
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

/*
56  57  58  59  60  61  62  63
48  49  50  51  52  53  54  55
40  41  42  43  44  45  46  47
32  33  34  35  36  37  38  39
24  25  26  27  28  29  30  31
16  17  18  19  20  21  22  23
8   9   10  11  12  13  14  15
0   1   2   3   4   5   6   7
*/