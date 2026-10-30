#define _CRT_SECURE_NO_WARNINGS 1
//简单选择排序：每次从剩下的队伍里挑出最小的那个，放到最前面

void SelectSort(int* a, int n)
{
	for (int i = 0; i < n; i++)
	{
		int min = i;
		for (int j = i + 1; j < n; j++)
		{
			if (a[j] < a[min])
			{
				min = j;
			}
		}
		if (i != min)
			// 如果最小值就是自己，就不需要交换了
		{
			int tmp = a[i];
			a[i] = a[min];
			a[min] = tmp;
		}
	}
}