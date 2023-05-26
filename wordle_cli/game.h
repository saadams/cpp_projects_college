#ifndef GAME_H
#define GAME_H
#include <string>
#include <vector>

class Game
{

private:
    std::vector<std::string> past_guesses;
public:
    std::vector<std::string> read_dict();
    std::string create_board(int word_len);
    bool is_guess_correct(std::string word, std::string guess);
    void print_colored_word(const std::string& word, const std::string& current);
    void print_past_guesses(std::string &word); 
    void store_guess(const std::string& guess);
    std::string update_board(std::string &board, std::string& guess, std::string &word);

};

#endif