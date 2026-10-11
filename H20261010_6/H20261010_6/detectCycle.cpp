#define _CRT_SECURE_NO_WARNINGS 1
#include <stdio.h>

//给定一个链表的头节点 head,返回链表开始入环的第一个节点
//如果链表无环，则返回 null

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


struct ListNode* detectCycle1(struct ListNode* head) {
	struct ListNode* slow = head, * fast = head;
	while (fast && fast->next) {
		slow = slow->next;
		fast = fast->next->next;

		if (slow == fast) {
			struct ListNode* meet = slow;
			struct ListNode* newhead = meet->next;
			meet->next = NULL;
			struct ListNode* entry = getIntersectionNode(head, newhead);
				meet->next = newhead;
			return entry;
		}
	}
	return NULL;
}


//让⼀个指针从链表表头开始⾛，同时让另⼀个指针从判环时相遇点的位置
//开始绕环运⾏，两个指针都是每次均⾛⼀步，最终肯定会在⼊⼝点的位置相遇

struct ListNode* detectCycle2(struct ListNode* head)
{
	struct ListNode* slow = head;
	struct ListNode* fast = head;

	while (fast && fast->next)
	{
		slow = slow->next;
		fast = fast->next->next;

		if (slow == fast)
		{
			struct ListNode* p = head;
			while (p != slow)
			{
				p = p->next;
				slow = slow->next;
			}
			return p;
		}
	}
	return NULL;
}