#define _CRT_SECURE_NO_WARNINGS 1
#include <stdio.h>

//计算一个数的每位之和

int DigitSum(int n)
{
	if (n <= 9)
	{
		return n;
	}
	else
	{
		return n % 10 + DigitSum(n / 10);
	}
}

int main()
{
	int a = 0;
	scanf("%d", &a);
	printf("%d", DigitSum(a));
	return 0;
}