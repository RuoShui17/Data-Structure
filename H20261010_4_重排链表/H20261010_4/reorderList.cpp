#define _CRT_SECURE_NO_WARNINGS 1
#include <stdio.h>

//给定一个单链表 L 的头节点 head ，单链表 L 表示为：
//L0 → L1 → … → Ln - 1 → Ln
//请将其重新排列后变为：
//L0 → Ln → L1 → Ln - 1 → L2 → Ln - 2 → …
//不能只是单纯的改变节点内部的值，而是需要实际的进行节点交换
//第⼀步找到中间结点,反转后半段链表,把后半段链表的结点依次插⼊到前半段链表中

struct ListNode {
	int val;
	struct ListNode* next;
};


void reorderList(struct ListNode* head)
{
	struct ListNode* slow = head;
	struct ListNode* fast = head;

	while (fast && fast->next)
	{
		slow = slow->next;
		fast = fast->next->next;
	}

	struct ListNode* cur =  slow->next;
	slow->next = NULL;

	struct ListNode* newhead = NULL;
	while (cur)
	{
		struct ListNode* next = cur->next;
		cur->next = newhead;
		newhead = cur;
		cur = next;
	}

	struct ListNode* cur1 = head;
	struct ListNode* cur2 = newhead;

	while (cur2)
	{
		struct ListNode* next1 = cur1->next;
		struct ListNode* next2 = cur2->next;
		cur1->next = cur2;
		cur2->next = next1;
		cur1 = next1;
		cur2 = next2;
	}
