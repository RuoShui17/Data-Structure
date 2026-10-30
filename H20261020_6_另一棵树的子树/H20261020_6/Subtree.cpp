#define _CRT_SECURE_NO_WARNINGS 1
#include <stdio.h>
#include <stdbool.h>

//本题⽬为前⼀个相同的树问题再加码变形，若a树是b树的⼦树，则a树根b树的某个结点为根的⼦树是相同的树，
//则我们遍历b树的每个结点就拿到了b树的每棵⼦树的根，再调⽤前⾯相同的树isSameTree的函数去判断即可，
//若a树和b树某个结点为根的⼦树相同，则a树是b树的⼦树。

struct TreeNode {
	struct TreeNode* left;// 指向左孩⼦的指针
	struct TreeNode* right;// 指向右孩⼦的指针
	int data;// 数据元素
};

bool isSameTree(struct TreeNode* p, struct TreeNode* q)
{
	if (p == NULL && q == NULL)
	{
		return true;
	}
	if (p == NULL || q == NULL)
	{
		return false;
	}
	if (p->data != q->data)
	{
		return false;
	}
	return isSameTree(p->left, q->left) && isSameTree(p->right, q->right);
}

bool isSubtree(struct TreeNode* root, struct TreeNode* subRoot)
{
	if (root == NULL)
	{
		return false;
	}
	if (isSameTree(root, subRoot))
	{
		return true;
	}
	return isSubtree(root->left, subRoot) || isSubtree(root->right, subRoot);
}
