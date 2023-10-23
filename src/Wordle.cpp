#include "../include/Wordle.h"

Wordle::Wordle()
{
}

bool Wordle::enter_word()
{
    system(CLEAR);

    std::cout << "### Enter your words/guesses ###\n"
              << std::endl;
    board.print_board();

    std::string new_word;
    std::cout << "Enter your " << attempt_cnt + 1 << ". word: ";
    std::cin >> new_word;

    if (!Wordle::is_valid_word(new_word))
        throw std::invalid_argument("Invalid word: '" + new_word + "'");

    // NOTE: This check is not part of the original Wordle implementation.
    if (already_entered(new_word))
        throw std::invalid_argument("Word '" + new_word + "' already entered.");

    entered_words[attempt_cnt] = new_word;
    board.set_word(attempt_cnt, new_word, searched_word);
    board.print_board();
    attempt_cnt++;

    return check_word(new_word);
}

bool Wordle::check_word(const std::string &word)
{
    if (word == searched_word)
    {
        word_guessed = true;
        return true;
    }

    word_guessed = false;
    return false;
}

bool Wordle::already_entered(const std::string &word) const
{
    for (const auto &entered_word : entered_words)
        if (entered_word == word)
            return true;

    return false;
}

bool Wordle::is_valid_word(const std::string &word)
{
    if ((word.length() == WORD_LENGTH) && (typeid(word) == typeid(std::string)))
        return true;
    else
        return false;
}

void Wordle::set_searched_word(const std::string &word)
{
    if (!Wordle::is_valid_word(word))
        throw std::invalid_argument("Invalid word: " + word);

    searched_word = word;
}

std::string Wordle::get_searched_word() const
{
    return std::string(searched_word);
}

const int Wordle::get_attempt_cnt() const
{
    return attempt_cnt;
}

const Board &Wordle::get_board() const
{
    return board;
}

void Wordle::reset()
{
    board.reset();
    attempt_cnt = 0;
    entered_words.fill("");
    searched_word = "";
    word_guessed = false;
}