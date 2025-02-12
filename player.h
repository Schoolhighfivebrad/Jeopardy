#ifndef PLAYER_H
#define PLAYER_H

// Defines the Player structure
struct Player {
    char name[50];
    int score;
};

// Functions for managing players
int setup_players();
void update_score(const char *player_name, int points);
int is_valid_player(const char *player_name);

#endif 
