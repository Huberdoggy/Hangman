#include "NPC.h"


std::vector<std::string> NPC::wordVec; // Static definition


std::string NPC::pickRandWord(int num, const std::vector<std::string>& v) const {
    size_t first = 0, last = v.size(); // Full 'size' to account for range of inclusiveness for rand
    int random = static_cast<int>(first) + (rand() % static_cast<int>(last));
    
    return (v[random].length() > num || v[random].length() < num) ? 
        pickRandWord(num, v) : v[random];
}

void NPC::setSecretWord(const std::string& s) {

    secretWord = s;
}


std::string_view NPC::getSecretWord() const{

    return secretWord;
}