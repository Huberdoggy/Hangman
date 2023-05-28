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
        //std::cout << "Destroyed Hangman" << '\n';
        //std::cin.get();
    }

    void terminate_call() {
        delete this;
    }
    void renderFigure(const char*, const int) const;
    void renderFigure() const;
};

