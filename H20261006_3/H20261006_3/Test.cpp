#define _CRT_SECURE_NO_WARNINGS 1

//给你一个非严格递增排列的数组 nums ，请你 原地 删除重复出现的元素
//使每个元素只出现一次 ，返回删除后数组的新长度
//元素的 相对顺序 应该保持 一致 。然后返回 nums 中唯一元素的个数
//考虑 nums 的唯一元素的数量为 k。去重后，返回唯一元素的数量 k
//nums 的前 k 个元素应包含 排序后 的唯一数字。下标 k - 1 之后的剩余元素可以忽略

int removeDuplicates(int* nums, int numsSize)
{
	int src = 0;
	int dst = 1;
	while (dst < numsSize)
	{
		if (nums[src] == nums[dst])
		{
			dst++;
		}
		else
		{
			src++;
			nums[src] = nums[dst];
			dst++;
		}
	}
	return src + 1;
}