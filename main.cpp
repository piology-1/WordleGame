#include <iostream>
// #include <curl/curl.h>
#include "include/Game.h"

// // TODO: Make it available for different languages
// // Make the word length variable (not only 5)
// // Make the guesses amount variable (not only 5)
// // Add Word definition?
// // ADD fortunes text/ quotes

int main()
{
    std::cout << " === WORDLE GAME === \n"
              << std::endl;

    Game game;
    game.run();

    return 0;
}

// #include <iostream>
// #include <string>
// #include <curl/curl.h>

// size_t WriteCallback(void *contents, size_t size, size_t nmemb, std::string *output)
// {
//     size_t total_size = size * nmemb;
//     output->append(static_cast<char *>(contents), total_size);
//     return total_size;
// }

// int main()
// {
//     CURL *curl;
//     CURLcode res;
//     std::string response;

//     curl = curl_easy_init();
//     if (curl)
//     {
//         curl_easy_setopt(curl, CURLOPT_URL, "https://amazon.com");
//         curl_easy_setopt(curl, CURLOPT_WRITEFUNCTION, WriteCallback);
//         curl_easy_setopt(curl, CURLOPT_WRITEDATA, &response);
//         res = curl_easy_perform(curl);
//         curl_easy_cleanup(curl);

//         if (res != CURLE_OK)
//         {
//             std::cerr << "Error: " << curl_easy_strerror(res) << std::endl;
//             return 1;
//         }

//         std::cout << "Random word: " << response << std::endl;
//     }

//     return 0;
// }