#include "../include/Game.h"

Game::Game()
{
}

void Game::change_wordle_language()
{
    std::cout << "Settings - Change language for Wordle words" << std::endl;
    std::cout << "==========================================\n\n";

    std::string lang = words_list.get_language();
    std::cout << "Currently selected language: " << lang << std::endl;

    // Define language options as an array
    std::array<std::string, 5> lang_options = {"English", "German", "Spanish", "Italian", "Chinese"}; // Same Order as LANGUAGES in constants.h
    const int num_options = lang_options.size();

    // Display language options
    for (int i = 0; i < num_options; ++i)
        std::cout << "   " << i + 1 << ". " << lang_options[i] << "\t(" << LANGUAGES[i] << ")" << std::endl;

    std::cout << "   0. Quit" << std::endl;

    int choice = 0;
    std::cout << "Your choice: ";
    if (!(std::cin >> choice) || choice <= 0 || choice > num_options)
    {
        std::cin.clear();
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
        lang = ENGLISH; // Set a default language on invalid input
    }
    else
        lang = LANGUAGES[choice - 1];

    words_list.set_language(lang);
    std::cout << "\nThe language is set to " << lang_options[choice - 1] << " (" << LANGUAGES[choice - 1] << ")"
              << "!\n\n";
    std::cout << STANDARD_FOREGROUND; // Reset text color and formatting to default if  ANSI escape codes being used accidentally

    wait_for_user_continue();
    system(CLEAR);
}

void Game::print_help() const
{
    std::cout << "Welcome to Wordle! - Instructions and Rules" << std::endl;
    std::cout << "===========================================\n\n";
    std::cout << "Wordle is a word-guessing game where you try to guess a hidden word within a limited number of attempts." << std::endl;

    std::cout << "Here's what the colors mean:\n"
              << std::endl;
    std::cout << GREEN_FOREGROUND << "Green\t" << STANDARD_FOREGROUND << " - The letter is in the correct position." << std::endl;
    std::cout << YELLOW_FOREGROUND << "Yellow\t" << STANDARD_FOREGROUND << " - The letter is in the word but in the wrong position." << std::endl;
    std::cout << GREY_FOREGROUND << "Grey\t" << STANDARD_FOREGROUND << " - The letter is not in the word." << std::endl;

    std::cout << "\nYou have a limited number of " << MAX_ATTEMPTS << " to guess the hidden word. Good luck!\n\n";

    wait_for_user_continue();
    system(CLEAR);
}

void Game::print_game_result()
{
    system(CLEAR);
    board.print_board();
    std::cout << "\n";

    if (wordle.word_guessed)
    {
        std::cout << "Congratulations, you have won!\n";
        std::cout << "You have guessed the word '" << wordle.get_searched_word() << "' with " << wordle.get_attempt_cnt() << " tries\n";
    }
    else
    {
        std::cout << "No more tries - you lose!\n";
        std::cout << "The word was: " << wordle.get_searched_word() << "\n";
    }

    wordle.reset();
    std::cout << "\n";
}

void Game::wordle_game()
{
    try
    {
        wordle.set_searched_word(words_list.get_random_word());
    }
    catch (const std::invalid_argument &e)
    {
        std::cerr << e.what() << '\n';
        wait_for_user_continue();
        system(CLEAR);
        return;
    }

    while (wordle.get_attempt_cnt() < MAX_ATTEMPTS)
    {
        try
        {
            if (wordle.enter_word())
                break;
        }
        catch (const std::invalid_argument &e)
        {
            std::cerr << e.what() << '\n';
            wait_for_user_continue();
        }
    }

    print_game_result();
}

void Game::run()
{
    system(CLEAR); // Clear the terminal
    bool is_running = true;

    while (is_running)
    {
        int choice;

        std::cout << "### Wordle - Main Menu ###" << std::endl;
        std::cout << "1. Instructions and Rules" << std::endl;
        std::cout << "2. Change Language of Wordle words" << std::endl;
        std::cout << "3. Start a New Game" << std::endl;
        std::cout << "0. Quit" << std::endl;

        std::cout << "Your choice: ";
        if (!(std::cin >> choice))
        {
            std::cin.clear();                                                   // Clear the error state
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n'); // Discard the invalid input
            choice = -1;                                                        // Set a value to get into the "default" case of the switch
        }
        system(CLEAR);

        switch (choice)
        {
        case 1:
            print_help();

            break;
        case 2:
            change_wordle_language();

            break;
        case 3:
            wordle_game();

            break;

        case 0:
            is_running = false; // Quit the game

            std::cout << "\nThank you for playing my Wordle game - Bye!\n"
                      << std::endl;

            break;

        default:
            std::cout << "Invalid choice. Please choose again.\n\n";
        }
    }
}

void Game::wait_for_user_continue() const
{
    std::cout << "Press any key to continue...";
    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
    std::cin.get();
}