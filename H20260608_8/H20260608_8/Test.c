#define _CRT_SECURE_NO_WARNINGS 1
#include <stdio.h>

//使⽤回调函数，模拟实现qsort（采⽤冒泡的⽅式）

void Swap(char* buf1, char* buf2, size_t width)
{
	for (int i = 0; i < width; i++)
	{
		char tmp = *buf1;
		*buf1 = *buf2;
		*buf2 = tmp;
		buf1++;
		buf2++;
	}
}

int cmp_int(const void* p1, const void* p2)
{
	return (*(int*)p1) - (*(int*)p2);
}


void bubbleSort(void* base, size_t len, size_t width, int (*cmp)(const void* p1, const void* p2))
{
	for (int i = 0; i < len - 1; i++)
	{
		for (int j = 0; j < len - 1 - i; j++)
		{
			if (cmp((char*)base + j * width, (char*)base + (j + 1) * width) > 0)
			{
				Swap((char*)base + j * width, (char*)base + (j + 1) * width, width);
			}
		}
	}
}


int main()
{
	int arr[] = { 1, 3, 5, 7, 9, 2, 4, 6, 8, 0 };
	int len = sizeof(arr) / sizeof(arr[0]);
	int width = sizeof(arr[0]);
	bubbleSort(arr, len, width, cmp_int);
	for (int i = 0; i < len; i++)
	{
		printf("%d ", arr[i]);
	}
	return 0;
}