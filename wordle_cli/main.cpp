#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <algorithm>
#include "game.h"

using namespace std;

int main()
{
    const int word_len = 5;
    const int max_guesses = 6;
    vector<string> past_guess;

    Game c;

    string board = c.create_board(word_len);

    vector<string> lines = c.read_dict();

    srand(time(nullptr));

    int rand_index = rand() % lines.size();

    string word = lines[rand_index];
    cout << "----------------" << endl;
    cout << "Welcome to Wordle!" << endl;
    // uncomment for testing.
    // cout << word << endl;
    cout << "----------------" << endl;

    int guesses_remaining = max_guesses;

    while (guesses_remaining > 0)
    {
        string guess;
        cout << "Board State: " << endl;
        cout << "*****************" << endl;
        cout << board << endl;
        cout << "*****************" << endl;
        c.print_colored_word(word, guess);
        c.print_past_guesses(word);
        cout << "Enter your guess (a five letter word): ";
        cin >> guess;

        if (guess == "!quit")
        {
            cout << "User terminated the program." << endl;
            break;
        }

        if (guess.length() == word.length() && std::find(lines.begin(), lines.end(), guess) != lines.end())
        {

            c.store_guess(guess);
            
            if (c.is_guess_correct(guess, word))
            {

                board = c.update_board(board, guess, word);
                if (guess == word)
                {
                    c.print_past_guesses(word);
                    cout << "Congratulations! You guessed the word: " << word << " in only " << (max_guesses - guesses_remaining+1) << " guesses." << endl;
                    break;
                }
            }
            guesses_remaining--;
            cout << "----------------" << endl;
            cout << "guesses remaining: " << guesses_remaining << endl;
            cout << "----------------" << endl;
            if (guesses_remaining == 0)
            {
                c.print_past_guesses(word);
                cout << "Sorry, you ran out of guesses. The word was: " << word << endl;
                break;
            }

        }
        else if (guess == "!print")
        {

            cout << "Word is: " << word << endl;
        }
        else if (guess == "!float")
        {
            word = "float";
            cout << "Word is: " << word << endl;
        }
        else if (guess == "!deads")
        {
            word = "deads";
            cout << "Word is: " << word << endl;
        }
        else if (guess == "!feeds")
        {
            word = "feeds";
            cout << "Word is: " << word << endl;
        }
        else if (guess == "!sizes")
        {
            word = "sizes";
            cout << "Word is: " << word << endl;
        }
        else
        {
            cout << "Invalid guess (word might not be in word list). Please enter a word " << word.length() << " letters in length." << endl;
        }
    }

    return 0;
}
