#include "Hangman.h"

// shared by all instances.. in this case, I only forsee a single instance of
// 'Hangman'. Not defined in header due to linking errors
std::vector<std::string> Hangman::manVec;


void Hangman::renderFigure() const {
    for (auto& i : manVec) {

        std::cout << "\t\t\t\t" << i << '\n'; // Opening menu - center screen
    }
}


// Overload
void Hangman::renderFigure(const char* fmtWidth, const int index) const {
    // we are only going to add to the drawing displayed on screen if guess is wrong
    // up to the point corresponding to the number of missed guesses
    for (int i = 0; i < index; i++)
    {
        std::cout << fmtWidth << manVec[i] << '\n';
    }
}

