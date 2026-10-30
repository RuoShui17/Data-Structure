#define _CRT_SECURE_NO_WARNINGS 1
#include <stdio.h>

//将两个升序链表合并为一个新的 升序 链表并返回
//新链表是通过拼接给定的两个链表的所有节点组成的

struct ListNode {
	int val;
	struct ListNode* next;
};


struct ListNode* mergeTwoLists(struct ListNode* list1, struct ListNode* list2)
{
	struct ListNode* cur1 = list1;
	struct ListNode* cur2 = list2;

	struct ListNode* newhead = NULL;
	struct ListNode* tail = NULL;

	while (cur1 && cur2)
	{
		struct ListNode* smaller = NULL;
		if (cur1->val <= cur2->val)
		{
			smaller = cur1;
			cur1 = cur1->next;
		}
		else
		{
			smaller = cur2;
			cur2 = cur2->next;
		}
		if (newhead == NULL)
		{
			newhead = tail = smaller;
		}
		else
		{
			tail->next = smaller;
			tail = smaller;
		}

	}
	struct ListNode* rest = cur1 ? cur1 : cur2;
	if (newhead == NULL)
		return rest;
	tail->next = rest;
	return newhead;
}