#ifndef MOVE_H
#define MOVE_H
#include <iostream>
#include <algorithm>
#include <cctype>
#include <string>
#include "board.h"

struct Move {
    Board human;
    Board computer;
    Move(Board& hum, Board& cpu);
    bool isValidMove(std::string move, Board& attacker, Board& defender);
    u_int64_t tileToInt(char row, int column);
};

#endif