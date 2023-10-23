#ifndef WORDSLIST_H
#define WORDSLIST_H

#include <iostream>
#include <vector>
#include <string>
#include <random>
#include <fstream>
#include <cstdlib>
#include <ctime>
#include <filesystem>

#include "constants.h"
#include "Wordle.h"

class WordsList
{
private:
    std::vector<std::string> default_w_list;

    std::string curr_lang = ENGLISH;

    // API URLS
    std::string word_url = "https://random-word-api.herokuapp.com/word?lang=" + curr_lang + "&length=" + std::to_string(WORD_LENGTH);
    std::string dict_url = "https://api.dictionaryapi.dev/api/v2/entries/" + curr_lang + "/" + std::to_string(WORD_LENGTH);

    // WORDLISTS PATH
    std::string WORDLISTS_PATH = "C:/Users/piusg/OneDrive/Programming/C_C++_projects/wordle/utils/wordlists/";

    std::string word_from_wordlist_txt() const;
    std::string word_from_api() const;

public:
    WordsList();

    void set_language(const std::string &language);
    std::string get_language() const;

    void add_word(const std::string &word);

    std::string get_random_word() const;
    std::string get_word_data() const;
    void clear();
    void print_list() const;
};

#endif
