#include <iostream>
#include <algorithm>
#include <cctype>
#include <string>
#include <vector>
#include "board.h"
#include "move.h"

Move::Move(Board& hum, Board& cpu) : human(hum), computer(cpu) { }

uint64_t Move::tileToInt(char column, int row) {
    int newColumn = column - 'a';
    uint64_t spot = 2^(newColumn - (8*row));
    return spot;
}

std::string Move::intToTile(uint64_t pos) {
    int tileNumber = 0;
    std::cout << "IntoTile, Pos: " << pos << "\n";
    while (true) {
        if ((1ULL << tileNumber) == pos) { std::cout << "Tile: 2^" << tileNumber << "\n";
            break; }
        else { tileNumber++; }
    }
    int column = tileNumber % 8;
    std::cout << "Num column: " << column << "\n";
    char newColumn = column + 'a';
    std::cout << "Alpha column: " << newColumn << "\n";
    tileNumber /= 8;
    std::cout << "Tile Number: " << tileNumber << "\n";
    std::string algTile = "";
    algTile += newColumn;
    algTile += tileNumber;
    return algTile;
}

std::vector<uint64_t> Move::pawnMoves(uint64_t pos, Board& attacker, Board& defender) {
    std::vector<uint64_t> moves;
    uint64_t defBoard = defender.sumPieces();
    uint64_t wholeBoard = (defender.sumPieces() | attacker.sumPieces());
    if (attacker.top) {
        uint64_t front = (pos >> 8);
        uint64_t leftDiag = (pos >> 9);
        uint64_t rightDiag = (pos >> 7);
        if (!(front & wholeBoard)) { moves.push_back(front); }
        if (pos <= (1ULL << 55) && pos >= (1ULL << 48)) {
            uint64_t doubleFront = (pos >> 16);
            // EN PASSANT
            if (!(doubleFront & wholeBoard)) { moves.push_back(doubleFront); }
        }
        for (int i = 55; i >= 8; i--) {
            if (((pos == 1ULL >> i) && (i % 8 == 0)) && (rightDiag & defBoard)) { moves.push_back(rightDiag); }
            else if (((pos == 1ULL >> i) && ((i+1) % 8 == 0)) && (leftDiag & defBoard)) { moves.push_back(leftDiag); }
        }
    }
    else {
        uint64_t front = (pos << 8);
        uint64_t leftDiag = (pos << 7);
        uint64_t rightDiag = (pos << 9);       
        if (!(front & wholeBoard)) { moves.push_back(front); }
        if (pos <= (1ULL << 15) && pos >= (1ULL << 8)) {
            uint64_t doubleFront = (pos << 16);
            //EN PASSANT AGAIN
            if (!(doubleFront & wholeBoard)) { moves.push_back(doubleFront); }
        }
        for (int i = 8; i < 56; i++) {
            if (((pos == 1ULL << i) && (i % 8 == 0)) && (rightDiag & defBoard)) { moves.push_back(rightDiag); }
            else if (((pos == 1ULL << i) && ((i+1) % 8 == 0)) && (leftDiag & defBoard)) { moves.push_back(rightDiag); }
        }
    }
    return moves;
}

std::vector<uint64_t> Move::rookMoves(uint64_t pos, Board& attacker, Board& defender) {
    std::vector<uint64_t> moves;
    uint64_t defBoard = defender.sumPieces();
    uint64_t wholeBoard = (defender.sumPieces() | attacker.sumPieces());
    return moves;
}

std::vector<uint64_t> Move::knightMoves(uint64_t pos, Board& attacker, Board& defender) {
    std::vector<uint64_t> moves;
    uint64_t defBoard = defender.sumPieces();
    uint64_t wholeBoard = (defender.sumPieces() | attacker.sumPieces());
    return moves;
}

std::vector<uint64_t> Move::bishopMoves(uint64_t pos, Board& attacker, Board& defender) {
    std::vector<uint64_t> moves;
    uint64_t defBoard = defender.sumPieces();
    uint64_t wholeBoard = (defender.sumPieces() | attacker.sumPieces());
    return moves;
}

std::vector<uint64_t> Move::queenMoves(uint64_t pos, Board& attacker, Board& defender) {
    std::vector<uint64_t> moves;
    uint64_t defBoard = defender.sumPieces();
    uint64_t wholeBoard = (defender.sumPieces() | attacker.sumPieces());
    return moves;
}

std::vector<uint64_t> Move::kingMoves(uint64_t pos, Board& attacker, Board& defender) {
    std::vector<uint64_t> moves;
    uint64_t defBoard = defender.sumPieces();
    uint64_t wholeBoard = (defender.sumPieces() | attacker.sumPieces());
    return moves;
}


