#include <iostream>
#include <algorithm>
#include <cctype>
#include <string>
#include <vector>
#include <fstream>
#include <cstdint>
#include "board.h"
#include "move.h"

const uint64_t wrapLeftOne = 0xFEFEFEFEFEFEFEFE; //0s on right column
const uint64_t wrapLeftTwo = 0xFCFCFCFCFCFCFCFC; //0s on right two columns
const uint64_t wrapRightOne = 0x7F7F7F7F7F7F7F7F; //0s on left column
const uint64_t wrapRightTwo = 0x3F3F3F3F3F3F3F3F; //0s on left two columns

uint64_t rookAttacks[64][4096];
uint64_t rookMasks[64];
uint64_t rookMagics[64];
uint64_t bishopAttacks[64][4096];
uint64_t bishopMasks[64];
uint64_t bishopMagics[64];
uint64_t knightAttacks[64];
uint64_t kingAttacks[64];
uint64_t pawnMoves[2][64]; //pawnAttacks[0] = human, pawnAttacks[1] = computer
uint64_t pawnAttacks[2][64];


uint64_t Move::tileToInt(char column, int row) {
    int newColumn = column - 'a' + 1;
    int test = (8*row) - newColumn;
    uint64_t spot = 1ULL << test;
    return spot;
}

std::string Move::intToTile(uint64_t pos) {
    int tileNumber = 0;
    while (true) {
        if ((1ULL << tileNumber) == pos) { break; }
        else { tileNumber++; }
    }
    int column = tileNumber % 8;
    char newColumn = column + 'a';
    tileNumber /= 8;
    std::string algTile = "";
    algTile += newColumn;
    algTile += std::to_string(tileNumber + 1);
    return algTile;
}

uint64_t Move::pawnMoves(int sq, uint64_t attackBoard, uint64_t defBoard) {
    return 0;
}

uint64_t Move::rookMoves(int sq, uint64_t attackBoard, uint64_t defBoard) {
    return 0;
}

uint64_t Move::knightMoves(int sq, uint64_t attackBoard, uint64_t defBoard) {
    return 0;
}

uint64_t Move::bishopMoves(int sq, uint64_t attackBoard, uint64_t defBoard) {
    return 0;
}

uint64_t Move::queenMoves(int sq, uint64_t attackBoard, uint64_t defBoard) {
    return 0;
}

uint64_t Move::kingMoves(int sq, uint64_t attackBoard, uint64_t defBoard) {
    return 0;
}


