#pragma once
#include "common_includes.h"


class NPC
{

private:
    static std::vector<std::string> wordVec;
    std::string secretWord;
    char* reveal = new char[strlen(secretWord.c_str())];

public:
    NPC(std::vector<std::string>& v) {
        srand(static_cast<unsigned>(time(0))); // Upon instance creation, seed rand
        wordVec = v;
        
    }

    ~NPC() {
        delete[] reveal;
    }

    std::string pickRandWord(int, const std::vector<std::string>& = wordVec) const;
    std::string_view getSecretWord() const;
    void setSecretWord(const std::string&);
    void displayProgress() const;
};
