#define _CRT_SECURE_NO_WARNINGS 1
#include <stdio.h>
#include <stdlib.h>

//编一个程序，读入用户输入的一串先序遍历字符串，根据此字符串建立一个二叉树（以指针方式存储）
//例如如下的先序遍历字符串： ABC##DE#G##F### 其中“#”表示的是空格，空格字符代表空树
//建立起此二叉树以后，再对二叉树进行中序遍历，输出遍历结果

typedef struct treeNode {
    struct treeNode* left;
    struct treeNode* right;
    char val;
} Node;

Node* bulidTree(char* arr, int* pi) {
    if (arr[*pi] == '#') {
        (*pi)++;
        return NULL;
    }
    Node* node = (Node*)malloc(sizeof(Node));
    node->val = arr[*(pi)];
    (*pi)++;

    node->left = bulidTree(arr, pi);
    node->right = bulidTree(arr, pi);
    return node;
}

void Inorder(Node* root) {
    if (root == NULL) {
        return;
    }
    Inorder(root->left);
    printf("%c ", root->val);
    Inorder(root->right);

}

int main() {
    char arr[100];
    scanf("%s", arr);
    int i = 0;
    Node* node = bulidTree(arr, &i);
    Inorder(node);
}