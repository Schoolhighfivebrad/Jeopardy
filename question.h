#ifndef QUESTION_H
#define QUESTION_H

// Defines the structure for storing question details
struct Question {
    char category[50];
    char question[255];
    char answer[50];
    int value;
    int answered;
};

// Function prototypes for handling questions
void load_questions(); // Loads questions from a file
int validate_answer(const char *player_answer, const char *correct_answer); // Checks if an answer is correct

#endif 
