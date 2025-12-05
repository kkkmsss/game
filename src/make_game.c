#include "make_game.h"

// int decide_turn(void) {

//     srand((unsigned int)time(NULL));

//     int random_value = rand() % 2;

//     if(random_value == 0) {

//         printf("The draw is done. You're the first player!");

//     } else {

//         printf("The draw is done. You're the second player!");
//     }
//     return random_value;
// }

// player_turn() {


// }

// opponent_turn() {
// }

void outputBord(char board[ROWS][COLS]) {
    int i;
    for (i = 0; i < ROWS; i++) {
        int j;
        for (j = 0; j < COLS; j++) {
            printf("%c ", board[i][j]);
        }
        printf("\n");
    }
}

void convBord(char board[ROWS][COLS], int input) {

}

void playGame(void) {
    char board[ROWS][COLS] = {
        {'1', '2', '3'},
        {'4', '5', '6'},
        {'7', '8', '9'}
    };
    outputBord(board);
}
