#define _CRT_SECURE_NO_WARNINGS 1
#include <stdio.h>
#include <stdlib.h>

//使⽤qsort函数排序整型数据

int int_cmp(const void* p1, const void* p2)//系统规定必须是void*类型
{
	return (*(int*)(p1)-*(int*)(p2));//强转成int*类型，解引用，相减
}

int main()
{
	int arr[] = { 1, 3, 5, 7, 9, 2, 4, 6, 8, 0 };
	qsort(arr, sizeof(arr) / sizeof(arr[0]), sizeof(int), int_cmp);
	for (int i = 0; i < sizeof(arr) / sizeof(arr[0]); i++)
	{
		printf("%d ", arr[i]);
	}
	return 0;
}