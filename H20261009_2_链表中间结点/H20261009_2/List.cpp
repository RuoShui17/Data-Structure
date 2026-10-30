#define _CRT_SECURE_NO_WARNINGS 1
//使⽤⼀个快指针fast，⼀个慢指针slow，均指向第⼀个有效结点，
//slow⼀次⾛⼀步，fast⼀次⾛两步，当fast⾛到尾时，slow就⾛到中间结点了

struct ListNode {
	int val;
	struct ListNode* next;
};


struct ListNode* middleNode(struct ListNode* head)
{
	struct ListNode* slow = head;
	struct ListNode* fast = head;
	while (fast && fast->next)
	{
		slow = slow->next;
		fast = fast->next->next;
	}
	return slow;