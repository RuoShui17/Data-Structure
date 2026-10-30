#define _CRT_SECURE_NO_WARNINGS 1
#include <stdio.h>

//将数组A中的内容和数组B中的内容进行交换。（数组一样大）

int main()
{
	int arr1[10] = { 0 };
	int arr2[10] = { 0 };
	for (int i = 0; i < 10; i++)
	{
		scanf("%d", &arr1[i]);
	}
	for (int j = 0; j < 10; j++)
	{
		scanf("%d", &arr2[j]);
	}
	for (int a = 0; a < 10; a++)
	{
		int tmp = arr2[a];
		arr2[a] = arr1[a];
		arr1[a] = tmp;
	}
	return 0;
}