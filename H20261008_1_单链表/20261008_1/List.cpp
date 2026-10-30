#include "List.h"

// 创建一个新结点
LNode* BuyListNode(int data)
{
	LNode* newNode = (LNode*)malloc(sizeof(LNode));
	if (NULL == newNode)
	{
		printf("BuyListNode失败！");
		exit(-1);
	}
	newNode->data = data;
	newNode->next = NULL;
	return newNode;
}


// 初始化链表
LNode* ListInit()
{
	LNode* node = BuyListNode(-1);
	return node;
}
// 书本上的一些用法
// void ListInit(LinkList& L);
// 等价于 void ListInit(LNode*& L);


// 打印链表
void ListPrint(LNode* L)
{
	assert(L);
	printf("头结点->");
	LNode* cur = L->next;
	while (cur)
	{
		printf("%d->", cur->data);
		cur = cur->next;
	}
	printf("NULL\n");
}
// 等价的void ListPrint(LinkList L);


// 获取链表中有效元素个数
int ListSize(LNode* L)
{
	assert(L);
	int size = 0;
	LNode* cur = L->next;
	while (cur)
	{
		size++;
		cur = cur->next;
	}
	return size;
}


// 获取链表中第一个数据等于x结点的地址，若不存在返回NULL指针
LNode* ListLocateElem(LNode* L, LDataType x)
{
	assert(L);
	LNode* cur = L->next;
	while (cur)
	{
		if (cur->data == x)
		{
			return cur;
		}
		cur = cur->next;
	}

	return NULL;
}


// 返回链表中下标为i的结点
LNode* ListGetElem(LNode* L, int i)
{
	assert(L);
	assert(i >= 0);
	LNode* iNode = L->next;
	int j = 0;
	while (iNode && j < i)
	{
		iNode = iNode->next;
		j++;
	}
	return iNode;
}


// 在链表的第i个下标位置插入元素x
void ListInsert(LNode* L, int i, LDataType x)
{
	assert(L);
	assert(i >= 0);
	LNode* i_1Node = L;
	int j = -1;
	while (i_1Node && j < i - 1)
	{
		i_1Node = i_1Node->next;
		j++;
	}
	assert(i_1Node);
	LNode* newNode = BuyListNode(x);
	newNode->next = i_1Node->next;
	i_1Node->next = newNode;
}


// 删除链表中下标为i的结点，并用x带出结点的值
LDataType ListDelete(LNode* L, int i)
{
	assert(L);
	assert(i >= 0);
	LNode* i_1Node = L;
	int j = -1;
	while (i_1Node && j < i - 1)
	{
		i_1Node = i_1Node->next;
		j++;
	}
	assert(i_1Node && i_1Node->next);
	LNode* iNode = i_1Node->next;
	i_1Node->next = iNode->next;
	LDataType x = iNode->data;
	free(iNode);
	return x;
}


// 检测链表是否为空，空返回真，否则返回假
bool ListEmpty(LNode* L)
{
	assert(L);
	return L->next == NULL;
}

// 头插
void ListPushFront(LNode* L, LDataType x)
{
	assert(L);
	ListInsert(L, 0, x);  // 在下标 0 处插入
}


// 尾插
void ListPushBack(LNode* L, LDataType x)
{
	assert(L);
	ListInsert(L, ListSize(L), x);  // 在下标 size 处插入
}


// 头删
LDataType ListPopFront(LNode* L)
{
	assert(L);
	assert(L->next != NULL);  // 空链表不能删
	return ListDelete(L, 0);  // 删除下标 0 处
}


// 尾删
LDataType ListPopBack(LNode* L)
{
	assert(L);
	assert(L->next != NULL);  // 空链表不能删
	return ListDelete(L, ListSize(L) - 1);  // 删除下标 size-1 处
}


// 销毁链表
void ListDestroy(LNode* L)
{
	LNode* cur = L;
	while (cur) 
	{
		LNode* next = cur->next;
		free(cur);
		cur = next;
	}
}