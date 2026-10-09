#define _CRT_SECURE_NO_WARNINGS 1
#include <stdio.h>
#include <stdlib.h>
//给你一个链表的头节点 head 和一个整数 val ，
//请你删除链表中所有满足 Node.val == val 的节点，并返回 新的头节点 。

struct ListNode
{
	int val;
	struct ListNode* next;
};

struct ListNode* removeElements(struct ListNode* head, int val)
{
	if (head == NULL)
	{
		return NULL;
	}

	//双指针，cur代表当前的，prev代表cur前一个
	struct ListNode* cur = head;
	struct ListNode* prev = NULL;

	while (cur)
	{
		if (cur->val == val)
		{
			struct ListNode* next = cur->next;
			if (prev == NULL)
			{
				head = cur->next;
			}
			else
			{
				prev->next = cur->next;
			}
			free(cur);
			cur = next;
		}
		else
		{
			prev = cur;
			cur = cur->next;
		}
	}
	return head;
}