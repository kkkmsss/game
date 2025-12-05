#ifndef MAKE_GAME_H
#define MAKE_GAME_H

#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <time.h>

#define MAX_TURN 8
#define ROWS 3
#define COLS 3

// gcc src/main.c src/make_game.c -o game

// int decide_turn(void);
void outputBord(char board[ROWS][COLS]);
void convBord(char board[ROWS][COLS], int input);
void playGame(void);
// void player_turn(void);
// void opponent_turn(void);

#endif // MAKE_GAME_H