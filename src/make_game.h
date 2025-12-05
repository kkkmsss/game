#ifndef MAKE_GAME_H
#define MAKE_GAME_H

#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <time.h>

#define MAX_TURN 9
#define ROWS 3
#define COLS 3
#define MIN_TURN_TO_WIN 5

// gcc src/main.c src/make_game.c -o game

void outputMassage(void);
void outputBoard(char board[ROWS][COLS]);
void convBoard(char board[ROWS][COLS], char mark);
void outputResultDrow(void);
int checkWin(char board[ROWS][COLS], char mark);
int checkRowsWin(char board[ROWS][COLS], char mark);
int checkColsWin(char board[ROWS][COLS], char mark);
int checkCrossWin(char board[ROWS][COLS], char mark);
void winingMessage(char mark);
void playGame(void);

#endif // MAKE_GAME_H