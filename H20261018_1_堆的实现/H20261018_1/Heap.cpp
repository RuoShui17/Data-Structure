#include "Heap.h"

void Swap(int* x, int* y)
{
	int tmp = *x;
	*x = *y;
	*y = tmp;
}

//向上调整算法
void AdjustUp(HeapDataType* a, int child)
{
	assert(a);
	int parent = (child - 1) / 2;
	while (child > 0)
	{
		if (a[child] < a[parent])
		{
			Swap(&a[child], &a[parent]);
		}
		else
		{
			break;
		}
		child = parent;
		parent = (child - 1) / 2;
	}
}

//堆的插⼊
void HeapPush(Heap* hp, HeapDataType x)
{
	assert(hp);
	if (hp->size == hp->capacity)
	{
		int newCapacity = hp->capacity == 0 ? 4 : hp->capacity * 2;
		HeapDataType* tmp = (HeapDataType*)realloc(hp->a, sizeof(HeapDataType) * newCapacity);
		if (tmp == NULL)
		{
			printf("realloc fail\n");
			exit(-1);
		}
		hp->a = tmp;
		hp->capacity = newCapacity;
	}
	hp->a[hp->size] = x;
	hp->size++;
	AdjustUp(hp->a, hp->size - 1);
}


//向下调整算法
void AdjustDown(HeapDataType* a, int n, int parent)
{
	assert(a);
	int child = parent * 2 + 1;
	while (child < n)
	{
		if (child + 1 < n && a[child + 1] < a[child])
		{
			child++;
		}
		if (a[child] < a[parent])
		{
			Swap(&a[child], &a[parent]);
			parent = child;
			child = parent * 2 + 1;
		}
		else
		{
			break;
		}
	}
}

// 堆的删除，删除堆顶数据
void HeapPop(Heap* hp)
{
	assert(hp && !HeapEmpty(hp));
	Swap(&hp->a[0], &hp->a[hp->size - 1]);
	hp->size--;
	AdjustDown(hp->a, hp->size, 0);
}


//默认初始化堆
void HeapInit(Heap* hp)
{
	assert(hp);
	hp->a = NULL;
	hp->capacity = hp->size = 0;
}

//堆的销毁
void HeapDestroy(Heap* hp)
{
	assert(hp);
	free(hp->a);
	hp->capacity = hp->size = 0;
}

//利⽤给定数组初始化建堆
void HeapInitArray(Heap* hp, HeapDataType* a, int n)
{
	assert(hp != NULL && a != NULL);
	hp->a = (HeapDataType*)malloc(sizeof(HeapDataType) * n);
	if (hp->a == NULL) {
		printf("malloc fail\n");
		exit(-1);
	}
	hp->size = n;
	hp->capacity = n;

	memcpy(hp->a, a, sizeof(HeapDataType) * n);

	int i;
	for (i = (hp->size - 1 - 1) / 2; i >= 0; --i) {
		AdjustDown(hp->a, n, i);
	}
}


// 获取堆顶数据
HeapDataType HeapTop(Heap* hp)
{
	assert(hp);
	assert(!HeapEmpty(hp));
	return hp->a[0];
}

// 堆的数据个数
int HeapSize(Heap* hp)
{
	assert(hp);
	return hp->size;
}

// 堆的判空
bool HeapEmpty(Heap* hp)
{
	assert(hp);
	return hp->size == 0;
}
