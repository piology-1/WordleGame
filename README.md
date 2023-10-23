# Wordle Game

Wordle Game is a terminal-based word guessing game with the potential for future expansion to fetch random words via an API using the cURL library. It currently just offers word lists in several languages for an offline gaming experience.

## Features

- C++ implementation of the Wordle game.
- Interactive terminal application with visualisation
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

1. Select an option from the main menu.
2. Take a look at the 
Allow the program to solve or visualize the puzzle.
Explore various functions of the Sudoku Solver using the options provided.

## Generating Word Lists

You can use the Python script in [utils/make_wordlists.py](utils/make_wordlists.py) to generate word lists from an API. The generated lists are stored as text files in the [utils/wordlists](utils/wordlists) directory. To generate or regenerate the lists, execute the python script within the main project directory:

To generate or regenerate the word lists, open a terminal in the main project directory (e.g., `C:\Path\to\the\project\directory\wordle`), and then run the following command:

1. Change the directory to the main project directory:

```bash
cd C:\Path\to\the\project\directory\wordle
```

2. Run the Python script:

```bash
python.exe .\utils\make_wordlists.py
```

NOTE: You may need to use `python3` to execute the script if you are using MacOS or Linux.
