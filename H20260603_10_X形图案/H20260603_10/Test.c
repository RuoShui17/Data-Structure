#define _CRT_SECURE_NO_WARNINGS 1
#include <stdio.h>

//打印用“ * ”组成的X形图案。

int main()
{
	int n = 0;
	scanf("%d", &n);
	for (int i = 1; i <= n; i++)
	{
		for (int j = 1; j <= n; j++)
		{
			if (i == j || i + j == n + 1)
			{
				printf("*");
			}
			else {
				printf(" ");
			}
		}
		printf("\n");
	}
	return 0;
}