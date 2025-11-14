#include <iostream>

#include "ArgsParser.h"

int main(int argc, char** argv) {
    auto parser = new ArgsParser(argc, argv);

    auto errorMessage = parser->validateAndParseArgs();
    if (errorMessage) {
        std::cerr << errorMessage;
        delete parser;
        return 1;
    }
    auto outputFile = parser->getOutputFile();

    Sudoku* sudoku;
    try {
        while ((sudoku = parser->getNextSudoku())) {
            // TODO: coś tam z sudoku

            delete sudoku;
        }
    }
    catch (std::exception& e) {
        std::cerr << e.what();
    }

    fclose(outputFile);
    delete parser;
    return 0;
}