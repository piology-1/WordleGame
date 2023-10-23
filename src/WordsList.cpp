#include "../include/WordsList.h"

WordsList::WordsList()
{
    // Initialize and seed the random number generator with the current time once in the constructor
    std::srand(static_cast<unsigned>(std::time(nullptr)));

    default_w_list = {
        "apple",
        "beach",
        "cloud",
        "drink",
        "funky",
        "grape",
        "happy",
        "juice",
        "lemon",
        "music",
        "ocean",
        "piano",
        "quick",
        "rider",
        "sunny",
        "train",
        "vivid",
        "water",
        "xerox",
        "zebra"};
}

std::string WordsList::word_from_api() const
{
    return std::string();
}

std::string WordsList::word_from_wordlist_txt() const
{
    std::vector<std::string> word_list;
    std::string file = WORDLISTS_PATH + "words_" + curr_lang + ".txt";
    // std::string file = std::filesystem::current_path() / WORDLISTS_PATH / ("wordlist_" + curr_lang + ".txt");
    std::ifstream inputFile(file); // Open the text file

    if (inputFile.is_open())
    {
        std::string word;

        while (std::getline(inputFile, word))
            word_list.push_back(word);

        inputFile.close(); // Close the file
    }
    else
    {
        std::cerr << "Error opening the file." << std::endl;
        return ""; // Return empty string
    }

    // Choose a random word from the list
    // int random_index = std::rand() % word_list.size();
    // std::string random_word = word_list[std::rand() % word_list.size()];

    return std::string(word_list[std::rand() % word_list.size()]);
}

std::string WordsList::get_random_word() const
{

    std::string r_word = "";

    // try to get a random word from the API
    try
    {
        r_word = word_from_api();
    }
    catch (const std::out_of_range &e)
    {
        // Handle the exception here, if needed
    }

    // If no exception was thrown or after handling the exception
    if (r_word.empty())
    {
        // If r_word is empty, meaning an error occurred while trying to get a word from the API
        // Return a random word from the list or "pizza" as a default
        r_word = word_from_wordlist_txt();

        if (r_word.empty())
        {
            r_word = default_w_list[std::rand() % default_w_list.size()];

            if (r_word.empty())
                r_word = "pizza"; // default to "pizza" if all else fails
        }
    }

    return r_word;
}

void WordsList::add_word(const std::string &word)
{
    if (Wordle::is_valid_word(word))
        default_w_list.push_back(word);
    else
        throw std::invalid_argument("Invalid word: " + word);
}

void WordsList::clear()
{
    this->default_w_list.clear();
}

void WordsList::print_list() const
{
    int cnt = 1;
    for (auto &word : default_w_list)
    {
        std::cout << cnt << ". " << word << std::endl;
        cnt++;
    }
}

void WordsList::set_language(const std::string &language)
{
    curr_lang = language;
}

std::string WordsList::get_language() const
{
    return std::string(curr_lang);
}

/*
#include <iostream>
#include <string>
#include <curl/curl.h>

size_t WriteCallback(void *contents, size_t size, size_t nmemb, std::string *output) {
    size_t total_size = size * nmemb;
    output->append(static_cast<char *>(contents), total_size);
    return total_size;
}

int main() {
    CURL *curl;
    CURLcode res;
    std::string response;

    curl = curl_easy_init();
    if (curl) {
        curl_easy_setopt(curl, CURLOPT_URL, "https://api.example.com/getRandomWord");
        curl_easy_setopt(curl, CURLOPT_WRITEFUNCTION, WriteCallback);
        curl_easy_setopt(curl, CURLOPT_WRITEDATA, &response);
        res = curl_easy_perform(curl);
        curl_easy_cleanup(curl);

        if (res != CURLE_OK) {
            std::cerr << "Error: " << curl_easy_strerror(res) << std::endl;
            return 1;
        }

        std::cout << "Random word: " << response << std::endl;
    }

    return 0;
}
*/