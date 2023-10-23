#ifndef Game_H
#define Game_H

#include <iostream>

#include "WordsList.h"
#include "Wordle.h"
#include "Board.h"

class Game
{
private:
    WordsList words_list;
    Wordle wordle;
    const Board &board = wordle.get_board();

    void change_wordle_language();
    void print_help() const;
    void wordle_game();
    void print_game_result();
    void wait_for_user_continue() const;

public:
    Game();

    void run();
};

#endif
