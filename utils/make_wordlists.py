"""
Generate wordlist files using Python and an API.

This script fetches random words in different languages from the Words API and creates wordlist files with words of a specific length.

API Source:
https://random-word-api.herokuapp.com/home

NOTE: Execute this script from the root directory of the project.
(e.g., PS ...\\wordle> python.exe .\\utils\\make_wordlists.py)
"""


import requests
import random


### CONSTANTS ###
WORD_LENGTH = 5

SAVE_LOC = "utils/wordlists"

ENGLISH = "en"
GERMAN = "de"
SPANISH = "es"
ITALIAN = "it"
CHINESE = "zh"
LANGUAGES = [ENGLISH, GERMAN, SPANISH, ITALIAN, CHINESE]

BASE_URL = "https://random-word-api.herokuapp.com/all?lang="


def make_words_file_txt(language):
    """
    Fetches random words in the specified language, filters them by length, and saves them to a text file.

    Args:
        language (str): The language code for the desired word list.
    """

    # get a list of all the words in the passed language in alphabetical order
    response = requests.get(BASE_URL + str(language))

    # Filter out words with the correct length (5) and haven't been added yet
    words = []
    for word in response.json():
        if len(word) == WORD_LENGTH and word.lower() not in words:
            words.append(word.lower())

    # shuffle the words to randomize the order
    random.shuffle(words)

    # save the words to a file
    with open(f"{SAVE_LOC}/words_{language}.txt", "w", encoding="utf-8") as f:
        for word in words:
            # each word is separated by a new line
            try:
                f.write(word + "\n")
            except UnicodeEncodeError:
                pass


def save_words():
    """
    Iterates through the list of supported languages and generates wordlists for each language.
    """

    for language in LANGUAGES:
        make_words_file_txt(language=language)


save_words()
