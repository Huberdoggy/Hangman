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
    for (int i = 0; i <= size; i++)
    {
        if (i == size)
        {
            *(s + i) = '\0';
        }
        else {
            *(s + i) = '_';
        }
    }

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

        ptr = &letters_remaining;
    }
    else {
        ptr = &num_guesses;
    }

    return ptr;
}