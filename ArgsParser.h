//
// Created by kamil on 14.11.2025.
//

#ifndef SUDOKUSOLVER_ARGSPARSER_H
#define SUDOKUSOLVER_ARGSPARSER_H

#include <cwchar>
#include "Sudoku.h"


class ArgsParser {
private:
    int argc;
    char** argv;
    bool initialized;
    char method;
    int sudokuCount;
    int currentLine;
    FILE* inputFile;
    FILE* outputFile;
    void throwIfUninitialized() const;
public:
    ArgsParser(int argc, char** argv);
    ~ArgsParser();
    [[nodiscard]] const char* validateAndParseArgs();
    [[nodiscard]] Sudoku* getNextSudoku();
    [[nodiscard]] FILE* getOutputFile() const;
};


#endif //SUDOKUSOLVER_ARGSPARSER_H