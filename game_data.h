#ifndef GAME_DATA_H
#define GAME_DATA_H

// Include necessary header files
#include "player.h"
#include "question.h"

// Define maximum limits for players and questions in the game
#define MAX_PLAYERS 4
#define MAX_QUESTIONS 30

// Declare external arrays for storing player and question data
extern struct Player players[MAX_PLAYERS];   
extern struct Question questions[MAX_QUESTIONS];  

#endif
