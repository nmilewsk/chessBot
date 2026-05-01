#include <iostream>
#include <algorithm>
#include <cctype>
#include <string>
#include "board.h"
#include "move.h"

Move::Move(Board& hum, Board& cpu) : human(hum), computer(cpu) { }

bool Move::isValidMove(std::string move, Board& attacker, Board& defender) {
    return 0;
}

u_int64_t Move::tileToInt(char row, int column) {
    return 0;
}

