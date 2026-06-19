#define _CRT_SECURE_NO_WARNINGS 1
#include <stdio.h>
#include <stdlib.h>

//给你一个长度为n的整数数组nums
//请你构建一个长度为2n的答案数组ans数组下标 
//从0开始计数，对于所有0<=i<n的i满足下述所有要求：
//ans[i] == nums[i]
//ans[i + n] == nums[i]
//具体而言，ans由两个nums数组串联形成。返回数组ans。

int* getConcatenation(int* nums, int numsSize, int* returnSize)
{
	int* ans = (int*)malloc(numsSize * sizeof(int) * 2);
	for (int i = 0; i < numsSize; i++)
	{
		ans[i] = nums[i];
		ans[i + numsSize] = nums[i];
	}
	*returnSize = 2 * numsSize;
	return ans;
}