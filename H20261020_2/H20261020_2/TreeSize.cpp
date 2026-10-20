#define _CRT_SECURE_NO_WARNINGS 1
#include <stdio.h>

typedef int BTDataType;

typedef struct BinaryTreeNode {
	struct BinaryTreeNode* left;
	struct BinaryTreeNode* right;
	BTDataType data;
}BTNode;

// 求二叉树的节点个数
int TreeSize(BTNode* root)
{
	//递归公式：总节点数 = 左子树节点数 + 右子树节点数 + 1（根节点自己）
	return root == NULL ? 0 : 1 + TreeSize(root->left) + TreeSize(root->right);
}

// 求二叉树的最大深度
int TreeHeight(BTNode* root)
{
	if (root == NULL)
		return 0;

	int leftHeight = TreeHeight(root->left);
	int rightHeight = TreeHeight(root->right);

	return (leftHeight > rightHeight ? leftHeight : rightHeight) + 1;
}
//在三元运算符里，TreeHeight(root->left) 会被调用 2 次
//子树被反复重复计算，如果是 50 层的树，程序会直接卡死
//用 leftHeight 和 rightHeight 提前把结果接住