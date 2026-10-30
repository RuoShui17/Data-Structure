#define _CRT_SECURE_NO_WARNINGS 1
#include <stdio.h>
#include <stdlib.h>

//使用malloc函数模拟开辟一个3 * 5的整型二维数组，
//开辟好后，使用二维数组的下标访问形式，访问空间。

int main()
{
	int** p = (int**)malloc(3 * sizeof(int*));
	for (int i = 0; i < 3; i++)
	{
		*(p + i) = (int*)malloc(5 * sizeof(int));
	}
	for (int i = 0; i < 3; i++)
	{
		for (int j = 0; j < 5; j++)
		{
			*(*(p + i) + j) = 5 * i + j;
		}
	}
	for (int i = 0; i < 3; i++)
	{
		for (int j = 0; j < 5; j++)
		{
			printf("%d ", *(*(p + i) + j));
		}
		printf("\n");
	}
	for (int i = 0; i < 3; i++)
	{
		free(*(p + i));
	}
	free(p);
	return 0;
}