#include <stdio.h>
#include <string.h>
#include "game.h"
#include "player.h"
#include "question.h"
#include "game_data.h"

struct Player players[MAX_PLAYERS];
struct Question questions[MAX_QUESTIONS];


int initialize_game() {
    load_questions();
    return setup_players();
}

// Start the game loop
void start_game(int num_players) {
    int remaining_questions = MAX_QUESTIONS;
    char player_name[50];
    char category[50];
    int value;
    int found;

    while (remaining_questions > 0) {
        printf("\nCurrent Scores:\n");
        for (int i = 0; i < num_players; i++) {
            printf("%s: $%d\n", players[i].name, players[i].score);
        }

        // Ask for the player who will select the category and question
        printf("\nEnter the player name who will choose: ");
        scanf("%s", player_name);

        // Validate player name
        if (!is_valid_player(player_name)) {
            printf("Invalid player name! Try again.\n");
            continue;
        }

        printf("Available categories:\n");
        for (int i = 0; i < MAX_QUESTIONS; i++) {
            if (!questions[i].answered) {
                printf("- %s ($%d)\n", questions[i].category, questions[i].value);
            }
        }


        // Ask for category and question value
        printf("Enter category: ");
        scanf("%s", category);

        printf("Enter question value: ");
        scanf("%d", &value);

        // Validate if the question exists and hasn't been answered
        found = 0;
        for (int i = 0; i < MAX_QUESTIONS; i++) {
            if (strcasecmp(questions[i].category, category) == 0 && questions[i].value == value && !questions[i].answered) {
                found = 1;

                // Display the question
                printf("\nQuestion: %s\n", questions[i].question);

                // Get and validate the player's answer
                char player_answer[255];
                printf("Enter your answer (start with 'what is' or 'who is'): ");
                getchar();  // Clear newline from previous input
                fgets(player_answer, sizeof(player_answer), stdin);

                // Remove newline character from the answer
                player_answer[strcspn(player_answer, "\n")] = '\0';

                if (validate_answer(player_answer, questions[i].answer)) {
                    printf("Correct!\n");
                    update_score(player_name, value);
                } else {
                    printf("Incorrect! The correct answer was: %s\n", questions[i].answer);
                }

                // Mark the question as answered
                questions[i].answered = 1;
                remaining_questions--;
                break;
            }
        }

        if (!found) {
            printf("Invalid category or question value, or question already answered. Try again.\n");
        }
    }

    printf("\nAll questions have been answered! Game over.\n");
}


void print_final_scores() {
    // Sort players by score (descending order)
    struct Player temp;
    for (int i = 0; i < MAX_PLAYERS - 1; i++) {
        for (int j = i + 1; j < MAX_PLAYERS; j++) {
            if (players[j].score > players[i].score) {
                // Swap players[i] and players[j]
                temp = players[i];
                players[i] = players[j];
                players[j] = temp;
            }
        }
    }

    // Print final scores
    printf("\nFinal Scores:\n");
    for (int i = 0; i < MAX_PLAYERS; i++) {
        printf("%d. %s: $%d\n", i + 1, players[i].name, players[i].score);
    }

    // Announce the winner
    printf("\nThe winner is %s with $%d!\n", players[0].name, players[0].score);
}

