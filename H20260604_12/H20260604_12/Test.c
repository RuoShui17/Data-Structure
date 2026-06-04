#define _CRT_SECURE_NO_WARNINGS 1
#include <stdio.h>

//获取一个整数二进制序列中所有的偶数位和奇数位，分别打印出二进制序列

void printBit(int n)
{
	for (int i = 31; i >= 1; i -= 2)
	{
		printf("%d ", (n >> i) & 1);
	}
	printf("\n");
	for (int i = 30; i >= 0; i -= 2)
	{
		printf("%d ", (n >> i) & 1);
	}
}

int main()
{
	int a = 0;
	scanf("%d", &a);
	printBit(a);
	return 0;
}