//
// Created by kamil on 25.11.2025.
//

#ifndef SUDOKUSOLVERCUDA_CPU_ITERATIVE_SOLVER_H
#define SUDOKUSOLVERCUDA_CPU_ITERATIVE_SOLVER_H
#include "../sudoku.h"

int cpuIterativeBruteforceSolveSudoku(Sudoku* sudoku, const int sudokuNo) {
    // Prepare data structures for bruteforce
    // empty_indices format: xxxxyyyy (8 bits):
    // xxxx - row (i)
    // yyyy - col (j)
    uint8_t empty_indices[SUDOKU_BOARD_SIZE] = {};
    uint8_t empty_count = 0; // Length of empty_indices array

    // Find all empty cells
    for (uint8_t i = 0; i < SUDOKU_DIMENSION_SIZE; i++) {
        for (uint8_t j = 0; j < SUDOKU_DIMENSION_SIZE; j++) {
            if (getDigitAt(sudoku, sudokuNo, i, j) == 0) {
                empty_indices[empty_count] = (i << 4) | j;
                empty_count++;
            }
        }
    }

    // Perform iterative bruteforce
    int stack_idx = 0;
    while (stack_idx >= 0 && stack_idx < empty_count) { // TODO: dobrze?
        // Take one empty cell from "stack" array
        uint8_t empty_cell_position = empty_indices[stack_idx];
        uint8_t row = empty_cell_position >> 4;
        uint8_t col = empty_cell_position & 0xF;

        // Clean up previous iteration (if occurred)
        uint8_t previousDigit = getDigitAt(sudoku, sudokuNo, row, col);
        if (previousDigit != 0)
            removeDigitAndUpdateUsedDigits(sudoku, sudokuNo, row, col, previousDigit);

        // Bruteforce every digit
        uint16_t digitsMask = getPossibleDigitsAt(sudoku, sudokuNo, row, col);

        // If it's not first try for this cell, shift the possible digits mask
        digitsMask >>= previousDigit;

        if (digitsMask == 0) {
            // No possible digits - backtracking
            stack_idx--;
        }
        else {
            const int shift = __builtin_ffs(digitsMask);
            const int digit = previousDigit + shift;
            setDigitAndUpdateUsedDigits(sudoku, sudokuNo, row, col, digit);
            stack_idx++;
            //printSudoku(sudoku, stdout, 1);
        }
    }

    // Check if the solution was found
    if (stack_idx == empty_count) {
        return 1;
    }

    return -1;
}

#endif //SUDOKUSOLVERCUDA_CPU_ITERATIVE_SOLVER_H