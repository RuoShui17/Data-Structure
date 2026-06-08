#define _CRT_SECURE_NO_WARNINGS 1
#include <stdio.h>

//一个数组中只有两个数字是出现一次，其他所有数字都出现了两次。
//编写一个函数找出这两个只出现一次的数字。

void findTwoNum(int arr[], int len, int* pnum1, int* pnum2)
{
	int tmp = 0;
	for (int i = 0; i < len; i++)
	{
		tmp ^= arr[i];
	}

	int pos = 0;
	for (int i = 0; i < 32; i++)
	{
		if ((tmp >> i) & 1)
		{
			pos = i;
			break;
		}
	}

	for (int i = 0; i < len; i++)
	{
		if (arr[i] >> pos & 1 == 1)
		{
			*pnum1 ^= arr[i];
		}
		else
		{
			*pnum2 ^= arr[i];
		}
	}
}

int main()
{
	int arr[] = { 1,2,3,4,5,1,2,3,4,6 };
	int a = 0;
	int b = 0;
	int len = sizeof(arr) / sizeof(arr[0]);
	findTwoNum(arr, len, &a, &b);
	printf("%d %d", a, b);
	return 0;
}