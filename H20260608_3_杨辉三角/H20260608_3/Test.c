#define _CRT_SECURE_NO_WARNINGS 1
#include <stdio.h>

//在屏幕上打印杨辉三角。
//1
//1 1
//1 2 1
//1 3 3 1

void yangHuiTriangle(int n)
{
	int data[30][30] = { 1 };
	for (int i = 1; i < n; i++)
	{
		data[i][0] = 1;
		for (int j = 1; j <= i; j++)
		{
			data[i][j] = data[i - 1][j - 1] + data[i - 1][j];
		}
	}

	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j <= i; j++)
		{
			printf("%d ", data[i][j]);
		}
		printf("\n");
	}
}

int main()
{
	yangHuiTriangle(5);
	return 0;
}