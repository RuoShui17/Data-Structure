#define _CRT_SECURE_NO_WARNINGS 1
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

//root = [1, 2, 3, 4]
//输出： "1(2(4))(3)"
//解释： 原本需要表示为 "1(2(4)())(3()())"，但需要省略所有空括号对。因此最终得到 "1(2(4))(3)"。
//本质就是前序遍历⼆叉树，将⼆叉树结点中的值转换为字符串，追加到字符串数组中，
//最后⽣成⼀个前序的字符数组。还需要注意的是左右⼦树分别⽤()括起来。


struct TreeNode {
	struct TreeNode* left;// 指向左孩⼦的指针
	struct TreeNode* right;// 指向右孩⼦的指针
	char data;// 数据元素
};

void _tree2str(struct TreeNode* root, char* str, int* pi)
{
	if (root == NULL)
	{
		return;
	}
	char arr[10];
	sprintf(arr, "%d", root->data);
	strcpy(str + (*pi), arr);
	(*pi) += strlen(arr);

	// 左边和右边有⼀个为空，左边必须有括号
	if (root->left || root->right)
	{
		str[(*pi)++] = '(';
		_tree2str(root->left, str, pi);
		str[(*pi)++] = ')';
	}

	// 右不为空时，右边必须有括号，右边为空时括号总是省略
	if (root->right) {
		str[(*pi)++] = '(';
		_tree2str(root->right, str, pi);
		str[(*pi)++] = ')';
	}
}


char* tree2str(struct TreeNode* root)
{
	char* str = (char*)malloc(sizeof(char) * 10000);
	int i = 0;
	_tree2str(root, str, &i);
	str[i] = '\0';
	return str;
}