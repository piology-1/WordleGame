#include "../include/Board.h"

Board::Board()
{
    // Initialize an empty board
    reset();
}

void Board::reset()
{
    // Resize the cells vector to match the dimensions of the board and create a Field object for each cell
    cells.resize(BOARD_SIZE, std::vector<Field>(BOARD_SIZE));

    // Initialize/fill the board with empty fields
    for (int row = 0; row < BOARD_SIZE; row++)
    {
        for (int col = 0; col < BOARD_SIZE; col++)
        {
            // Set each cell to an empty field
            cells[row][col].character = EMPTY_FIELD;
            cells[row][col].state = Field::empty;
        }
    }
}

bool Board::char_in_word(const char &c, const std::string &word) const
{
    return std::find(word.begin(), word.end(), c) != word.end();
}

void Board::set_word(const int &row, const std::string &word, const std::string &searched_word)
{
    // Put the word on the board and mark the fields / cells (characters) in the correct way.
    for (int col = 0; col < WORD_LENGTH; col++)
    {
        cells[row][col].character = std::toupper(word[col]);

        if (word[col] == searched_word[col])
            cells[row][col].state = Field::correct_position;

        else if (char_in_word(word[col], searched_word))
            cells[row][col].state = Field::in_word;

        else
            cells[row][col].state = Field::not_in_word;
    }
}

std::string Board::get_fg_color(const Field::State &state) const
{
    std::string fg_color = STANDARD_FOREGROUND;

    switch (state)
    {
    case Field::State::empty:
        fg_color = STANDARD_FOREGROUND;
        break;

    case Field::State::not_in_word:
        fg_color = GREY_FOREGROUND;
        break;

    case Field::State::in_word:
        fg_color = YELLOW_FOREGROUND;
        break;

    case Field::State::correct_position:
        fg_color = GREEN_FOREGROUND;
        break;

    default:
        fg_color = STANDARD_FOREGROUND;
        break;
    }

    return std::string(fg_color);
}

void Board::print_board() const
{
    /*
    EMPTY BOARD:

    ---------------------
    | # | # | # | # | # |
    ---------------------
    | # | # | # | # | # |
    ---------------------
    | # | # | # | # | # |
    ---------------------
    | # | # | # | # | # |
    ---------------------
    | # | # | # | # | # |
    ---------------------
    */

    // Display the board in the console
    for (int row = 0; row < BOARD_SIZE; row++)
    {
        std::cout << H_LINE << std::endl;

        for (int col = 0; col < BOARD_SIZE; col++)
        {
            char c = cells[row][col].character;
            Field::State char_state = cells[row][col].state;

            std::string foreground_color = get_fg_color(char_state);

            std::cout << V_SPACE << foreground_color << " " << c << " " << STANDARD_FOREGROUND;
        }
        std::cout << V_SPACE << "\n";
    }
    std::cout << H_LINE << std::endl;
}
