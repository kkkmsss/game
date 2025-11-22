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

void play_game(void) {

    char board[3][3] = {

        {'1', '2', '3'},
        {'4', '5', '6'},
        {'7', '8', '9'}
    };

    int i;
    for(i = 0; i < MAX_TURN; i++) {

        int m;
        int n;

        for(m = 0; m < 3; m++) {

            for(n = 0; n < 3; n++) {

                printf("%c", board[m][n]);
            }
            printf("\n");
        }
    }
}
