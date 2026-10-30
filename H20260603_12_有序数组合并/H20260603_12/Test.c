#define _CRT_SECURE_NO_WARNINGS 1
#include <stdio.h>

//输入两个升序排列的序列，将两个序列合并为一个有序序列并输出。

int main()
{
	int arr1[1000] = { 0 };
	int arr2[1000] = { 0 };
	int a = 0;
	int b = 0;
	int i = 0;
	int j = 0;
	scanf("%d%d", &a, &b);
	for (i = 0; i < a; i++)
	{
		scanf("%d", &arr1[i]);
	}
	for (j = 0; j < b; j++)
	{
		scanf("%d", &arr2[j]);
	}
	i = 0;
	j = 0;
	while (i < a && j < b)
	{
		if (arr1[i] < arr2[j])
		{
			printf("%d ", arr1[i]);
			i++;
		}
		else
		{
			printf("%d ", arr2[j]);
			j++;
		}
		if (i == a)
		{
			for (; j < b; j++)
			{
				printf("%d ", arr2[j]);
			}
		}
		if (j == b)
		{
			for (; i < a; i++)
			{
				printf("%d ", arr1[i]);
			}
		}

	}

	return 0;
}