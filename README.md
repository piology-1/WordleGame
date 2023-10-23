# Wordle Game

Wordle Game is a terminal-based word guessing game with the potential for future expansion to fetch random words via an API using the cURL library. It currently just offers word lists in several languages for an offline gaming experience.

## Features

- C++ implementation of the Wordle game.
- Interactive terminal application with visualisation.
- Support for guessing 5 letter words.
- Game available in multiple languages.
- Python script to generate word lists from an API [python script](utils/make_wordlists.py).
- Extensible to other languages or features.
- Extensible to add definition and other information about the guessed word in the future using another API.

## Available Languages

- English
- German
- Spanish
- Italian
- Chinese

Feel free to extend the game or add word lists for additional languages as needed.

## Usage

Here are some basic steps for using the Wordle game:

1. Choose an option from the main menu.
2. Take a look at the "Instructions and Rules" to familiarise yourself with the rules.
3. Change the language of the wordle words by following the instructions.
4. Play a Wordle game in your chosen language (default is English) and receive a new random word each time you select the "Start a new game" option.

## Installation

You can clone this project from GitHub and run it locally. Make sure you have the required dependencies installed.

```bash
git clone git clone https://github.com/piology-1/WordleGame.git
cd WordleGame
```

## Generating Word Lists

You can use the Python script in [utils/make_wordlists.py](utils/make_wordlists.py) to generate word lists from an API. The generated lists are stored as text files in the [utils/wordlists](utils/wordlists) directory. To generate or regenerate the lists, execute the python script within the main project directory:

To generate or regenerate the word lists, open a terminal in the main project directory (e.g., `C:\Path\to\the\project\directory`), and then run the following command:

1. Change the directory to the main project directory:

```bash
cd C:\Path\to\the\project\directory
```

2. Run the Python script:

```bash
python.exe .\utils\make_wordlists.py
```

NOTE: You may need to use `python3` to execute the script if you are using MacOS or Linux.

## Helpful Links and Documentation

Here are some useful links and documentation for further information and resources:

- Random Word API (https://random-word-api.herokuapp.com/home):
  This API is used to generate the [utils/wordlists](utils/wordlists) and can be used for fetching random words.

- Free Dictionary API (https://dictionaryapi.dev/):
  The Free Dictionary API can be utilized for adding features like word definitions, synonyms, or related information about the guessed word.
