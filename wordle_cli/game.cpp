#include "game.h"
#include <string>
#include <vector>
#include <fstream>
#include <iostream>
#include <cstdlib>
#include <algorithm>

std::string Game::create_board(int word_len)
{
    std::string game_board(word_len, '-');
    return game_board;
};

std::vector<std::string> Game::read_dict()
{
    std::string line;
    std::vector<std::string> lines;

    std::ifstream file("sgb-words.txt");

    while (file.is_open())
    {
        while (getline(file, line))
        {
            lines.push_back(line);
        }
        file.close();
    }
    return lines;
};

bool Game::is_guess_correct(std::string word, std::string guess)
{
    {
        if (guess.length() != word.length())
        {
            return false;
        }

        bool isCorrect = false;
        for (size_t i = 0; i < word.length(); i++)
        {
            if (guess[i] == word[i])
            {
                ;
                isCorrect = true;
            }
        }

        return isCorrect;
    }
}

void Game::print_colored_word(const std::string &word, const std::string &guess)
{
    // used to tell if word has back to back letters / double chars
    bool double_char = false;
    // store chars to not print yellow twice in word like float with the guess loops. Name is confusing but this stores corect chars ahead of index of guess as well as past correct indices/chars.
    std::string past_printed;

    for (size_t i = 0; i < word.length(); i++)
    {
        // check word for double letter "ee" etc and set double_char to true
        if (word[i] == word[i + 1])
        {
            // std::cout << "double char detected";
            double_char = true;
        }
    }
    // was used for testing the boolean checking if the word had double chars.
    // std::cout << double_char << std::endl;
    for (size_t i = 0; i < guess.length(); i++)
    {
        // checking for correct chars ahead of current char in guess.
        for (size_t s = 1; s < guess.length(); s++)
        {
            if (guess[i + s] == word[i + s])
            {
                // check for double chars in word and guess and if so remove those from the past_printed list which then allows the guess to show up double yellow or green yellow for words.
                if (guess[i + s] == guess[(i + s) - 1] && double_char == true)
                {
                    for (size_t c = 0; c < past_printed.length(); c++)
                    {
                        past_printed.erase(std::remove(past_printed.begin(), past_printed.end(), guess[i]), past_printed.end());
                    }
                }
                // past_printed += guess[i];
                past_printed += guess[i + s];
            }

            // std::cout << past_printed << std::endl;
        }
        // std::cout << past_printed << std::endl;
        if (guess[i] == word[i])
        {
            std::cout << "\033[0;102m" << guess[i] << "\033[0m"; // print green color for correct letters in the right spot
            past_printed += guess[i];
            // check for double chars in word and guess and if so remove those from the past_printed list which then allows the guess to show up double yellow or green yellow for words.
            if (guess[i] == guess[i - 1] && double_char == true)
            {
                for (size_t c = 0; c < past_printed.length(); c++) // for each char in past_printed string remove the char that is a double char in guess.
                {
                    past_printed.erase(std::remove(past_printed.begin(), past_printed.end(), guess[i]), past_printed.end());
                }
            }
        }
        else if (word.find(guess[i]) != std::string::npos && past_printed.find(guess[i]) == std::string::npos)
        {
            // std::cout << past_printed << std::endl;
            //  check for double chars and if the word does not include two letters in a row and print second instance of double char grey. else print yellow
            if (guess[i] == guess[i - 1] && double_char == false)
            {
                std::cout << guess[i];
            }
            else
            {
                std::cout << "\033[0;103m" << guess[i] << "\033[0m"; // print yellow color for correct letters in the word but not in the right spot
            }
        }
        else
        {
            std::cout << guess[i]; // Print grey
        }
        // std::cout << "\033[0m";
    }
    std::cout << std::endl;
}

std::string Game::update_board(std::string &board, std::string &guess, std::string &word)
{
    for (size_t i = 0; i < board.length(); i++)
    {
        if (word[i] == guess[i])
        {
            board[i] = guess[i];
        }
        else
        {
            board[i] = board[i];
        }
    }
    return board;
}
void Game::print_past_guesses(std::string &word)
{
    std::cout << "Past guesses: " << std::endl;
    for (const std::string &guess : past_guesses)
    {
        // std::cout << "\033[47m";
        print_colored_word(word, guess);
        // std::cout << "\033[0m";
        // std::cout << " ";
    }
    std::cout << std::endl;
}

void Game::store_guess(const std::string &guess)
{
    past_guesses.push_back(guess);
}