#include "NPC.h"

std::vector<std::string> NPC::wordVec; // Static definitions
std::string NPC::secretWord;


std::string NPC::pickRandWord(int num, const std::vector<std::string>& v) const {
    size_t first = 0, last = v.size(); // Full 'size' to account for range of inclusiveness for rand
    int random = static_cast<int>(first) + (rand() % static_cast<int>(last));

    return (v[random].length() > num || v[random].length() < num) ?
        pickRandWord(num, v) : v[random];
}


char* NPC::initBlanks(const int size, char* s) {
    s = new char[size];

    for (int i = 0; i < size; i++)
    {
        *(s + i) = '_';
    }
    *(s + size) = '\0';

    return s;
}


void NPC::setSecretWord(const std::string& s) {

    secretWord = s;
}


std::string_view NPC::getSecretWord() const {

    return secretWord;
}


void NPC::getGuess(char& letter) {
    std::cout << "Guess a letter => ";
    std::cin >> letter;
}



int* NPC::handleGuess(const char& letter, const int iterator) {
    int* ptr = new int;
    if (secretWord[iterator] == letter) {

        ptr = &dummyData; // Only returning ptr here as a way to convenientally track
        // if this iteration's chosen letter is hit or miss. Comparing addresses in main()
        return ptr;
    }

    return nullptr;
}