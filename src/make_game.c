#include "make_game.h"

void outputBoard(char board[ROWS][COLS]) {
    int i;
    for (i = 0; i < ROWS; i++) {
        int j;
        for (j = 0; j < COLS; j++) {
            if (board[i][j] == 'O') {
                printf("\x1b[31m%c\x1b[0m ", board[i][j]); // 赤でO
            } else if (board[i][j] == 'X') {
                printf("\x1b[34m%c\x1b[0m ", board[i][j]); // 青でX
            } else {
                printf("%c ", board[i][j]); // 数字はデフォ色
            }            
        }
        printf("\n");
    }
}

void convBoard(char board[ROWS][COLS], char mark) {
    char input;
    printf("Select number: ");
    scanf(" %c", &input);
    int i;
    for (i = 0; i < ROWS; i++) {
        int j;
        for (j = 0; j < COLS; j++) {
            if (input == board[i][j]) {
                board[i][j] = mark;
            }
        }
    }
}

void outputResultDrow(void) {
    printf("Drow!!\n");
}

void outputMassage(void) {
    printf("Choose a number to place your mark: \n");
}

int checkRowsWin(char board[ROWS][COLS], char mark) {
    
}

int checkColsWin(char board[ROWS][COLS], char mark) {

}

int checkCrossWin(char board[ROWS][COLS], char mark) {

}

int checkWin(char board[ROWS][COLS], char mark) {
    if (checkRowsWin(board, mark) == 1) {
        return 1;
    }

    if (checkColsWin(board, mark) == 1) {
        return 1;
    }

    if (checkCrossWin(board, mark) == 1) {
        return 1;
    }
    return 0;
}

void winingMessage(char mark) {
    if (mark == 'O') {
        printf("Winner: \x1b[31m%c\x1b[0m ", mark);
    }
    if (mark == 'X') {
        printf("Winner: \x1b[34m%c\x1b[0m ", mark);
    }    
}

void playGame(void) {
    char board[ROWS][COLS] = {
        {'1', '2', '3'},
        {'4', '5', '6'},
        {'7', '8', '9'}
    };    
    int turn = 0;
    int i;
    for (i = 0; i < MAX_TURN; i++) {
        outputMassage();
        outputBoard(board);
        if (turn % 2 == 0) {
            convBoard(board, 'O');
            if (turn >= MIN_TURN_TO_WIN) {
                if (checkWin(board, 'O') == 1) {
                    winingMessage('O');
                    break;
                }
            }
            turn = turn + 1;
        } else {
            convBoard(board, 'X');
            if (turn >= MIN_TURN_TO_WIN) {
                if (checkWin(board, 'X') == 1) {
                    winingMessage('X');
                    break;
                }
            }
            turn = turn + 1;
        }
        outputBoard(board);        
    }
    outputResultDrow();
}
