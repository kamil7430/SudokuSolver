//
// Created by kamil on 14.11.2025.
//

#ifndef SUDOKUSOLVER_SUDOKU_H
#define SUDOKUSOLVER_SUDOKU_H
#include <cstdint>


class Sudoku {
private:
    uint64_t rows[9] = {};
public:
    explicit Sudoku(const uint64_t rows[9]);
    Sudoku() = default;
    [[nodiscard]] uint8_t getDigitAt(unsigned int row, unsigned int col) const;
    void setDigitAt(unsigned int row, unsigned int col, unsigned int digit);
    void print() const;
};


#endif //SUDOKUSOLVER_SUDOKU_H