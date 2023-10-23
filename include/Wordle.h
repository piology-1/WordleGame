#ifndef WORDLE_H
#define WORDLE_H

#include <iostream>
#include <string>
#include <array>
#include <typeinfo>
#include <limits>

#include "constants.h"
#include "Board.h"

class Wordle
{
private:
    Board board;

    int attempt_cnt = 0;
    std::array<std::string, MAX_ATTEMPTS> entered_words;
    std::string searched_word;

    bool already_entered(const std::string &word) const;
    bool check_word(const std::string &word);

public:
    Wordle();
    bool word_guessed = false;

    void reset();
    static bool is_valid_word(const std::string &word); // static method, indicating that the method is associated with the class as a whole, not just with instances of the class.
    bool enter_word();
    void set_searched_word(const std::string &word);
    std::string get_searched_word() const;
    const int get_attempt_cnt() const;
    const Board &get_board() const; // returned value is constant and can't be changed
};

#endif // WORDLE_H
