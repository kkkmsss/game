#include <stdio.h>
#include "make_game.h"

int main() {
    printf("Let's start Tic-Tac-Toe!!\n");
    int result;
    result = playGame();
    if (result != 0) {
        fprintf(stderr, "Error: Program terminated unexpectedly.\n");
        return 1;
    }    
    return 0;
}