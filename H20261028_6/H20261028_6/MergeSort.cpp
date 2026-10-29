#define _CRT_SECURE_NO_WARNINGS 1
#include <stdlib.h>

//归并的含义是将两个或两个以上的有序表合并成⼀个新的有序表
//链表归并可以直接取结点下来归并，数组归并则必须结束⼀个额外的数组空间归并，归并后再拷⻉回去

void _MergeSort(int* a, int* tmp, int begin, int end)
{
	if (begin >= end) return;

	//递归划分[begin, mid][mid + 1, end]
	int mid = (begin + end) / 2;
	_MergeSort(a, tmp, begin, mid);
	_MergeSort(a, tmp, mid + 1, end);

	int begin1 = begin, end1 = mid;
	int begin2 = mid + 1, end2 = end;
	int i = begin;

	while (begin1 <= end1 && begin2 <= end2)
	{
		if (a[begin1] <= a[begin2])//保证稳定性

		{
			tmp[i++] = a[begin1++];
		}
		else
		{
			tmp[i++] = a[begin2++];
		}
	}
	while (begin1 <= end1)
	{
		tmp[i++] = a[begin1++];
	}
	while (begin2 <= end2)
	{
		tmp[i++] = a[begin2++];
	}

	//归并到tmp区间的值拷⻉回a原数组
	while (begin <= end)
	{
		a[begin] = tmp[begin];
		begin++;
	}

}
void MergeSort(int* a, int n)
{
	int* tmp = (int*)malloc(sizeof(int) * n);
	if (tmp == NULL)
	{
		perror("malloc fail");
		return;
	}
	_MergeSort(a, tmp, 0, n - 1);
	free(tmp);
	tmp = NULL;
}