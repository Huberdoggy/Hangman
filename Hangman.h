#pragma once
#include "common_includes.h"


class Hangman
{

private:
    static std::vector<std::string> manVec;  // store lines read from input file to draw the man

public:
    Hangman(std::vector<std::string>& v) { // Constructor
        manVec = v;
    }

    ~Hangman() { // Destructor

    }


    bool readFile(std::ifstream& inFile) const;
    void renderFigure() const;
};

