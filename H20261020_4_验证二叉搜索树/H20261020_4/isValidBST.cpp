#define _CRT_SECURE_NO_WARNINGS 1
#include <stdio.h>
#include <stdbool.h>

//⼆叉搜索树也叫⼆叉排序树，也就意味着中序遍历⼆叉搜索树，
// 结点出现的顺序是有序的，我们只需要跟上⼀个结点的值⽐较，
// 如果上⼀个结点的值 >= 当前结点的值，则说明不是搜索⼆叉树

struct TreeNode* prev = NULL;

struct TreeNode {
	struct TreeNode* left;// 指向左孩⼦的指针
	struct TreeNode* right;// 指向右孩⼦的指针
	int data;// 数据元素
};

bool _isValidBST(struct TreeNode* root)
{
	if (root == NULL)
	{
		return true;
	}
	if (_isValidBST(root->left) == false)
	{
		return false;
	}
	if (prev != NULL && prev->data >= root->data)
	{
		return false;
	}
	prev = root;
	if (_isValidBST(root->right) == false)
	{
		return false;
	}
	return true;
}

bool isValidBST(struct TreeNode* root)
{
	prev = NULL;
	return _isValidBST(root);
}
