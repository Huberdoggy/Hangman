/*
OBJECTIVES:

The hangman project game consists of guessing a secret word of a given length
by entering one letter at a time. The game ends if the user does not correctly
guess the word within the allotted number of guesses. The Hangman game will
utilize classes to store the hidden word and guesses a class containing member
methods used to track progress, and a class to represent the hangman figure.
The game logic will be written using a variety of modern C++ features

*/

#include "Hangman.h"

std::vector<std::string> initVector(std::ifstream&);
void validateInput(int&);

/************************GLOBAL CONSTANTS**************************************/
const std::regex NUM_FILTER {"[^a-zA-Z]"};
constexpr int MIN_LETTERS{ 4 }, MAX_LETTERS{ 12 };

/****************FUNCTION DEFINITIONS******************************************/
std::vector<std::string> initVector(std::ifstream& inFile) {

    std::vector<std::string> v;

    std::string line;

    while (!(inFile.eof()))
    {

        std::getline(inFile, line);
        v.push_back(line);
    }
    inFile.close();
    return v;
}


void validateInput(int& user_input) {
    while (!(std::cin >> user_input) || (user_input < MIN_LETTERS || user_input > MAX_LETTERS))
    {
        std::cin.clear();
        ignoreExtraneous();
        printf("ERROR! The word should be between %d and %d letters.\nTry again => "
            , MIN_LETTERS, MAX_LETTERS);
    }
}





/******************************************************************************/

int main() {

    /******************VARIABLE INITIALIZATIONS*********************************************/

    std::string manPath = std::getenv("STREAMFILE_DIR");
    manPath += "\\Hangman\\hangman.txt";
    std::string wordsPath = std::getenv("STREAMFILE_DIR");
    wordsPath += "\\Hangman\\wordlist.txt";
    std::ifstream manFile(manPath), wordsFile(wordsPath);

    std::vector<std::string> drawing = initVector(manFile);
    std::vector<std::string> wordList = initVector(wordsFile);
    int desiredLetters;
    Hangman gameMan(drawing);
    /******************************************************************************/

    if (!(gameMan.readFile(manFile) || gameMan.readFile(wordsFile))) {
        return 1;
    }


    std::cout << "How many letters should the secret word be? => ";
    validateInput(desiredLetters);
    gameMan.renderFigure();

    for (int i = 0; i < wordList.size(); i++)
    {
        if (std::regex_search(wordList[i], NUM_FILTER) ||
            (wordList[i].length() < MIN_LETTERS || wordList[i].length() > MAX_LETTERS)) {
            
            continue;
        }
        //std::cout << wordList[i] << '\n';
    }


    return 0;

}

