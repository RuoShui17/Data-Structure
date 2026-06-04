#define _CRT_SECURE_NO_WARNINGS 1
#include <stdio.h>
#include <math.h>

//求出0～100000之间的所有“水仙花数”并输出

int main()
{
	for (int i = 0; i <= 100000; i++)
	{
		int tmp = i;
		int count = 0;
		int sum = 0;
		while (tmp) 
		{
			count++;
			tmp /= 10;
		}
		tmp = i;
		while (tmp)
		{
			sum += pow(tmp % 10, count);
			tmp /= 10;
		}
		if (sum == i)
		{
			printf("%d ",i);
		}
	}
	return 0;
}