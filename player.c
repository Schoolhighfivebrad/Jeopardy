#include <stdio.h>
#include <string.h>
#include "player.h"
#include "game_data.h"

// Handles player setup, ensuring valid player count (2-4) and unique names
int setup_players() {
    int num_players;
    printf("How many players are playing? (2-4): ");
    scanf("%d", &num_players);
    printf("\n");

    while ((num_players > 4) || (num_players < 2)) {
        printf("\nInvalid number of players.\nHow many players are playing? (2-4): ");
        scanf("%d", &num_players);
        printf("\n");
    }

    for (int i = 0; i < num_players; i++) {
        while (1) {
            printf("Enter name for Player %d: ", i + 1);
            scanf("%s", players[i].name);

            // Check if the name has already been used
            int name_exists = 0;
            for (int j = 0; j < i; j++) {
                if (strcasecmp(players[j].name, players[i].name) == 0) {
                    name_exists = 1;
                    break;
                }
            }

            if (name_exists) {
                printf("This name is already taken. Please choose another name.\n");
            } else {
                players[i].score = 0;
                break;
            }
        }
    }

    return num_players;
}

// Updates the score of the specified player
void update_score(const char *player_name, int points) {
    for (int i = 0; i < MAX_PLAYERS; i++) {
        if (strcasecmp(players[i].name, player_name) == 0) {
            players[i].score += points;
            break;
        }
    }
}

// Checks if a given player name exists in the game
int is_valid_player(const char *player_name) {
    for (int i = 0; i < MAX_PLAYERS; i++) {
        if (strcasecmp(players[i].name, player_name) == 0) {
            return 1;  // Player is valid
        }
    }
    return 0;  // Player not found
}
