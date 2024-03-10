#include <iostream>
#include <string>
#include <cstdlib>
#include <ctime>
#include <fstream>
#include <list>

class HangmanGame 
{
private:
    std::string secretWord;
    std::string guessedWord;
    int maxAttempts;
    int remainingAttempts;
    std::list<char> guessedLetters;

public:
    HangmanGame(const std::string& word, int attempts) : secretWord(word), maxAttempts(attempts), remainingAttempts(attempts) 
    {
        guessedWord = std::string(secretWord.length(), '_');
    }

    void play() {
        while (remainingAttempts > 0 && guessedWord != secretWord) 
        {
            displayStatus();
            char guess = getGuess();
            updateGuessedWord(guess);
            if (secretWord.find(guess) == std::string::npos) 
            {
                remainingAttempts--;
                std::cout << "Incorrect guess! " << remainingAttempts << " attempts left.\n";
            }
        }

        if (guessedWord == secretWord) 
        {
            std::cout << "Congratulations! You guessed the word: " << secretWord << std::endl;
        } else 
        {
            std::cout << "Out of attempts! The word was: " << secretWord << std::endl;
        }
    }

private:
    void displayStatus() 
    {
        std::cout << "Guessed word: " << guessedWord << std::endl;
        std::cout << "Guessed letters: ";
        for (char letter : guessedLetters) 
        {
            std::cout << letter << " ";
        }
        std::cout << std::endl;
    }

    char getGuess() 
    {
        char guess;
        std::cout << "Enter your guess: ";
        std::cin >> guess;
        guessedLetters.push_back(guess);
        return guess;
    }

    void updateGuessedWord(char guess) 
    {
        for (size_t i = 0; i < secretWord.length(); ++i) 
        {
            if (secretWord[i] == guess) 
            {
                guessedWord[i] = guess;
            }
        }
    }
};

int main() 
{
    std::ifstream file("C:/Users/ACER/Desktop/Codes/C++ Sftw/words.txt");
    if (!file.is_open()) 
    {
        std::cerr << "Error opening file." << std::endl;
        return 1;
    }

    std::list<std::string> words;
    std::string word;
    while (file >> word) 
    {
        words.push_back(word);
    }
    file.close();

    if (words.empty()) 
    {
        std::cerr << "No words found in file." << std::endl;
        return 1;
    }

    srand(time(nullptr));
    int randomIndex = rand() % words.size();
    auto it = std::next(words.begin(), randomIndex);
    std::string secretWord = *it;

    HangmanGame game(secretWord, 6);
    game.play();

    return 0;
}
