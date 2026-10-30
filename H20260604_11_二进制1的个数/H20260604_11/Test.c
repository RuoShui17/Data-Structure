#define _CRT_SECURE_NO_WARNINGS 1
#include <stdio.h>

//统计二进制中1的个数

int numberofone1(unsigned int n)
{
	int count = 0;
	for (int i = 0; i < 32; i++)
	{
		if ((n >> i & 1) == 1)
		{
			count++;
		}
	}
	return count;
}

int numberofone2(int n)
{
	int count = 0;
	while (n)
	{
		n = n & (n - 1);
		count++;
	}
	return count;
}

int main()
{
	int a = 0;
	scanf("%d", &a);
	printf("%d\n", numberofone1(a));
	printf("%d\n", numberofone2(a));
	return 0;
}