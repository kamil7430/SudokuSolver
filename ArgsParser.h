//
// Created by kamil on 14.11.2025.
//

#ifndef SUDOKUSOLVER_ARGSPARSER_H
#define SUDOKUSOLVER_ARGSPARSER_H

#include <cwchar>

#include "consts.h"
#include "Sudoku.h"


class ArgsParser {
private:
    int argc;
    char** argv;
    bool initialized = false;
    char method = 'a';
    int totalSudokuCount = -1;
    int sudokusParsed = 0;
    char buffer[Consts::SUDOKU_BOARD_SIZE] = {};
    FILE* inputFile = nullptr;
    FILE* outputFile = nullptr;
    void throwIfUninitialized() const;
public:
    ArgsParser(int argc, char** argv);
    ~ArgsParser();
    [[nodiscard]] const char* validateAndParseArgs();
    [[nodiscard]] Sudoku* getNextSudoku();
    [[nodiscard]] FILE* getOutputFile() const;
    [[nodiscard]] char getMethod() const;
};


#endif //SUDOKUSOLVER_ARGSPARSER_H