#define _CRT_SECURE_NO_WARNINGS 1
#include<stdio.h>
//给你单链表的头节点 head ，请你反转链表，并返回反转后的链表
//cur遍历原链表，不断取下原链表的结点头插到新链表就可以实现反转

struct ListNode {
	int val;
	struct ListNode* next;
};

struct ListNode* reverseList(struct ListNode* head)
{
	struct ListNode* newhead = NULL;
	struct ListNode* cur = head;

	while (cur)
	{
		struct ListNode* next = cur->next;
		cur->next = newhead;
		newhead = cur;
		cur = next;
	}
	return newhead;
}