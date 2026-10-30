#define _CRT_SECURE_NO_WARNINGS 1
#include <stdio.h>

//输入两个链表，找出它们的第一个公共结点
//遍历两个链表找到尾结点，同时求出两个链表的⻓度尾结点相同则相交，尾结点不同则不相交。
//算出两个链表的⻓度差距，让⻓的链表先⾛差距步，两个链表再同时⾛，第⼀个相等的结点就是交点

struct ListNode {
	int val;
	struct ListNode* next;
};

struct ListNode* getIntersectionNode(struct ListNode* headA, struct ListNode* headB)
{
	struct ListNode* cur1 = headA;
	struct ListNode* cur2 = headB;

	int len1 = 1;
	int len2 = 1;

	while (cur1->next != NULL)
	{
		len1++;
		cur1 = cur1->next;
	}

	while (cur2->next != NULL)
	{
		len2++;
		cur2 = cur2->next;
	}
	if (cur1 != cur2)
	{
		return NULL;
	}

	int gap = len1 > len2 ? len1 - len2 : len2 - len1;

	struct ListNode* longest = headA;
	struct ListNode* shortest = headB;

	if (len2 > len1)
	{
		longest = headB;
		shortest = headA;
	}

	while (gap--)
	{
		longest = longest->next;
	}

	while (longest != shortest)
	{
		longest = longest->next;
		shortest = shortest->next;
	}

	return shortest;
}