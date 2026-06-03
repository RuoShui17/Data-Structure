#define _CRT_SECURE_NO_WARNINGS 1
#include "game.h"

static int GetMineCount(char mine[ROWS][COLS], int x, int y) {
	return mine[x - 1][y - 1] + mine[x - 1][y] + mine[x - 1][y + 1] + mine[x][y - 1]
		+ mine[x][y + 1] + mine[x + 1][y - 1] + mine[x + 1][y] + mine[x + 1][y + 1] - 8 * '0';
}

void InitBoard(char board[ROWS][COLS], int r, int c, char set) {
	for (int i = 0; i < ROWS; i++) {
		for (int j = 0; j < COLS; j++) {
			board[i][j] = set;
		}
	}
}

void DisplayBoard(char board[ROWS][COLS], int r, int c) {
	for (int j = 0; j <= 9; j++) {
		printf("%d ", j);
	}
	printf("\n");
	for (int i = 1; i <= r; i++) {
		printf("%d ", i);
		for (int j = 1; j <= c; j++) {
			printf("%c ", board[i][j]);
		}
		printf("\n");
	}
	printf("\n");
}

void SetMine(char board[ROWS][COLS], int r, int c) {
	int count = 10;
	while (count) {
		int x = rand() % r + 1;
		int y = rand() % c + 1;
		if (board[x][y] == '0') {
			board[x][y] = '1';
			count--;
		}
	}
}

void FindMine(char mine[ROWS][COLS], char show[ROWS][COLS], int r, int c) {
	int x = 0;
	int y = 0;
	int win = 0;
	while (win < r * c - 10) {
		printf("请输入要排查的坐标：\n");
		scanf("%d%d", &x, &y);
		if (x >= 1 && x <= r && y >= 1 && y <= c) {
			if (show[x][y] == '*') {
				if (mine[x][y] == '1') {
					printf("很遗憾你被炸死了\n");
					DisplayBoard(mine, ROW, COL);
					break;
				}
				else {
					int count = GetMineCount(mine, x, y);
					show[x][y] = count + '0';
					DisplayBoard(show, ROW, COL);
					win++;
				}
			}
			else {
				printf("该坐标已被排查过，无需重复排查\n");
			}
		}
		else {
			printf("输入的坐标非法，请重新输入\n");
		}
	}
	if (win == r * c - 10) {
		printf("恭喜你排雷成功！\n");
		DisplayBoard(mine, ROW, COL);
	}
}

