#define _CRT_SECURE_NO_WARNINGS 1
#include <stdio.h>

//使用函数指针数组实现转移表

int Add(int x, int y)
{
	return x + y;
}

int Sub(int x, int y)
{
	return x - y;
}

int Mul(int x, int y)
{
	return x * y;
}

int Div(int x, int y)
{
	return x / y;
}

void menu()
{
	printf("------------------\n");
	printf("--1.Add---2.Sub---\n");
	printf("------------------\n");
	printf("--3.Mul---4.Div---\n");
	printf("------------------\n");
	printf("--0.exit----------\n");
	printf("------------------\n");
}

int main()
{
	int input = 0;
	int x = 0;
	int y = 0;
	int (*parr[])(int, int) = { NULL, Add,Sub,Mul,Div };
	int r = 0;
	do
	{
		menu();
		printf("请选择：\n");
		scanf("%d", &input);
		if (input >= 1 && input <= 4)
		{
			printf("请输入操作数：\n");
			scanf("%d%d", &x, &y);
			int r = parr[input](x, y);
			printf("结果是：%d\n", r);
		}
		else if (input == 0)
		{
			printf("退出程序\n");
		}
		else
		{
			printf("选择错误，请重新选择\n");
		}
	} while (input);
}