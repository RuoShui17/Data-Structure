#define _CRT_SECURE_NO_WARNINGS 1
#include <stdio.h>

//希尔排序的本质是先通过预排序(d>1)让待排序序列接近有序
//最后再通过直接插⼊排序(d == 1)快速让序列有序

void ShellSort(int* a, int n)
{
	int d = n;
	while (d > 1)
	{
		d = d / 3 + 1;
		for (int i = 0; i < n - d; i++)
		{
			int end = i;
			int tmp = a[end + d];
			while (end >= 0)
			{
				if (tmp < a[end])
				{
					a[end + d] = a[end];
					end -= d;
				}
				else
				{
					break;
				}
			}
			a[end + d] = tmp;
		}
	}
}

void PrintArray(int* a, int n)
{
	for (int i = 0; i < n; i++)
	{
		printf("%d ", a[i]);
	}
	printf("\n");
}

void TestShellSort()
{
	int a[] = { 9,1,2,5,7,4,6,3,5 };
	PrintArray(a, sizeof(a) / sizeof(int));
	ShellSort(a, sizeof(a) / sizeof(int));
	PrintArray(a, sizeof(a) / sizeof(int));
}

int main()
{
	TestShellSort();
}