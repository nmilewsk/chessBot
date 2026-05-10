#ifndef MOVE_H
#define MOVE_H
#include <iostream>
#include <algorithm>
#include <cctype>
#include <string>
#include <vector>
#include <cstdint>
#include "board.h"

extern const uint64_t wrapLeftOne;
extern const uint64_t wrapLeftTwo;
extern const uint64_t wrapRightOne;
extern const uint64_t wrapRightTwo;

extern uint64_t rookAttacks[64][4096];
extern uint64_t rookMasks[64];
extern uint64_t rookMagics[64];
extern uint64_t bishopAttacks[64][4096];
extern uint64_t bishopMasks[64];
extern uint64_t bishopMagics[64];
extern uint64_t knightAttacks[64];
extern uint64_t kingAttacks[64];
extern uint64_t pawnMoves[2][64];
extern uint64_t pawnAttacks[2][64];

struct Move {
    uint64_t tileToInt(char column, int row);
    std::string intToTile(uint64_t pos);

    uint64_t pawnMoves(int sq, uint64_t attackBoard, uint64_t defBoard);
    uint64_t rookMoves(int sq, uint64_t attackBoard, uint64_t defBoard);
    uint64_t knightMoves(int sq, uint64_t attackBoard, uint64_t defBoard);
    uint64_t bishopMoves(int sq, uint64_t attackBoard, uint64_t defBoard);
    uint64_t queenMoves(int sq, uint64_t attackBoard, uint64_t defBoard);
    uint64_t kingMoves(int sq, uint64_t attackBoard, uint64_t defBoard);

    void doMove(std::string, Board& att, Board& def);

};

#endif