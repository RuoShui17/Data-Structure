#define _CRT_SECURE_NO_WARNINGS 1
#include <stdio.h>
#include <time.h>
#include <stdlib.h>

//猜数字游戏

void menu() {
	printf("----------------\n");
	printf("---  1.play  ---\n");
	printf("----------------\n");
	printf("---  0.exit  ---\n");
	printf("----------------\n");
}

void game() {
	int ret = rand() % 100 + 1;
	int num = 0;
	int count = 10;
	while (count) {
		printf("请猜测数字：\n");
		scanf("%d", &num);
		if (num == ret) {
			printf("恭喜你猜中了\n");
			break;
		}
		else if (num < ret) {
			printf("猜小了\n");
			count--;
			printf("你还有%d次机会！\n",count);
		}
		else {
			printf("猜大了\n");
			count--;
			printf("你还有%d次机会！\n",count);
		}
		if (count == 0) {
			printf("很遗憾你失败了\n");
			break;
		}
	}
}

int main() {
	int input = 0;
	do {
		srand((unsigned int)time(NULL));
		menu();
		printf("请选择：\n");
		scanf("%d", &input);
		switch (input) {
		case 1:
			game();
			break;
		case 0:
			printf("退出游戏\n");
			break;
		default:
			printf("选择错误，请重新选择\n");
			break;
		}


	} while (input);
}