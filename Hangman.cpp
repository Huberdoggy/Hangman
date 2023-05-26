#include "Hangman.h"

// shared by all instances.. in this case, I only forsee a single instance of
// 'Hangman'. Not defined in header due to linking errors
std::vector<std::string> Hangman::manVec;


void Hangman::renderFigure() const {

    for (auto& i : manVec) {
        std::cout << "\t\t\t\t" << i << '\n';
    }
}

