#pragma once
#include "common_includes.h"

class NPC
{

private:
    static std::vector<std::string> wordVec;

public:
    static std::string secretWord;
    char* reveal;
    int num_guesses;
    int letters_remaining;


    NPC(std::vector<std::string>& v, const int s) {
        srand(static_cast<unsigned>(time(0))); // Upon instance creation, seed rand
        wordVec = v;
        letters_remaining = s; // set based on user's chosen number of letters per game round
        reveal = nullptr;
        num_guesses = 0;
        
    }

    ~NPC() {
        
        //std::cout << "Destroyed NPC object" << '\n';
        //std::cin.get();
    }


    void terminate_call(){
        delete this;
    }
    char* initBlanks(const int, char*);
    std::string pickRandWord(int, const std::vector<std::string> & = wordVec) const;
    std::string_view getSecretWord() const;
    void setSecretWord(const std::string&);
    void getGuess(char&);
    int* handleGuess(const char&, const int);
};
