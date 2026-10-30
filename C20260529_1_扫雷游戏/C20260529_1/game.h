#define _CRT_SECURE_NO_WARNINGS 1
#define ROW 9
#define COL 9
#define ROWS ROW+2
#define COLS COL+2

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void InitBoard(char board[ROWS][COLS], int r, int c, char set);
void DisplayBoard(char board[ROWS][COLS], int r, int c);
void SetMine(char board[ROWS][COLS], int r, int c);
void FindMine(char mine[ROWS][COLS], char show[ROWS][COLS], int r, int c);