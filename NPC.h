#pragma once
#include "common_includes.h"


class NPC
{

private:
    static std::vector<std::string> wordVec;

public:
    NPC(std::vector<std::string>& v) {
        srand(static_cast<unsigned>(time(0))); // Upon instance creation, seed rand
        wordVec = v;
    }

    ~NPC() {

    }

    std::string pickRandWord(int, const std::vector<std::string>& = wordVec) const;

};
