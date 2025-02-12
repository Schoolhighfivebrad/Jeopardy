#include "game.h"
#include "player.h"
#include "question.h"
#include "game_data.h"

// Main function that initializes and starts the Jeopardy game
int main() {
    start_game(initialize_game());
    print_final_scores();
    return 0;
}
