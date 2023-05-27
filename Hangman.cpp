#include "Hangman.h"

// shared by all instances.. in this case, I only forsee a single instance of
// 'Hangman'. Not defined in header due to linking errors
std::vector<std::string> Hangman::manVec;


void Hangman::renderFigure(const std::optional<const char*> fmtWidth) const {

    for (auto& i : manVec) {
        if (fmtWidth)
        {
            std::cout << *fmtWidth << i << '\n'; // Postion further across screen
            // when game is running
        }
        else {
            std::cout << "\t\t\t\t" << i << '\n'; // Opening menu - center screen
        }
    }
}

