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
#include <windows.h>

bool readFile(const std::ifstream&);
std::vector<std::string> initVector(std::ifstream&);
void validateInput(int&);
void trimWordList(std::vector<std::string>&);
void displayMenu();

/************************GLOBAL CONSTANTS**************************************/
const std::regex NUM_FILTER {"[^a-zA-Z]"};
constexpr int MIN_LETTERS{ 4 }, MAX_LETTERS{ 12 };

/****************FUNCTION DEFINITIONS******************************************/
bool readFile(const std::ifstream& inFile) {

    return (!inFile) ? false : true;
}


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



void displayMenu() {
    std::string welcome {"WELCOME TO HANGMAN!"};
    std::cout << std::setfill('*') << std::setw(85) << '\n';
    std::cout << std::setfill(' ') << std::setw(45) << welcome << std::setw(45) << '\n';
    std::cout << std::setfill('*') << std::setw(85) << '\n';
    std::cout << "\n\n";
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



void trimWordList(std::vector<std::string>& v) {
    auto it = v.begin(); // Store iterator
    while (it != v.end())
    {
        if (std::regex_search(*it, NUM_FILTER) ||
           ((*it).length() < MIN_LETTERS || (*it).length() > MAX_LETTERS)) {
            it = v.erase(it); // Returns iterator pointing to 
            // adjusted loc of next item in vec
        }
        else {
            it++;
        }
    }

    // Test - check trimmed vec
   // for (auto& i : v) std::cout << i << std::endl;
}




/******************************************************************************/

int main() {

    /******************VARIABLE INITIALIZATIONS********************************/
    std::string manPath = std::getenv("STREAMFILE_DIR");
    manPath += "\\Hangman\\hangman.txt";
    std::string wordsPath = std::getenv("STREAMFILE_DIR");
    wordsPath += "\\Hangman\\wordlist.txt";
    std::ifstream manFile(manPath), wordsFile(wordsPath);
    int desiredLetters;
    char newGame{ 'y' };

    if (!(readFile(manFile) || readFile(wordsFile))) {
        return 1;
    }

    std::vector<std::string> drawing = initVector(manFile);
    std::vector<std::string> wordList = initVector(wordsFile);
    trimWordList(wordList);

    Hangman gameMan(drawing);
    /**************************************************************************/
    do
    {
        system("cls");
        displayMenu();
        gameMan.renderFigure();
        Sleep(5000);
        system("cls");
        std::cout << "How many letters should the secret word be? => ";
        validateInput(desiredLetters);
        std::cout << "New game? ['Y' 'N'] => ";
        std::cin >> newGame;
    } while (tolower(newGame) == 'y');

    return 0;

}

