#include <string>
#include <iostream>
#include <sstream>
#include "game.h"
#include "board.h"

Game::Game(bool white) : human(false), computer(true), checkmate(false), turn(0), 
                        display(white ? human : computer, white ? computer: human) 
{}

void Game::updateCheckmate() {
    return;
}

Print::Print(const Board& white, const Board& black) : w(white), b(black) {}

void Print::printBoard(std::ostream& out) {
    std::ostringstream board;
    board << "-----------------------------------------\n";
    for (int r = 7; r >= 0; r--) {
        for (int c = 0; c < 8; c++) {
            uint64_t square = 1ULL << (r*8 + c);
            board << "| " << getLabel(square) << " ";
        }
        board << "|\n";
    }
    board << "-----------------------------------------\n";
    out << board.str();
    return;
}

std::string Print::getLabel(uint64_t sq) {
    if (w.pawns & sq) { return "WP"; }
    if (b.pawns & sq) { return "BP"; }
    if (w.knights & sq) { return "WN"; }
    if (b.knights & sq) { return "BN"; }
    if (w.bishops & sq) { return "WB"; }
    if (b.bishops & sq) { return "BB"; }
    if (w.rooks & sq) { return "WR"; }
    if (b.rooks & sq) { return "BR";}
    if (w.queens & sq) { return "WQ"; }
    if (b.queens & sq) { return "BQ"; }
    if (w.king & sq) { return "WK"; }
    if (b.king & sq) { return "BK"; }
    return "--";
}