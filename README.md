# Command-Line Jeopardy Game

## Introduction

This is a command-line version of the classic game Jeopardy, developed in C .
 It supports up to four players and follows the traditional Jeopardy format, 
 with questions, categories, and scoring.

## Features

1. Player Management:
   - Supports up to 4 players.
   - Tracks names and scores throughout the game.
2. Interactive Gameplay:
   - Players select categories and dollar amounts.
   - Questions are validated for correctness and tracked to prevent reuse.
   - Answers must follow the "what is" or "who is" format.
3. Score Tracking:
   - Updates player scores based on correct answers.
   - Displays rankings at the end of the game.

## Requirements

- A GCC-compatible C compiler (e.g., GCC or Clang).
- A terminal or command-line interface.

## How to Compile and Run

1. Compile the Code:
   - Open a terminal and navigate to the project directory.
   - Run the following command to compile the game using the provided Makefile:
     
     make
  
   - This will generate an executable named `jeopardy`.

2. Run the Game:
   - Start the game by running the following command:
    
     ./jeopardy

## Gameplay Instructions

1. Setup:
   - The game will prompt each player to enter their name. All names must be unique.
   - Players start with a score of $0.

2. Selecting Questions:
   - The game will display categories and dollar amounts for questions.
   - A player will be prompted to select a category and dollar amount.

3. Answering Questions:
   - The chosen question will be displayed.
   - The player must answer in the format "what is [answer]" or "who is [answer]".
   - If the answer is correct, the player's score will be updated.
   - If incorrect, the correct answer will be displayed, and no points will be awarded.

4. Tracking Progress:
   - The game keeps track of answered questions and prevents them from being reused.
   - Remaining questions and their dollar values are displayed after each turn.

5. Winning the Game:
   - Once all questions have been answered, the game will rank players based on their scores.
   - The player with the highest score wins.
