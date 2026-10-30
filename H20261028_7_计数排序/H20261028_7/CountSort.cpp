#define _CRT_SECURE_NO_WARNINGS 1
#include <stdlib.h>
#include <string.h>

//计数排序是⼀种⾮⽐较型的整数排序算法
//通过统计每个元素出现的次数，直接计算出该元素在最终有序数组中的位置

//从后往前处理，是为了保持稳定性
//count[a[i] - min]记录⼩于等于a[i]的值个数，
//那么a[i]排序后的位置就是count[a[i] - min] - 1
//count[a[i] - min]--是因为当前a[i]已经放到排序后的位置了，
//前⾯⼩于等于a[i]的值就少了⼀个了，
//数组前⾯等于a[i]的值就应该存放在前⼀个位置

void CountSort(int* a, int n)
{
	int min = a[0];
	int max = a[0];

	for (int i = 1; i < n; i++)
	{
		if (a[i] < min)
		{
			min = a[i];
		}
		if (a[i] > max)
		{
			max = a[i];
		}
	}

	int range = max - min + 1;
	int* count = (int*)calloc(range, sizeof(int));

	for (int i = 0; i < n; i++)
	{
		count[a[i] - min]++;
	}

	for (int i = 1; i < range;i++)
	{
		count[i] += count[i - 1];
	}

	int* tmp = (int*)malloc(sizeof(int) * n);

	for (int i = n - 1; i >= 0; i--)
	{
		tmp[count[a[i] - min] - 1] = a[i];
		count[a[i] - min]--;
	}

	memcpy(a, tmp, sizeof(int) * n);
	free(tmp);
	free(count);
}