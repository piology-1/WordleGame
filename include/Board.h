#ifndef BOARD_H
#define BOARD_H

#include <iostream>
#include <vector>
#include <string>
#include <cctype>
#include <algorithm> // for std::find

#include "constants.h"

#define EMPTY_FIELD '#';

struct Field
{
    char character; // The character of the field

    enum State // Enum to represent the state of the field
    {
        empty,            // The field is empty from initialization
        correct_position, // The character is in the correct position of the searched word
        in_word,          // The character is in the word but currently not in the correct position
        not_in_word       // The character is not in the word
    };

    State state; // The state of the field
};

class Board
{
private:
    std::vector<std::vector<Field>> cells; // Stores the content of each cell on the board

    std::string get_fg_color(const Field::State &state) const;
    bool char_in_word(const char &c, const std::string &word) const;

public:
    // Default constructor to create an empty board.
    Board();

    void reset();
    void set_word(const int &row, const std::string &word, const std::string &searched_word);
    void print_board() const;
};

#endif
