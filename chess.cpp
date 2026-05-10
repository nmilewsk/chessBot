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
    
    //Inquiries about rating for data
    bool record = false;
    std::cout << "What is your rating? If unsure, press enter to skip...\n(Approximates will do fine)\n";
    std::string rating;
    std::ofstream data("ratingData.txt", std::ios::app);
    std::getline(std::cin, rating);
    if (!rating.empty()) {
        record = true;
        data << std::stoi(rating, nullptr, 10) << " ";
    }



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
    // configSetUp(moves);
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

        int row = i / 8;
        int column = i % 8;

        uint64_t rook = 0;
        for (int j = row + 1; j <= 6; j++) { rook |= 1ULL << ((8*j) + column); } //up
        for (int j = row - 1; j >= 1; j--) { rook |= 1ULL << ((8*j) + column); } //down
        for (int j = column + 1; j <= 6; j++) { rook |= 1ULL << ((8*row) + j); } //right
        for (int j = column - 1; j >= 1; j--) { rook |= 1ULL << ((8*row) + j); } //left
        rookMasks[i] = rook;
        int rookConfigs = __builtin_popcountll(rook);
        uint64_t rookBlocks = 0;
        do {
            uint64_t attacks = 0;
            for (int j = row + 1; j <= 7; j++) { 
                attacks |= 1ULL << ((8*j) + column); if (rookBlocks & (1ULL << ((8*j) + column))) break;
            }
            for (int j = row - 1; j >= 0; j--) {
                attacks |= 1ULL << ((8*j) + column); if (rookBlocks & (1ULL << ((8*j) + column))) break;
            }
            for (int j = column + 1; j <= 7; j++) {
                attacks |= 1ULL << ((8*row) + j); if (rookBlocks & (1ULL << ((8*row) + j))) break;
            }
            for (int j = column - 1; j >= 0; j--) {
                attacks |= 1ULL << ((8*row) + j); if (rookBlocks & (1ULL << ((8*row) + j))) break;
            }
            int index = (rookBlocks*rookMagics[i]) >> (64 - rookConfigs);
            rookAttacks[i][index] = attacks;
            rookBlocks =(rookBlocks - rookMasks[i]) & rookMasks[i];
        } while (rookBlocks != 0);

        uint64_t bishop = 0;
        for (int j = row + 1, k = column + 1; j <= 6 && k <= 6; j++, k++) { bishop |= 1ULL << ((8*j) + k); } //UR
        for (int j = row - 1, k = column + 1; j >= 1 && k <= 6; j--, k++) { bishop |= 1ULL << ((8*j) + k); } //DR
        for (int j = row + 1, k = column - 1; j <= 6 && k >= 1; j++, k--) { bishop |= 1ULL << ((8*j) + k); } //UL
        for (int j = row - 1, k = column - 1; j >= 1 && k >= 1; j--, k--) { bishop |= 1ULL << ((8*j) + k); } //DL
        bishopMasks[i] = bishop;
        int bishopConfigs = __builtin_popcountll(bishop);
        uint64_t bishopBlocks = 0;
        do {
            uint64_t attacks = 0;
            for (int j = row + 1, k = column + 1; j <= 7 && k <= 7; j++, k++) { 
                attacks |= 1ULL << ((8*j) + k); if (bishopBlocks & (1ULL << ((8*j) + k))) break;
            }
            for (int j = row - 1, k = column + 1; j >= 0 && k <= 7; j--, k++) { 
                attacks |= 1ULL << ((8*j) + k);  if (bishopBlocks & (1ULL << ((8*j) + k))) break;
            }
            for (int j = row + 1, k = column - 1; j <= 7 && k >= 0; j++, k--) { 
                attacks |= 1ULL << ((8*j) + k);  if (bishopBlocks & (1ULL << ((8*j) + k))) break;
            }
            for (int j = row - 1, k = column - 1; j >= 0 && k >= 0; j--, k--) { 
                attacks |= 1ULL << ((8*j) + k);  if (bishopBlocks & (1ULL << ((8*j) + k))) break;
            }
            int index = (bishopBlocks*bishopMagics[i]) >> (64 - bishopConfigs);
            bishopAttacks[i][index] = attacks;
            bishopBlocks = (bishopBlocks - bishopMasks[i]) & bishopMasks[i];
        } while (bishopBlocks != 0);


        uint64_t twoLeft = (left >> 1) & wrapLeftTwo;
        uint64_t twoRight = (right << 1) & wrapRightTwo;
        knightAttacks[i] = 
            (twoLeft << 8) | (twoLeft >> 8) | 
            (twoRight << 8) | (twoRight >> 8) | 
            (left << 16) | (right >> 16) |
            (left >> 16) | (right << 16);

        pawnAttacks[0][i] = diagUp;
        pawnAttacks[1][i] = diagDown;
        if (i >= 8 && i < 16) { 
            pawnMoves[0][i] = up | (up << 8);
            pawnMoves[1][i] = down;
        }
        else if (i >= 48 && i < 56) {
            pawnMoves[1][i] = down | (down >> 8);
            pawnMoves[0][i] = up;
        }
        else {
            pawnMoves[0][i] = up;
            pawnMoves[1][i] = down;
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