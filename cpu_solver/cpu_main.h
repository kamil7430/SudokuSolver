//
// Created by kamil on 23.11.2025.
//

#ifndef SUDOKUSOLVERCUDA_CPU_MAIN_H
#define SUDOKUSOLVERCUDA_CPU_MAIN_H

#include "cpu_iterative_solver.h"

#define PRINTING_INTERVAL 1000

// Main function for solving sudokus on CPU
void cpu_main(Sudoku* sudokus, const int sudokuCount) {
    for (int i = 0; i < sudokuCount; i++) {
        if (i % PRINTING_INTERVAL == 0) {
            printf("### Solving sudoku %d ###\n", i);
        }

        Sudoku* sudoku = &sudokus[i];
        if (cpuPreprocessSudoku(sudoku)) {
            printf("Sudoku board %d is invalid!\n", i);
            memset(sudoku->rows, 0, 6 * sizeof(uint64_t));
        }
        else {
            const int result = cpuIterativeBruteforceSolveSudoku(sudoku);

            if (result > 0) {
                // puts("Sudoku solved!");

                // if (const int result = validateSudokuSolution(sudoku)) {
                //     printf("Is solution valid: %d\n", result);
                //     // printSudoku(sudoku, stdout, 1);
                //     assert(result == 1);
                // }
            }
            else {
                printf("Sudoku %d is invalid! Setting output to zeros.\n", i);
                memset(sudoku->rows, 0, 6 * sizeof(uint64_t));
                // assert("Invalid sudoku!");
            }
        }
    }
}

#endif //SUDOKUSOLVERCUDA_CPU_MAIN_H