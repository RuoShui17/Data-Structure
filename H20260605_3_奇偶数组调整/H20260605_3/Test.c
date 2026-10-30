#define _CRT_SECURE_NO_WARNINGS 1
#include <stdio.h>

//输入一个整数数组，实现一个函数，来调整该数组中数字的顺序
//使得数组中所有的奇数位于数组的前半部分，所有偶数位于数组的后半部分

void swap_arr(int arr[], int sz)
{
	int left = 0;
	int right = sz - 1;
	while (left < right)
	{
		while (left < right && arr[left] % 2 != 0)   // 奇数：继续后移
		{
			left++;
		}
		while (left < right && arr[right] % 2 == 0)  // 偶数：继续前移
		{
			right--;
		}
		if (left < right)
		{
			int tmp = arr[left];
			arr[left] = arr[right];
			arr[right] = tmp;
			left++;
			right--;
		}
	}
}

int main()
{
	int arr[] = { 1,2,3,4,5,6,7,8,9,10 };
	int sz = sizeof(arr) / sizeof(arr[0]);
	swap_arr(arr, sz);
	for (int i = 0; i < sz; i++)
	{
		printf("%d ", arr[i]);
	}
	return 0;
}
