#define _CRT_SECURE_NO_WARNINGS 1
#include <stdio.h>
#include <stdlib.h>

//层序遍历，借助一个队列来实现，大思路是当前层结点依次入队列，
//当前层结点出队列时，带下一层结点入队列。
//a.将二叉树根结点入队列
//b.队列不为空，出队头结点frontNode，并将frontNode的下一层(不为空的孩子)入队列
//c.循环重复b，直至队列为空，则遍历结束

typedef struct TreeNode {
	int data;
	struct TreeNode* left;
	struct TreeNode* right;
} BTNode;

void Levelorder(BTNode* root)
{
	BTNode* queueArr[100];
	int front = 0;
	int rear = 0;
	if (root)
	{
		queueArr[rear++] = root;
	}
	while (front != rear)
	{
		BTNode* frontNode = queueArr[front++];
		printf("%d ", frontNode->data);

		if (frontNode->left)
		{
			queueArr[rear++] = frontNode->left;
		}

		if (frontNode->right)
		{
			queueArr[rear++] = frontNode->right;
		}
	}
}