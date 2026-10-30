#define _CRT_SECURE_NO_WARNINGS 1
#include "SqList.h"

// 初始化顺序表
void SqListInit(SqList* ps)
{
	assert(ps);
	ps->arr = (SqDataType*)malloc(sizeof(SqDataType) * 4);
	if (ps->arr == NULL)
	{
		printf("InitSqList:申请空间失败!\n");
		return;
	}
	ps->size = 0;
	ps->capacity = 4;
}


// 销毁顺序表
void SqListDestroy(SqList* ps)
{
	assert(ps);
	if (ps->arr)
	{
		free(ps->arr);
		ps->size = 0;
		ps->capacity = 0;
		ps->arr = NULL;
	}
}


// 返回顺序表中第i个下标位置元素的值
SqDataType GetElem(SqList* ps, int i)
{
	assert(ps);
	assert(i >= 0 && i < ps->size);
	return ps->arr[i];
}


// 返回第一个等于x的数据元素的下标，若不存在返回-1
int LocateElem(SqList* ps, SqDataType x)
{
	assert(ps);
	for (int i = 0; i < ps->size; i++)
	{
		if (x == ps->arr[i])
		{
			return i;
		}
	}
	return -1;
}


// 书本i通常是位序，位序是从1开始
// 我们实现的时候，i用的是下标
// 在顺序表下标为i的位置插入元素x
void SqListInsert(SqList* ps, int i, SqDataType x)
{
	assert(ps);
	assert(i >= 0 && i <= ps->size);
	if (ps->size == ps->capacity)
	{
		SqDataType* tmp = (SqDataType*)realloc(ps->arr, sizeof(SqDataType) * (ps->capacity * 2));
		if (tmp == NULL)
		{
			printf("SqListInsert: 扩容失败!\n");
			return;
		}
		ps->arr = tmp;
		ps->capacity *= 2;
	}
	for (int j = ps->size - 1; j >= i; j--)
	{
		ps->arr[j + 1] = ps->arr[j];
	}
	ps->arr[i] = x;
	ps->size++;
}


// 删除顺序表中下标为 i 的元素，并返回删除的值
SqDataType SqListDelete(SqList* ps, int i)
{
	assert(ps);
	assert(i >= 0 && i < ps->size);
	SqDataType x = ps->arr[i];
	for (int j = i + 1; j < ps->size; j++)
	{
		ps->arr[j - 1] = ps->arr[j];
	}
	ps->size--;
	return x;
}


// 打印顺序表中的元素
void SqListPrint(SqList* ps)
{
	assert(ps);
	for (int i = 0; i < ps->size; i++)
	{
		printf("%d ", ps->arr[i]);
	}
	printf("\n");
}


// 检测顺序表是否为空，空返回 true，否则返回 false
bool EmptySqList(SqList* ps)
{
	assert(ps);
	return ps->size == 0;
}


// 获取顺序表中有效元素个数
int SqListSize(SqList* ps)
{
	assert(ps);
	return ps->size;
}


// 尾插：在顺序表末尾插入元素
void SqListPushBack(SqList* ps, SqDataType x)
{
	assert(ps);
	SqListInsert(ps, ps->size, x);  // 在下标 size 处插入
}


// 头插：在顺序表开头插入元素
void SqListPushFront(SqList* ps, SqDataType x)
{
	assert(ps);
	SqListInsert(ps, 0, x);  // 在下标 0 处插入
}


// 尾删：删除顺序表末尾元素
void SqListPopBack(SqList* ps)
{
	assert(ps);
	assert(ps->size > 0);  // 空表不能删
	SqListDelete(ps, ps->size - 1);  // 删除下标 size-1 处
}


// 头删：删除顺序表开头元素
void SqListPopFront(SqList* ps)
{
	assert(ps);
	assert(ps->size > 0);  // 空表不能删
	SqListDelete(ps, 0);   // 删除下标 0 处
}