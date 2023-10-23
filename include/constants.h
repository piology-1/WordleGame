#ifndef CONSTANTS_H
#define CONSTANTS_H

#include <string>

#ifdef _WIN32
#define CLEAR "cls"
#else
#define CLEAR "clear"
#endif

/// WORDLE CONSTANTS
const int MAX_ATTEMPTS = 5;
const int WORD_LENGTH = 5;

/// BOARD CONSTANTS
const int BOARD_SIZE = 5;   // 5 rows, 5 columns
const int BOARD_WIDTH = 21; // characters
const int CHAR_WIDTH = 3;   // characters
const char H_SPACE = '-';
const char V_SPACE = '|';
const std::string H_LINE(BOARD_WIDTH, H_SPACE);

/// ANSI color-coded strings fpr the terminal/console
const std::string STANDARD_FOREGROUND = "\033[0m"; // Reset to standard colors
const std::string GREY_FOREGROUND = "\033[38;5;240m";
const std::string GREEN_FOREGROUND = "\033[92m";
const std::string YELLOW_FOREGROUND = "\033[93m";

/*
Words API to get random englisch wordsetc.
URL: https://random-word-api.herokuapp.com/home
Request to: WORD_URL = "https://random-word-api.herokuapp.com/word?length=5"
--> returns a random word wioth 5 characters

Get definitions etc. from dictionary API
URL:https://dictionaryapi.dev/
Request to: DICT_URL = "https://api.dictionaryapi.dev/api/v2/entries/en/hello"
--> returns definitions and other stuff about the passed word (here it is "hello")
*/

#define ENGLISH "en"
#define GERMAN "de"
#define SPANISH "es"
#define ITALIAN "it"
#define CHINESE "zh"

const std::string LANGUAGES[] = {ENGLISH, GERMAN, SPANISH, ITALIAN, CHINESE};

#endif // CONSTANTS_H
