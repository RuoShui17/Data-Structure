#define _CRT_SECURE_NO_WARNINGS 1
#include <stdio.h>
#include <stdlib.h>

struct TreeNode
{
	int val;
	struct TreeNode* left;
	struct TreeNode* right;
};

/*
 * 核心递归函数：_buildTree
 * 【核心思想：前序抓根，中序切块】
 * - preorder: 前序遍历数组 (提供根节点)
 * - pi:       永远只往后走，用来指向当前要拿的根节点
 * - inorder:  中序遍历数组 (提供左右子树的边界)
 * - inbegin:  当前这棵子树在中序数组中的左边界
 * - inend:    当前这棵子树在中序数组中的右边界
 */

struct TreeNode* _buildTree(int* preorder, int* pi, int* inorder, int inbegin, int inend)
{
	// 1. 递归的终止条件（没有节点可建了）
	// 如果左边界跑到了右边界的右边，说明这个区间被切没了，返回空。
	if (inbegin > inend)
	{
		return NULL;
	}

	// 2. 建立当前子树的根节点
	struct TreeNode* root = (struct TreeNode*)malloc(sizeof(struct TreeNode));
	root->val = preorder[(*pi)++];

	// 3. 在中序数组中寻找当前根节点的位置（为切分左右子树做准备）
	int rooti;
	for (rooti = inbegin; rooti <= inend; ++rooti)
	{
		if (inorder[rooti] == root->val)
			break; // 找到了，跳出循环，此时 rooti 就是根节点在中序数组里的下标
	}

	// 4. 递归构建左子树和右子树
	// 因为中序数组里，rooti 左边的都在左子树，右边的都在右子树。

	// 构建左子树：中序范围是 [inbegin, rooti - 1]。
	// 注意：这里把 pi 直接传进去，因为处理完左边，机械臂自动就会停在右子树的根上。
	root->left = _buildTree(preorder, pi, inorder, inbegin, rooti - 1);

	// 构建右子树：中序范围是 [rooti + 1, inend]。
	root->right = _buildTree(preorder, pi, inorder, rooti + 1, inend);

	// 5. 左右都建好了，把当前的根节点返回给上一层
	return root;
}

struct TreeNode* buildTree(int* preorder, int preorderSize, int* inorder, int inorderSize)
{
	int i = 0;

	// 传入地址 &i，以及中序数组的初始区间 [0, inorderSize - 1]
	return _buildTree(preorder, &i, inorder, 0, inorderSize - 1);
}