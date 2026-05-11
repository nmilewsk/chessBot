#ifndef PRINT_H
#define PRINT_H
#include <string>
#include <iostream>
#include "board.h"

struct Print {
    const Board& w;
    const Board& b;

    Print(const Board& white, const Board& black);

    void printBoard(std::ostream& out = std::cout);

private:
    std::string getLabel(uint64_t sq);
};

#endif