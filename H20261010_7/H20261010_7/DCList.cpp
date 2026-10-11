#include "DCList.h"
//双向循环链表
// 链表初始化
DCListNode* DCListInit()
{
	DCListNode* L = (DCListNode*)malloc(sizeof(DCListNode));
	if (L == NULL)
	{
		printf("malloc failed\n");
		exit(-1);
	}
	L->next = L;
	L->prev = L;
	return L;
}

// 销毁链表
void DCListDestroy(DCListNode* L)
{
	assert(L);
	DCListNode* cur = L->next;
	while (cur != L)
	{
		L->next = cur->next;
		free(cur);
		cur = L->next;
	}
	free(L);
}

// 打印链表中的元素
void DCListPrint(DCListNode* L)
{
	assert(L);
	printf("头结点->");
	DCListNode* cur = L->next;
	while (cur != L)
	{
		printf("%d ", cur->data);
		cur = cur->next;
	}
	printf("NULL\n");
}

// 获取链表的下标（不包括头节点）i的结点
DCListNode* DCListGetElem(DCListNode* L, int i)
{
	assert(L);
	assert(i >= 0);
	DCListNode* cur = L->next;
	int j = 0;
	while (cur != L && j < i) {
		cur = cur->next;
		++j;
	}

	assert(cur != L);//确保 cur 不是哨兵
	return cur;
}

// 在pos位置后插入值为x的结点
void DCListInsert(DCListNode* pos, DCLDataType x)
{
	assert(pos);
	DCListNode* newNode = (DCListNode*)malloc(sizeof(DCListNode));
	newNode->data = x;
	if (newNode == NULL)
	{
		printf("malloc failed\n");
		exit(-1);
	}
	newNode->next = pos->next;
	pos->next->prev = newNode;
	pos->next = newNode;
	newNode->prev = pos;
}

// 删除pos位置的结点
void DCListDelete(DCListNode* pos)
{
	assert(pos);
	pos->prev->next = pos->next;
	pos->next->prev = pos->prev;
	free(pos);
}

// 头插
void DCListPushFront(DCListNode* L, DCLDataType x)
{
	assert(L);
	DCListInsert(L, x);
}

// 尾插
void DCListPushBack(DCListNode* L, DCLDataType x)
{
	assert(L);
	DCListInsert(L->prev, x);
}

// 头删
void DCListPopFront(DCListNode* L)
{
	assert(L);
	assert(L->next != L);
	DCListDelete(L->next);
}

// 尾删
void DCListPopBack(DCListNode* L)
{
	assert(L);
	assert(L->prev != L);
	DCListDelete(L->prev);
}
