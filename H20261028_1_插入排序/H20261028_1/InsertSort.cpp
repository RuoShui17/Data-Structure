#define _CRT_SECURE_NO_WARNINGS 1
//单次插⼊思想:[0, end]为有序区间
//将end + 1位置的关键字插⼊到[0, end]有序区间，达到[0, end + 1]区间有序
void InsertSort(int* a, int n)
{
	for (int i = 0; i < n - 1; i++)
	{
		int end = i;
		int tmp = a[end + 1];
		while (end >= 0)
		{
			if (tmp < a[end])
			{
				a[end + 1] = a[end];
				end--;
			}
			else
			{
				break;
			}
		}
		a[end + 1] = tmp;
	}
}