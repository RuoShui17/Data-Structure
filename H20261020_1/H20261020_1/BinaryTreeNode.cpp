#define _CRT_SECURE_NO_WARNINGS 1
#include<stdio.h> 
#include<stdlib.h> 

typedef char BTDataType;

typedef struct BinaryTreeNode {
	struct BinaryTreeNode* left;// 指向左孩⼦的指针
	struct BinaryTreeNode* right;// 指向右孩⼦的指针
	BTDataType data;// 数据元素
}BTNode;


BTNode* BuyBTNode(int val)
{
	BTNode* newnode = (BTNode*)malloc(sizeof(BTNode));
	if (newnode == NULL)
	{
		perror("malloc fail");
		return NULL;
	}
	newnode->data = val;
	newnode->left = NULL;
	newnode->right = NULL;
	return newnode;
}


// k⼿动构造⼀棵⼆叉树
BTNode* CreateTree()
{
	BTNode* nodea = BuyBTNode('a');
	BTNode* nodeb = BuyBTNode('b');
	BTNode* nodec = BuyBTNode('c');
	BTNode* noded = BuyBTNode('d');
	BTNode* nodee = BuyBTNode('e');
	BTNode* nodef = BuyBTNode('f');
	nodea->left = nodeb;
	nodea->right = nodec;
	nodeb->left = noded;
	nodeb->right = nodee;
	nodec->right = nodef;
	return nodea;
}


void Preorder(BTNode* root)
{
	if (root == NULL)
	{
		printf("N ");
		return;
	}
	printf("%c ", root->data);
	Preorder(root->left);
	Preorder(root->right);
}

void Inorder(BTNode* root)
{
	if (root == NULL)
	{
		printf("N ");
		return;
	}
	Inorder(root->left);
	printf("%c ", root->data);
	Inorder(root->right);
}

void Postorder(BTNode* root)
{
	if (root == NULL)
	{
		printf("N ");
		return;
	}
	Postorder(root->left);
	Postorder(root->right);
	printf("%c ", root->data);
}


int main() {
	BTNode* root = CreateTree();
	Preorder(root);
	printf("\n");
	Inorder(root);
	printf("\n");
	Postorder(root);
	printf("\n");
	return 0;
}