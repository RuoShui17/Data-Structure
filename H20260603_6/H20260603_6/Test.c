#define _CRT_SECURE_NO_WARNINGS 1
#include <stdio.h>
#include <stdbool.h>

//写一个代码：打印100~200之间的素数

int main()
{
	
	for (int i = 100; i <= 200; i++)
	{
		_Bool a = true;
		for (int j = 2; j < i; j++)
		{
			if (i % j == 0)
			{
				a = false;
				break;
			}
		}
		if(a)
		{
			printf("%d ", i);
		}
	}
	
}