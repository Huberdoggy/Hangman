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
#include "NPC.h"
#include <windows.h>

bool readFile(const std::ifstream&);
std::vector<std::string> initVector(std::ifstream&);
void validateInput(int&);
void trimWordList(std::vector<std::string>&);
void displayMenu();
void refreshView(const std::optional<int> = std::nullopt);

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


void refreshView(const std::optional<int> sleep_time) {
    if (sleep_time)
    {
        Sleep(*sleep_time);
    }

    system("cls");
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
    const char* rightOffset = "\t\t\t\t\t\t";
    char newGame{ 'y' }, letter;


    if (!(readFile(manFile) || readFile(wordsFile))) {
        return 1;
    }

    std::vector<std::string> drawing = initVector(manFile);
    std::vector<std::string> wordList = initVector(wordsFile);
    trimWordList(wordList);

    /**************************************************************************/
    do
    {

        Hangman* gameMan = new Hangman(drawing);

        int* i_ptr = nullptr, inside_count = 0;
        refreshView();
        displayMenu();
        gameMan->renderFigure();
        refreshView(5000);
        std::cout << "How many letters should the secret word be? => ";
        validateInput(desiredLetters);
        NPC* tracker = new NPC(wordList);
        tracker->setSecretWord(tracker->pickRandWord(desiredLetters));
        tracker->reveal = tracker->initBlanks(desiredLetters, tracker->reveal); // set the game 'tiles' to empties
        refreshView(1000);
        std::cout << "\n\nGET READY!\t\t" << tracker->reveal << "\n\n"; // Show them the starting num of blanks
        std::cout << "Secret word this round is: " << tracker->getSecretWord() << "\n\n"; // For debugging
        refreshView(5000);
        while (tracker->num_guesses < drawing.size()) {
            if (tracker->secretWord == tracker->reveal)
                break; // Winner

            tracker->getGuess(letter);
            refreshView();

            for (int i = 0; i < tracker->secretWord.size(); i++) {

                i_ptr = tracker->handleGuess(letter, i);

                if (i_ptr != nullptr) // Found match
                {
                    tracker->reveal[i] = letter;
                    inside_count++; // ensure if ptr exits 'for' on a miss, 
                    //theres something tracking that we DID find something on a previously iterated letter
                }

            } // end for

            tracker->num_guesses = (inside_count == 0) ? tracker->num_guesses + 1 : tracker->num_guesses; // No letters found prev iteration
            gameMan->renderFigure(rightOffset, tracker->num_guesses);
            std::cout << "\t\t" << tracker->reveal << "\n\n";
            inside_count = 0; // Reset this counter so that next letter entered starts on clean slate
            refreshView(5000);
        } // end inner while

        i_ptr = nullptr;
        gameMan->terminate_call();
        tracker->terminate_call();
        refreshView();
        std::cout << "Secret word this round was: " << tracker->getSecretWord() << "\n\n";
        std::cout << "\n\nNew game? ['Y' 'N'] => ";
        std::cin >> newGame;


    } while (tolower(newGame) == 'y'); // end game loop while

    return 0;
}

