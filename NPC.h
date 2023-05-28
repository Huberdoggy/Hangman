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
    int dummyData;


    NPC(std::vector<std::string>& v) {
        srand(static_cast<unsigned>(time(0))); // Upon instance creation, seed rand
        wordVec = v;
        dummyData = 1; // set simply so pointer will not be null later. See handleGuess
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
