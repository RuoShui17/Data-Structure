#define _CRT_SECURE_NO_WARNINGS 1
#include <stdio.h>

//在一个整型数组中，只有一个数字出现一次，其他数组都是成对出现的，请找出那个只出现一次的数字

int findSingleDog(int arr[], int sz)
{
	int ret = 0;
	for (int i = 0; i < sz; i++)
	{
		ret ^= arr[i];
	}
	return ret;
}
int main()
{
	int arr[] = { 1,2,3,4,5,1,2,3,4 };
	int sz = sizeof(arr) / sizeof(arr[0]);
	int dog = findSingleDog(arr, sz);
	printf("%d\n", dog);

	return 0;
}