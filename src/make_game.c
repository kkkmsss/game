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
    if (board[0][0] == mark && board[0][1] == mark && board[0][2] == mark) {        
        return 1;
    }
    if (board[1][0] == mark && board[1][1] == mark && board[1][2] == mark) {
        return 1;
    }
    if (board[2][0] == mark && board[2][1] == mark && board[2][2] == mark) {
        return 1;
    }
    return 0;
}

int checkColsWin(char board[ROWS][COLS], char mark) {
    if (board[0][0] == mark && board[1][0] == mark && board[2][0] == mark) {        
        return 1;
    }
    if (board[0][1] == mark && board[1][1] == mark && board[2][1] == mark) {
        return 1;
    }
    if (board[0][2] == mark && board[1][2] == mark && board[2][2] == mark) {
        return 1;
    }
    return 0;
}

int checkCrossWin(char board[ROWS][COLS], char mark) {
    if (board[0][0] == mark && board[1][1] == mark && board[2][2] == mark) {        
        return 1;
    }    
    if (board[2][0] == mark && board[1][1] == mark && board[0][2] == mark) {
        return 1;
    }
    return 0;
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
        printf("Winner: \x1b[31m%c\x1b[0m \n", mark);
    }
    if (mark == 'X') {
        printf("Winner: \x1b[34m%c\x1b[0m \n", mark);
    }    
}

int playGame(void) {
    char board[ROWS][COLS] = {
        {'1', '2', '3'},
        {'4', '5', '6'},
        {'7', '8', '9'}
    };       
    int i;
    for (i = 0; i < MAX_TURN; i++) {
        outputMassage();
        outputBoard(board);
        if (i % 2 == 0) {
            convBoard(board, 'O');
            if (i + 1 >= MIN_TURN_TO_WIN) {
                if (checkWin(board, 'O') == 1) {                    
                    outputBoard(board);
                    winingMessage('O');
                    return 0;
                }
            }
        } else {
            convBoard(board, 'X');
            if (i + 1 >= MIN_TURN_TO_WIN) {
                if (checkWin(board, 'X') == 1) {
                    outputBoard(board);
                    winingMessage('X');                    
                    return 0;
                }
            }
        }
        outputBoard(board);
    }    
        outputResultDrow();
        return 0;    
}
