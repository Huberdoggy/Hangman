#include "Hangman.h"

// shared by all instances.. in this case, I only forsee a single instance of
// 'Hangman'
// Not defined in header due to linking errors
std::vector<std::string> Hangman::manVec;

bool Hangman::readFile(std::ifstream& inFile) const {

    return (!inFile) ? false : true;
}


void Hangman::renderFigure() const {

    for (auto& i : manVec) {
        std::cout << i << '\n';
    }
}

