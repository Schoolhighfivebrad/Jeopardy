#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "question.h"
#include "game_data.h"


// Loads questions from a file and stores them in the questions array
void load_questions() {
    FILE *file = fopen("questions.txt", "r");
    if (!file) {
        printf("Error: Could not open questions file.\n");
        return;
    }

    int i = 0;
    while (fscanf(file, "%49s", questions[i].category) != EOF) {
        char temp[300];
        if (fgets(temp, sizeof(temp), file) == NULL) {
            printf("Error: Unexpected end of file.\n");
            break;
        }

        // Use strtok to split and validate data
        char *question_part = strtok(temp, ">");   // Question part
        char *answer_part = strtok(NULL, ">");      // Answer part
        char *value_part = strtok(NULL, " ");       // Value part

        if (question_part && answer_part && value_part) {
            strcpy(questions[i].question, question_part);
            strcpy(questions[i].answer, answer_part);
            questions[i].value = atoi(value_part);
            questions[i].answered = 0;
            i++;
        } else {
            printf("Warning: Skipping malformed line in questions.txt.\n");
        }

        if (i > MAX_QUESTIONS) {
            printf("Warning: Reached maximum number of questions.\n");
            break;
        }
    }

    fclose(file);
}


// Compares a player's answer with the correct answer
int validate_answer(const char *player_answer, const char *correct_answer) {
    return strcasecmp(player_answer, correct_answer) == 0;
}
