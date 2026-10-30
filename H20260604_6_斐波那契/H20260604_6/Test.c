#define _CRT_SECURE_NO_WARNINGS 1
#include <stdio.h>

//递归和非递归分别实现求第n个斐波那契数

int Fib1(int n)
{
	if (n == 1 || n == 2)
	{
		return 1;
	}
	return Fib1(n - 1) + Fib1(n - 2);
}

int Fib2(int n)
{
	if (n == 1 || n == 2)
	{
		return 1;
	}
	int a = 1;
	int b = 1;
	int c = 0;
	while (n - 2)
	{
		c = a + b;
		a = b;
		b = c;
		n--;
	}
	return c;
}

int main()
{
	int a = 0;
	scanf("%d", &a);
	printf("%d\n", Fib1(a));
	printf("%d\n", Fib2(a));
	return 0;
}