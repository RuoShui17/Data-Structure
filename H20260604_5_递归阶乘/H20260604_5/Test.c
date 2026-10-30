#define _CRT_SECURE_NO_WARNINGS 1
#include <stdio.h>

//µÝ¹é µü´úÇónµÄ½×³Ë

int Func1(int n)
{
	if (n == 1)
	{
		return 1;
	}
	return n * Func1(n - 1);
}

int Func2(int n)
{
	int ret = 1;
	for (int i = 2; i <= n; i++)
	{
		ret *= i;
	}
	return ret;
}

int main()
{
	int a = 0;
	scanf("%d", &a);
	printf("%d\n", Func1(a));
	printf("%d\n", Func2(a));
	return 0;
}