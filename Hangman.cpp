#include "Hangman.h"


bool Hangman::readFile(std::ifstream& inFile) const {

    return (!inFile) ? false : true;
}


void Hangman::renderFigure() const {

    for (auto& i : manVec) {
        std::cout << i << '\n';
    }
}

