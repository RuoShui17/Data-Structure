#define _CRT_SECURE_NO_WARNINGS 1
#include <stdio.h>

//不允许创建临时变量，交换两个整数的内容

int main()
{
	int a = 10;
	int b = 20;
	a = a ^ b;
	b = a ^ b;
	a = a ^ b;
	printf("%d\n", a);
	printf("%d\n", b);
	return 0;
}