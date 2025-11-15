#include "Sudoku.h"

#include <cassert>
#include <cstdio>

Sudoku::Sudoku(const uint64_t rows[9]) {
    for (int i = 0; i < 9; i++) {
        this->rows[i] = rows[i];
    }
}

uint8_t Sudoku::getDigitAt(unsigned int row, unsigned int col) const {
    assert(row < 9 && col < 9);

    return (rows[row] & 0xF << (col << 2)) >> (col << 2);
}

void Sudoku::setDigitAt(unsigned int row, unsigned int col, unsigned int digit) {
    assert(row < 9 && col < 9);
    assert(digit <= 9);

    rows[row] &= ~(0xF << (col << 2));
    rows[row] |= digit << (col << 2);
}

void Sudoku::print() const {
    for (int i = 0; i < 9; i++) {
        for (int j = 0; j < 9; j++) {
            unsigned char digit = getDigitAt(i, j) + '0';
            if (digit == '0')
                digit = '.';
            putc(digit, stdout);
            putc(' ', stdout);
        }
        putc('\n', stdout);
    }
}
