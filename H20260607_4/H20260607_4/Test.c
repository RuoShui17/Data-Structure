#define _CRT_SECURE_NO_WARNINGS 1
#include <stdio.h>

//有一个数字矩阵，矩阵的每行从左到右是递增的，矩阵从上到下是递增的，
// 请编写程序在这样的矩阵中查找某个数字是否存在
//要求：时间复杂度小于O(N);

int findNum(int arr[][3], int x, int y, int target)
{
	int i = 0;
	int j = y - 1;
	while (i <= x - 1 && j >= 0)
	{
		if (arr[i][j] < target)
		{
			i++;
		}
		else if (arr[i][j] > target)
		{
			j--;
		}
		else {
			return 1;
		}
	}
	return 0;
}

int main()
{
	int a[][3] = { {1, 3, 5},{3, 5, 7},{5, 7, 9} };

	if (findNum(a, 3, 3, 2))
	{
		printf("It has been found!\n");
	}
	else
	{
		printf("It hasn't been found!\n");
	}

	return 0;
}