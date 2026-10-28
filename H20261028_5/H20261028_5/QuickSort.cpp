#define _CRT_SECURE_NO_WARNINGS 1

//快速排序是基于分治思想。它是在待排序区间中任取⼀个元素作为pivot
//然后按照基准值⼤⼩将区间中元素分割成左右两部分，左侧区间中元素⼩于等于基准值
//右侧区间中元素⼤于等于基准值(升序是这样，降序就是反过来)
//即基准值已经放在最终该放的位置上，该过程称为⼀次单趟划分
//划分结束后再对基准值左右两段⼦区间重复执⾏上述过程的过程，直到⼦区间只有⼀个值或者不存在

int Partition(int* a, int low, int high)
{
	int pivot = a[low];
	while (high > low)
	{
		while (high > low && a[high] >= pivot)
		{
			high--;
		}
		a[low] = a[high];
		while (high > low && a[low] <= pivot)
		{
			low++;
		}
		a[high] = a[low];

	}
	a[low] = pivot;
	return low;
}

void QuickSort(int* a, int left, int right)
{
	if (left >= right)
	{
		return;
	}
	int pivot = Partition(a, left, right);
	QuickSort(a, left, pivot - 1);
	QuickSort(a, pivot + 1, right);
}