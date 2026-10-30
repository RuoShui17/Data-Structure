#define _CRT_SECURE_NO_WARNINGS 1

//给你一个数组 nums 和一个值 val
//你需要 原地 移除所有数值等于 val 的元素
//元素的顺序可能发生改变,然后返回 nums 中与 val 不同的元素的数量

int removeElement(int* nums, int numsSize, int val)
{
	int src = 0;
	int dst = 0;
	while (src < numsSize)
	{
		if (nums[src] != val)
		{
			nums[dst] = nums[src];
			src++;
			dst++;
		}
		if (nums[src] == val)
		{
			src++;
		}
	}
	return dst;
}